# C++ Module 00

Each `exNN/` directory is a self-contained exercise with its own sources and (where
present) its own `Makefile`. There is no top-level build; each exercise is compiled
independently from within its own folder.

All code targets **C++98** and must compile clean:

```sh
c++ -std=c++98 -Wall -Wextra -Werror
```

---

## ex00 — megaphone

A tiny program that shouts back its command-line arguments.

- With arguments: prints every argument **uppercased**, concatenated on a single line.
- With no arguments: prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.

**Build & run**

```sh
cd ex00 && make        # -> ./megaphone
./megaphone "hello" "world"      # -> HELLOWORLD
./megaphone                      # -> * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

Files: `megaphone.cpp`, `Makefile`.

---

## ex01 — phonebook

An interactive contact manager driven by a simple command loop: `ADD`, `SEARCH`,
`EXIT`.

- Stores a fixed array of **8** contacts.
- Once full, the oldest entry is overwritten first (circular buffer).
- Each `Contact` holds five fields: first name, last name, nickname, phone number,
  and darkest secret.

**Design**

- `Contact` — owns the five `std::string` fields; `fill()` prompts stdin for the
  values, and the rest of the interface is `const` getters. It holds no printing logic.
- `PhoneBook` — owns the `Contact[8]` array and the index cursor. It handles adding
  contacts, wrapping the cursor at capacity, and all rendering.
- `main.cpp` — runs the `ADD` / `SEARCH` / `EXIT` command loop.

**Build & run**

```sh
cd ex01 && make        # -> ./phonebook
./phonebook
```

Files: `main.cpp`, `Contact.hpp`, `Contact.cpp`, `PhoneBook.hpp`, `PhoneBook.cpp`,
`Makefile`.

> Status: work in progress — the search/print path is not yet complete.

---

## ex02 — Account (log reconstruction)

Rebuild the `Account` class from a provided header (`Account.hpp`) and test driver
(`tests.cpp`) so that the program reproduces a given reference log **exactly** — apart
from the timestamps, which reflect the current time.

- `Account` tracks a per-account index, balance, and deposit/withdrawal counts, plus
  static class-wide totals shared across all accounts.
- Every operation (creation, deposit, withdrawal, closure) prints a timestamped log
  line; withdrawals that exceed the balance are refused.
- `_displayTimestamp()` formats the current time as `[YYYYMMDD_HHMMSS]`.

`19920104_091532.log` is the reference output to match.

**Build & run**

ex02 does not ship a `Makefile` yet; compile the class together with the test driver:

```sh
cd ex02
c++ -std=c++98 -Wall -Wextra -Werror Account.cpp tests.cpp -o account
./account
```

Files: `Account.hpp`, `Account.cpp`, `tests.cpp`, `19920104_091532.log`.

---

## Standard Makefile targets

Every exercise that ships a `Makefile` provides:

| Target   | Effect                          |
| -------- | ------------------------------- |
| `all`    | build the binary (default)      |
| `clean`  | remove `.o` object files        |
| `fclean` | remove `.o` files and binary    |
| `re`     | `fclean` then `all`             |
