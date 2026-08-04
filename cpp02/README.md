# C++ Module 02 — Ad-hoc Polymorphism, Operator Overloading & the Orthodox Canonical Form

This module builds a single class — `Fixed`, a **fixed-point number** — incrementally across four exercises, starting from the bare *Orthodox Canonical Form* and growing into a fully operator-overloaded arithmetic type. The final exercise puts the class to work in a small computational-geometry problem.

Each `exNN/` directory is a **self-contained, independently-compiled** exercise with its own `Makefile`. There is no top-level Makefile — build each exercise from inside its own directory.

## What is a fixed-point number?

A fixed-point number stores a fractional value inside a plain integer by reserving a fixed number of the integer's low bits for the fractional part. In this module the class keeps one `int fixedPoint` and a `static const int numFractBits = 8`, so the stored integer is the real value scaled by `2^8 = 256`:

```
real value  = fixedPoint / 256
fixedPoint  = round(real value * 256)
```

So `fixedPoint = 256` represents `1.0`, `fixedPoint = 128` represents `0.5`, and so on. It is a lightweight way to get fractional arithmetic without floating-point — the same trick used in graphics and embedded code.

## Build & run

Each exercise builds from within its own directory:

```sh
cd ex00 && make        # -> ./fixed
cd ex03 && make        # -> ./bsp
```

The binary is named `fixed` in ex00–ex02 and `bsp` in ex03.

Standard 42 Makefile targets in every exercise: `all`, `clean` (remove `.o`), `fclean` (remove `.o` + binary), `re` (fclean + all). There is no test suite — verify by running the binary and reading its output.

## Hard constraints (42 norm)

- Compiler flags are fixed: `c++ -std=c++98 -Wall -Wextra -Werror`. Code **must** compile clean under `-Werror` with **C++98** — no C++11+ features (no `auto`, `nullptr`, range-`for`, etc.).
- Every `.cpp` / `.hpp` / `Makefile` carries the 42 header comment block.
- Headers use include guards.

## Exercises

### ex00 — `Fixed`: the Orthodox Canonical Form

The starting point. `Fixed` holds a private `int fixedPoint` and implements the four functions every canonical C++ class provides:

- default constructor
- copy constructor
- copy assignment operator (`operator=`)
- destructor

plus `getRawBits()` / `setRawBits()` to read and write the raw stored integer. Each of the four special functions prints a message, so running `main` shows exactly **when** the compiler constructs, copies, assigns, and destroys objects.

**Concepts:** classes vs. C `struct`s, constructors/destructors, the Orthodox Canonical Form, `const` member functions, `static const` data members.

### ex01 — conversions & stream output

`Fixed` gains the ability to be created from, and converted back to, the built-in numeric types:

- `Fixed(const int)` and `Fixed(const float)` constructors
- `toInt()` and `toFloat()` conversion methods
- an overloaded `operator<<` so a `Fixed` can be printed with `std::cout << f`

This is the first encounter with **converting between representations** (int/float ↔ fixed-point via bit-shifting and rounding) and with overloading a **non-member** operator (`<<`) for a user-defined type.

**Concepts:** overloaded constructors, implicit conversions, bit-shifting for scaling, `operator<<` as a free function, `std::ostream`.

### ex02 — full operator overloading

`Fixed` becomes a first-class arithmetic type by overloading the operators that make it behave like a built-in number:

- **comparison:** `>`, `<`, `>=`, `<=`, `==`, `!=`
- **arithmetic:** `+`, `-`, `*`, `/`
- **increment / decrement:** pre- and post-forms of `++` and `--` (distinguished by the dummy `int` parameter on the post-forms)
- **static** `min()` and `max()` helpers, each in a mutable and a `const` overload

**Concepts:** member vs. non-member operators, how `a OP b` desugars to a function call, pre- vs. post-increment semantics and return types, `static` member functions, function overloading on `const`.

### ex03 — `BSP`: point-in-triangle

Applies the `Fixed` type to geometry. A `Point` class stores two **`const Fixed`** coordinates (`_x`, `_y`), and a free function

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

returns whether `point` lies strictly **inside** the triangle `a b c`. The test is built from one primitive — the sign of a 2D **cross product**, which tells you which side of a directed edge a point falls on. A point is inside when it lies on the *same side* of all three edges (so the three cross products share a sign); a point on an edge or vertex (a zero cross product) is treated as **not** inside.

The name nods to *Binary Space Partitioning*: the "which side of a line?" question this exercise answers three times is the atomic operation a full BSP tree asks at every node.

**Concepts:** composing a class from another user-defined type, `const` data members (and what that means for assignment), 2D vectors and the cross product, signed area, algorithm design from a single reusable primitive.

## Layout

```
cpp02/
├── ex00/   Fixed — Orthodox Canonical Form
├── ex01/   Fixed — conversions + operator<<
├── ex02/   Fixed — full operator overloading
└── ex03/   BSP   — Point class + point-in-triangle test
```
