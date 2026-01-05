_This project has been created as part of the 42 curriculum by asadik._

# Description

Partially recreates the functionality of the original printf function as seen in the ISO C99 Standard. `ft_printf(char *str, ...)` takes a string as its first parameter, optionally containing multiple format specifiers, and a variable number of arguments corresponding to the mentioned format specifiers to be printed. The function has no guards against overflow or not matching the variadic arguments to the correct format specifier. This would be undefined behavior.

The following format specifiers are implemented:
 - "%c" Prints a single character.
 - "%s" Prints a string (as defined by the common C convention).
 - "%p" The void * pointer argument has to be printed in hexadecimal format.
 - "%d" Prints a decimal (base 10) number.
 - "%i" Prints an integer in base 10.
 - "%u" Prints an unsigned decimal (base 10) number.
 - "%x" Prints a number in hexadecimal (base 16) lowercase format.
 - "%X" Prints a number in hexadecimal (base 16) uppercase format.
 - "%%" Prints a percent sign.

# Instruction

Compile with make. Compile with the debug flag using make debug. All other standard make rules apply. This will create a static library file called `libftprintf.a`. The header file `ft_printf.h` only exposes `ft_printf()`. Some utility functions are exposed by `ft_printf_util.h`. Users are discouraged from including this file in their code.

# Resources

[Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/) was used to learn about variadic functions.
AI and talking to colleagues were used to learn about Make syntax and flags.
This Readme was proofread by AI.

# Explanation

`t_printf()` loops through the given string and prints it to the standard output. If a '%' character is found, the static `coordinator()` function parses the next character. When applicable, the corresponding variadic variable is accessed, and one of several helper functions is called to print the variable to the standard output according to the format specifier. The amount of characters is counted in those helper functions and added to the total before the loop continues. When the null terminator is reached, `ft_printf()` returns the total number of characters printed. A negative integer cannot be returned.