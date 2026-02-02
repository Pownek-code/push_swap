*This project has been created as part of the 42 curriculum by schanqou.*
# Push_swap
## Description
**Push_swap** is an algorithmic project from the 42 curriculum. The primary goal is to sort a stack of integers (Stack A) using an auxiliary stack (Stack B) and a specific set of operations, while minimizing the total number of instructions used.

This project implements the **Turk Algorithm**, a cost-based sorting strategy. It works by moving elements from Stack A to Stack B, always selecting the node that requires the fewest operations (the "cheapest" move) to reach its correct position. Once Stack A is reduced to three elements, they are sorted directly, and the elements stored in Stack B are pushed back to Stack A in the correct order.
## Instructions
### Compilation
The project uses a `Makefile` for compilation. To build the `push_swap` executable, run:

```bash
make
```
### Execution
Run the program with a list of integers as arguments:

```bash
./push_swap <list_of_integers>
```
## Resources

### References
The following materials were used to understand the problem and design the solution:

- **Push_swap Turk Algorithm Explained in 6 Steps**  
  https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

- **42 Push_swap Subject PDF** – Official requirements, rules, and evaluation criteria.
### How AI Was Used
AI tools were used only as learning and documentation aids:
- Clarifying theoretical concepts (stack operations, cost-based sorting, Turk algorithm logic)
- Proofreading and formatting documentation
