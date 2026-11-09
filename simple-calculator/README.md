Simple Calculator

Description

A simple terminal-based calculator project written in C.

The program displays a menu, reads the user’s choice, and repeats the menu until the user selects 0 to quit.

Compilation

Compile the program using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

How to Run

Run the compiled program:

./calculator

Enter a number from the menu.

Menu

1. Add
2. Subtract
3. Multiply
4. Divide
5. Quit

Supported Operations

The program currently supports displaying the menu, reading integer choices, repeating the menu, and quitting with option 0.

Addition, subtraction, multiplication, and division are planned but not yet implemented.

Numeric Behavior

Menu choices are read as integers using scanf.

The program does not yet perform calculations with integer or decimal operands.

Known Limitations

* Arithmetic operations are not implemented yet.
* Invalid menu numbers repeat the menu.
* Non-numeric input is not handled reliably.