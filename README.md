# tdd_exercise

TDD exercise in C++ using GoogleTest

## Aim

To practice applying the principles of OOP and TDD (Test-Driven-Development) by writing a simple bowling score calculator in C++ with an unit test framework, [GoogleTest](https://google.github.io/googletest/).

## Description

- Write a program that computes the total score for the game of Ten-Pin Bowling, given a valid sequence of rolls for one line.
- The sequence of rolls will be provided in a `*.bs` file. The name of the score set file will be given as the first argument to the program.
- `*.bs` files MUST follow the following rules. Unless the program exits after displaying an appropriate error message.
  - The sequence of rolls are enclosed by a pair of curly brackets.
  - Each frame is delimitted by a semicolon and each pair of roll in the same frame are enclosed by a pair of square brackets.
  - 0 <= (the result of each roll) <= 10
- How score is calculated is explained in [this link](https://en.wikipedia.org/wiki/Ten-pin_bowling#Traditional_scoring).
