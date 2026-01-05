_This project has been created as part of the 42 curriculum by asadik._

# Description
Partially recreates the functionality of the original printf function.
`ft_printf()` takes a variable number of arguments and prints to the standard output, according to the given format specifiers, parsed out of the first parameter, a string.
Following format specifiers are implemented:
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
Compile with "make". Compile with debug flag using "make debug". This will create a static library file called `libftprintf.a`.

# Resources

# Explanation
