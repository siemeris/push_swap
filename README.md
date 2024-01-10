# Push Swap - 42 School Project


## Table of Contents

- [Introduction](#introduction)
- [Operations Allowed](#operations-allowed)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Push Swap is a project at 42 School that challenges you to implement a sorting algorithm using two stacks. The goal is to sort a set of integers with a limited set of operations while minimizing the number of moves.

## Operations allowed

- sa : swap a - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
- sb : swap b - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- ra : rotate a - shift up all elements of stack A by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack B by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack A by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack B by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/siemeris/push_swap.git
   cd push_swap
   ```
2. Compile the project:
    
    ```bash
    make
    ```

## Usage

Run the program by providing a list of integers as arguments:  

    ```bash
    ./push_swap 4 2 8 1 3
    ```

### Project Structure

The project structure is organized as follows:

- `push_swap/`: Contains the project source code.
- `./libft/`: 42 standard library, first project performed in the cursus.
- `./Makefile`: File for compiling the project.

### Examples

1. Sorting a list of integers:

    ```bash
    ./push_swap 9 4 2 7 1
    ```
2. Checking if the list is sorted:
    ```bash
    ./push_swap 3 1 5 | ./checker 3 1 5
    ````

### Contributing

If you wish to contribute to this project, please create an issue or submit a pull request.
