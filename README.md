# ft_printf

## Description

The "ft_printf" project aims to recreate the functionality of the standard C library function `printf()`. By undertaking this challenge, you will gain insights into variadic functions in C, while honing your programming skills. The project encourages the creation of a well-structured and extensible code for a custom `printf()` function.

## Overview of Implemented Features

### Mandatory Part

#### Program Name: libftprintf.a

Implement the `ft_printf()` function that mimics the behavior of the original `printf()`. The function prototype is `int ft_printf(const char *, ...)`. The following conversions must be handled: c, s, p, d, i, u, x, X, %.

### Bonus Part

**Bonus Features:**

- Manage any combination of flags: `-`, `0`, `.` and the field minimum width under all conversions.
- Manage all the following flags: `#`, `+`, and space.

**Note:** The bonus part will only be evaluated if the mandatory part is perfect.

## How to Run the Project

1. Clone the project repository to your local machine.
2. Navigate to the project directory.
3. Compile the source files using the provided Makefile and the following commands:
   ```bash
   make
   ```
