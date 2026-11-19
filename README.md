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

Include `ft_printf.h` in your program, then compile:

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

A va_list tracks the variable arguments. Each conversion retrieves
its argument using the corresponding type.

Numbers are printed recursively. Division processes the preceding
digits, and remainder selects the current digit. Hexadecimal
conversions use a digit lookup string.

Pointers are converted to unsigned long before hexadecimal formatting.

No heap allocation or additional container data structure is needed.
Each helper returns its printed byte count and propagates write
failures to the caller.

## Compatibility choices

Null strings print `(null)` and null pointers print `(nil)`,
matching common glibc behavior for the supported conversions.

Passing a null string to standard printf's `%s` is undefined behavior
in C; this handling is a compatibility choice.

A null format string, unsupported conversion, or trailing percent
sign returns `-1` in this implementation. These are outside the
supported valid-format contract.

## Resources

- printf manual:
  https://man7.org/linux/man-pages/man3/printf.3.html
- stdarg manual:
  https://man7.org/linux/man-pages/man3/stdarg.3.html
- variadic functions:
  https://youtu.be/7Sph8JlRo0g?si=EDQd-qnPZNmlXi7q

## AI Usage

AI was used to help correct Norminette formatting, deepen my understanding of variadic functions, and provide practical exercises to reinforce my understanding.