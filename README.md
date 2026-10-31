*This project has been created as part of the 42 curriculum by jeguiber.*

# ft_printf

## Description

`ft_printf` is a small C library that reimplements the mandatory part of the
standard `printf` function. The project focuses on variadic functions:
`ft_printf` receives a format string followed by a variable number of
arguments, interprets each conversion, writes the result to standard output,
and returns the number of characters written.

The library is built as `libftprintf.a` and supports the mandatory
conversions:

| Conversion | Behavior |
|---|---|
| `%c` | Prints one character. |
| `%s` | Prints a string. A null string is printed as `(null)`. |
| `%p` | Prints a pointer in lowercase hexadecimal with a `0x` prefix. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned hexadecimal integer using lowercase digits. |
| `%X` | Prints an unsigned hexadecimal integer using uppercase digits. |
| `%%` | Prints a percent sign. |

The bonus flags, field width, precision, and original `printf` buffer
management are not implemented.

## Instructions

### Compilation

Build the static library at the repository root:

```sh
make
```

The Makefile compiles with `cc -Wall -Wextra -Werror` and creates the archive
with `ar`. Available targets are:

```sh
make        # Build libftprintf.a
make clean  # Remove object files
make fclean # Remove object files and libftprintf.a
make re     # Rebuild from scratch
```

### Usage

Include `ft_printf.h` and link the generated archive:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello, %s! Number: %d\n", "42", 42);
	return (0);
}
```

Compile the program from the repository root:

```sh
cc -Wall -Wextra -Werror
```

## Project structure

| File | Purpose |
|---|---|
| `ft_printf.c` | Main format-string parser and conversion dispatch. |
| `ft_printf_var.c` | Output helpers for characters, strings, numbers, hexadecimal values, and pointers. |
| `ft_printf.h` | Public function prototypes and required headers. |
| `Makefile` | Builds and cleans `libftprintf.a`. |

## Resources

- Official ft_printf subject (`en.subject.pdf`): required files and project constraints.
- `man 3 printf` - reference behavior for formatted output.
- `man 3 stdarg` - variadic argument macros such as `va_start`, `va_arg`, and
  `va_end`.
- C language documentation for integer representations, pointers, and
  hexadecimal notation.

### AI usage

AI assistance was used to organize and write this README,provided guidance for creating the `main` files. The C implementation remains the responsibility of the project author, who is accountable for its correctness and the information presented here.
