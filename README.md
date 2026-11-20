*This project has been created as part of the 42 curriculum by rghomari.*

## Description

ft_printf is a C library that implements a subset of printf.

Supported conversions:

- `%c`: character
- `%s`: string
- `%p`: pointer address
- `%d`, `%i`: signed decimal integer
- `%u`: unsigned decimal integer
- `%x`, `%X`: lowercase and uppercase hexadecimal integer
- `%%`: percent sign

The function returns the number of bytes printed, or a negative
value if an output error occurs.

The project does not implement printf's buffer management.

## Instructions

Build the library:

```sh
make
```

This creates `libftprintf.a` at the repository root.

Include `ft_printf.h` and declare `int ft_printf(const char *str, ...);`
in `main.c` before calling it. Then compile with the library:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

Other commands:

```sh
make clean
make fclean
make re
```

## Algorithm and data structures

The format string is scanned from left to right.

Ordinary characters are written directly. When a percent sign is
encountered, the next character selects a conversion helper.

A `va_list` tracks the variable arguments. Conversions that take an
argument retrieve it with `va_arg` using the corresponding type.

Numbers are printed using two loops. The first finds the highest
power of 10 or 16 needed for the number. The second prints one digit
at a time from left to right, dividing the divisor by the base after
each digit. Hexadecimal conversions use a digit lookup string.

Non-null pointers are cast to `size_t` and printed in lowercase
hexadecimal with a `0x` prefix.

No heap allocation or additional container data structure is needed.
Each helper returns its printed byte count and propagates write
failures to the caller.

## Compatibility choices

Null strings print `(null)` and null pointers print `(nil)`,
matching common glibc behavior for the supported conversions.

Passing a null string to standard printf's `%s` is undefined behavior
in C; this handling is a compatibility choice.

## Resources

- printf manual:
  https://man7.org/linux/man-pages/man3/printf.3.html
- stdarg manual:
  https://man7.org/linux/man-pages/man3/stdarg.3.html
- variadic functions:
  https://youtu.be/7Sph8JlRo0g?si=EDQd-qnPZNmlXi7q

## AI Usage

AI was used to help correct Norminette formatting, deepen my understanding of variadic functions, and provide practical exercises to reinforce my understanding.