# C++ Module 03 — Inheritance

This module builds one family of classes — the *ClapTrap* robots — one inheritance step at a time. It starts from a single standalone class, adds a derived class, then a second derived class, and finally makes one class inherit from **both** of them at once, which forces the diamond problem and its fix, virtual inheritance.

Each `exNN/` directory is a **self-contained, independently-compiled** exercise with its own `Makefile`. There is no top-level Makefile — build each exercise from inside its own directory.

## The ClapTrap family

Every robot has a name and three counters:

| | hit points | energy points | attack damage |
|---|---|---|---|
| `ClapTrap`  |  10 |  10 |  0 |
| `ScavTrap`  | 100 |  50 | 20 |
| `FragTrap`  | 100 | 100 | 30 |
| `DiamondTrap` | 100 (FragTrap) | 50 (ScavTrap) | 30 (FragTrap) |

Three shared actions operate on those counters: `attack()` (spends 1 energy point, announces the damage dealt), `takeDamage()` (subtracts hit points) and `beRepaired()` (spends 1 energy point to add hit points). A robot at 0 hit points or 0 energy points can no longer act — every function checks that first.

Each derived class then adds something of its own: `ScavTrap::guardGate()`, `FragTrap::highFiveGuys()`, `DiamondTrap::whoAmI()`.

The values above are declared as `static const size_t HIT_POINTS / ENERGY_POINTS / ATTACK_DAMAGE` inside each class, so a derived class can pass its own set up to the base constructor by name instead of by magic number.

## Build & run

Each exercise builds from within its own directory:

```sh
cd ex00 && make        # -> ./claptrap
cd ex01 && make        # -> ./scavtrap
cd ex02 && make        # -> ./fragtrap
cd ex03 && make        # -> ./diamondtrap
```

Standard 42 Makefile targets in every exercise: `all`, `clean` (remove `.o`), `fclean` (remove `.o` + binary), `re` (fclean + all). There is no test suite — verify by running the binary and reading its output.

Because every constructor, destructor and assignment operator prints a line, the output of each binary is essentially a **trace of object lifetime**: it shows in what order the compiler builds a derived object (base first, then derived) and tears it down (derived first, then base).

## Hard constraints (42 norm)

- Compiler flags are fixed: `c++ -std=c++98 -Wall -Wextra -Werror`. Code **must** compile clean under `-Werror` with **C++98** — no C++11+ features (no `auto`, `nullptr`, range-`for`, etc.).
- Every `.cpp` / `.hpp` / `Makefile` carries the 42 header comment block.
- Headers use include guards.

## Exercises

### ex00 — `ClapTrap`: the base class

A single class, no inheritance yet. `ClapTrap` holds a name and its three counters as **private** members, follows the Orthodox Canonical Form (default constructor, name constructor, copy constructor, `operator=`, destructor), and implements `attack()`, `takeDamage()` and `beRepaired()`. An overloaded `operator<<` prints the robot.

The interesting part is the guard logic: what should happen when a dead robot attacks, when a robot takes more damage than it has hit points left, or when an out-of-energy robot tries to repair itself.

**Concepts:** classes vs. C `struct`s, the Orthodox Canonical Form, `private` data + public interface, `static const` class constants and why they still need an out-of-class definition, `operator<<` as a free function.

### ex01 — `ScavTrap`: first derived class

`ScavTrap` inherits publicly from `ClapTrap`. It reuses everything the base already does, but:

- it passes its own stat block (100 / 50 / 20) up to a **protected** `ClapTrap` constructor from its initialisation list;
- it **shadows** `attack()` with its own version, prefixed with `[SCAVTRAP]:`;
- it adds `guardGate()` and a private `bool _is_guarded` flag of its own.

To make this possible, `ClapTrap`'s data members move from `private` to `protected`, and a four-argument constructor is added in the `protected` section — usable by derived classes, invisible to everyone else.

**Concepts:** public inheritance, `protected` vs. `private`, calling a base constructor from a member-initialiser list, construction/destruction order, hiding a base member function (non-virtual — resolved at compile time by the *static* type), calling `ClapTrap::operator=` from `ScavTrap::operator=`.

### ex02 — `FragTrap`: a sibling class

`FragTrap` derives from `ClapTrap` too, alongside `ScavTrap` — the hierarchy widens instead of deepening. Its stat block is 100 / 100 / 30, and it adds `highFiveGuys()`. It keeps `ClapTrap`'s `attack()` rather than overriding it.

Adding a *second* independent child of the same base is what sets up the next exercise: two siblings, each carrying its own complete copy of `ClapTrap`.

**Concepts:** sibling classes in a hierarchy, code reuse through a common base, when to override an inherited function and when to inherit it unchanged.

### ex03 — `DiamondTrap`: multiple inheritance & the diamond

`DiamondTrap` inherits from **both** `ScavTrap` and `FragTrap`, which both inherit from `ClapTrap`. That is the classic **diamond**:

```
        ClapTrap
        /      \
   ScavTrap   FragTrap
        \      /
      DiamondTrap
```

Without precautions, a `DiamondTrap` would contain **two** `ClapTrap` subobjects — two names, two hit-point counters — and every reference to a base member becomes ambiguous. The fix is **virtual inheritance**: `ScavTrap` and `FragTrap` both declare `virtual public ClapTrap`, so the shared base exists exactly once and `DiamondTrap` itself is the one responsible for constructing it.

`DiamondTrap` also:

- keeps its **own** `_name` while the inherited `ClapTrap::_name` becomes `<name>_clap_name`, so `whoAmI()` can print both and make the two distinct subobjects visible;
- mixes its stats: hit points and attack damage from `FragTrap`, energy points from `ScavTrap`;
- uses `ScavTrap::attack()` explicitly, choosing between two inherited implementations of the same function.

**Concepts:** multiple inheritance, the diamond problem, `virtual` inheritance and the single shared base subobject, why the most-derived class initialises a virtual base directly, name ambiguity and explicit `Base::member` qualification, name shadowing between a derived member and an inherited one.

## Layout

```
cpp03/
├── ex00/   ClapTrap    — base class, canonical form
├── ex01/   ScavTrap    — single inheritance
├── ex02/   FragTrap    — sibling derived class
└── ex03/   DiamondTrap — multiple + virtual inheritance
```
