# C++ Module 01

Each `exNN/` directory is a self-contained exercise with its own `Makefile`. Build and run every exercise from inside its own directory.

## Build & run

```sh
cd ex00 && make       # each Makefile supports: all, clean, fclean, re
./<binary>            # binary name differs per exercise (see table below)
```

Compiled with the fixed 42 flags: `c++ -std=c++98 -Wall -Wextra -Werror`.

| Exercise | Binary       | Topic                                            |
|----------|--------------|--------------------------------------------------|
| ex00     | `zombie`     | Stack vs heap allocation                         |
| ex01     | `zombie`     | Allocating an array of objects on the heap       |
| ex02     | `manip`      | Pointers vs references (`HI THIS IS BRAIN`)      |
| ex03     | `attack`     | Reference members vs pointer members             |
| ex04     | `replace`    | File streams + string find/replace (`sed` clone) |
| ex05     | `harl`       | Pointers to member functions                     |
| ex06     | `harlFilter` | `switch` fall-through log filtering              |

---

## ex00 — BraiiiiiiinnnzzzZ

Two ways to make a `Zombie`, contrasting the two storage durations:

- `randomChump(name)` — creates a zombie **on the stack**; it announces itself and is destroyed automatically when the function returns.
- `newZombie(name)` — creates a zombie **on the heap** with `new`, returns a pointer, and hands ownership (and the `delete`) to the caller.

The point is to see *when the destructor fires* for each: automatically at end of scope vs. only when you `delete`.

```sh
cd ex00 && make && ./zombie
```

## ex01 — Moar brainz

`zombieHorde(N, name)` allocates **an array of `N` zombies in a single heap allocation** (`new Zombie[N]`), names each one, and returns the pointer to the first. `main` walks the array, makes each announce, then frees the whole block with `delete[]`.

Key detail: the array is allocated with `new[]`, so it **must** be freed with `delete[]` (not `delete`).

```sh
cd ex01 && make && ./zombie
```

## ex02 — HI THIS IS BRAIN

A pure demonstration exercise (no class). It creates a `std::string`, a **pointer** to it, and a **reference** to it, then prints:

1. the three addresses (`&string`, the pointer, `&reference`) — all identical,
2. the three values (`string`, `*pointer`, `reference`) — all identical.

Shows that a reference is an alias to the same object, not a copy.

```sh
cd ex02 && make && ./manip
```

## ex03 — Unnecessary violence

A `Weapon` with a `type`, wielded by two kinds of human:

- **`HumanA`** holds the weapon as a **reference** (`Weapon &`). The weapon must exist at construction and can never be null — set once, always present.
- **`HumanB`** holds the weapon as a **pointer** (`Weapon *`). It can be constructed *without* a weapon and given one later via `setWeapon`.

Because both store a reference/pointer to the *same* `Weapon` (not a copy), calling `setType` on the weapon changes what the human attacks with on the next `attack()`.

```sh
cd ex03 && make && ./attack
```

## ex04 — Sed is for losers

A minimal `sed`-style replacer.

```sh
cd ex04 && make && ./replace <filename> <s1> <s2>
```

Reads `<filename>` line by line with `std::ifstream`, replaces **every** occurrence of `s1` with `s2`, and writes the result to `<filename>.replace` via `std::ofstream`. Uses `std::string::find` / `substr` rather than C string functions. Sample inputs live in `ex04/files/`.

## ex05 — Harl 2.0

`Harl` complains at four levels — `DEBUG`, `INFO`, `WARNING`, `ERROR` — each a private member function. `complain(level)` dispatches to the right one using an **array of pointers to member functions** indexed by a matching level string, instead of a chain of `if`/`else if`. `main` fires all four levels in order.

```sh
cd ex05 && make && ./harl
```

## ex06 — Harl filter

Same `Harl`, but the level comes from the command line and the `switch` **deliberately falls through**: passing a level prints that level *and every level above it*.

```sh
cd ex06 && make
./harlFilter WARNING     # prints WARNING and ERROR
./harlFilter DEBUG       # prints all four
```

An unknown level prints the default "insignificant problems" message. This is the intended use of `switch` fall-through (no `break` between cases) to express "this level and higher".
