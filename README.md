*This project has been created as part of the 42 curriculum by jwira.*

# push_swap

## Description

`push_swap` is a 42 project that sorts integers using two stacks and a limited set of operations. The program does not print the sorted list itself; it prints the sequence of moves needed to transform stack A into ascending order with as few operations as possible.

This implementation handles input passed as separate arguments or as a single quoted string, validates integers, detects duplicates, and switches between a small-stack strategy and a chunk-based strategy depending on the input size. Chunk sort is used for larger inputs because it helps reduce the number of moves by grouping values into manageable ranges before pushing them back in order. It uses a custom `libft` for parsing and utility helpers.

## Instructions

Compilation:

```bash
make
```

Useful cleanup targets:

```bash
make clean
make fclean
make re
```

Execution:

```bash
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap 9 1 8 2 7 3 6 4 5
```

The program writes the stack operations to standard output. If the input is already sorted, it exits without printing anything.

Allowed operations:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

## Resources

References:

- 42 push_swap subject and intra documentation
- The C standard library documentation for integer conversion and memory management
- [GeeksforGeeks: Stack data structure](https://www.geeksforgeeks.org/c/implement-stack-in-c/)
- [GeeksforGeeks: Linked lists in C](https://www.geeksforgeeks.org/c/linked-list-in-c/)
- [w3schools: usage of exit() function](https://www.w3schools.com/c/ref_stdlib_exit.php)
- [kurval/42-push_swap](https://github.com/kurval/42-push_swap) - reference implementation used to better understand the chunk-sort approach and project structure.

AI usage:

- AI was used to draft and polish this README,and to help organize my thoughts about the chunk-sort algorithm.