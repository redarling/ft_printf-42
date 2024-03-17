# 🖨️ ft_printf

## Project Description
ft_printf is a project that aims to mimic the behavior of the standard C library function `printf`. It allows for formatted output to the standard output stream or to a string.

## 🛠️ Installation Instructions
1. Clone the repository using the command:

        git clone https://github.com/redarling/ft_printf-42.git

2. Navigate to the project directory:

        cd ft_printf-42

3. Compile the project:

        make

## 💻 Usage
1. Include the header file in your project:

        # include "ft_printf.h"

2. Call the function ft_printf in your code with the desired format string and arguments:

        ft_printf("%s World! - %d school\n", "Hello", 42);

3. The function behaves similarly to printf and outputs the formatted string to the standard output.

## Supported Format Specifiers

| Operation | Explanation                                |
|-----------|---------------------------------------------|
| %c        | Character |
| %s        | String |
| %p        | Pointer address                 |
| %d        | Signed decimal integer |
| %i        | Signed decimal integer |
| %u        | Unsigned decimal integer |
| %x        | Unsigned hexadecimal integer (lowercase) |
| %X        | Unsigned hexadecimal integer (uppercase)                  |
| %%        | Percent sign |

## 📝 Author
- [asyvash](https://github.com/redarling)

