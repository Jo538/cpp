# C++ Module 04 — Subtype Polymorphism, Abstract Classes, Interfaces

Each `exNN/` directory is a self-contained, independently-compiled
exercise with its own `Makefile`. There is no top-level Makefile — build each exercise separately.

## Build & run

```sh
cd ex00 && make        # -> ./animals (or equivalent binary name, see Makefile)
cd ex01 && make
cd ex02 && make
```

Standard Makefile targets in every exercise: `all`, `clean` (remove `.o`), `fclean` (remove
`.o` + binary), `re` (fclean + all). There is no test suite; verify by running each binary by
hand and reading its output.

## Constraints

Compiler flags are fixed across every exercise: `c++ -std=c++98 -Wall -Wextra -Werror`. Code must
compile clean under `-Werror` with **C++98** — no C++11+ features (`auto`, `nullptr`, range-`for`,
etc.).

## Exercises

### ex00 — virtual vs. non-virtual member functions

Two parallel class hierarchies:

- `Animal` → `Dog`, `Cat` — `makeSound()` is declared `virtual`.
- `WrongAnimal` → `WrongCat` — `makeSound()` is **not** declared `virtual`.

`main.cpp` calls `makeSound()` through base-class pointers on both hierarchies, side by side.
The point of the exercise is to observe the difference: through an `Animal *`, the call resolves
to the actual pointed-to derived type at runtime (dynamic dispatch); through a `WrongAnimal *`,
it resolves to `WrongAnimal::makeSound()` regardless of what it actually points to (static
binding, decided at compile time from the pointer's declared type).

### ex01 — deep copy with a pointer member

`Dog` and `Cat` each own a `Brain *_brain` — a heap-allocated `Brain` holding a fixed array of
100 `std::string` "ideas" (`setIdea()` / `getIdea()`). This forces a proper Orthodox Canonical
Form: the default (compiler-generated) copy constructor and assignment operator only copy the
pointer itself, leaving both objects pointing at the same `Brain` — the copy constructor and
`operator=` must instead allocate a new `Brain` and copy its contents, so each `Dog`/`Cat`
instance owns an independent one.

`getIdea()` also introduces exception handling (`std::out_of_range`) for invalid index access,
since it must return a `const std::string &` and a reference can never be null.

### ex02 — abstract classes and interfaces

`AAnimal` replaces the plain `Animal` base class from ex00/ex01: it declares `makeSound()` as a
**pure virtual function** (`= 0`) and gives itself a `protected` constructor. Together these make
`AAnimal` impossible to instantiate directly — it only exists to be inherited from. `Dog` and
`Cat` derive from it and must each provide a concrete `makeSound()` implementation to become
instantiable themselves. This is the C++98 route to what other languages call an "interface":
a class with no implementation, only a contract that derived classes must fulfill.
