# Linked Lists

In mathematics, the Farey sequence of order **n** is the sequence of completely reduced fractions between 0 and 1 which, when in lowest terms, have denominator less than or equal to n, arranged in ascending orders. For this question, you need to print out the Farey sequence from order 1 to n, where n is the input from the user using linked list.

Here is the example of the Farey sequences of orders 1 to 6 are:

Order 1: $\{ \frac{0}{1}, \frac{1}{1} \}$

Order 2: $\{\frac{0}{1}, \frac{1}{2}, \frac{1}{1}\}$

Order 3: $\{\frac{0}{1}, \frac{1}{3}, \frac{1}{2}, \frac{2}{3}, \frac{1}{1}\}$

Order 4: $\{\frac{0}{1}, \frac{1}{4}, \frac{1}{3}, \frac{1}{2}, \frac{2}{3}, \frac{3}{4}, \frac{1}{1}\}$

Order 5: $\{\frac{0}{1}, \frac{1}{5}, \frac{1}{4}, \frac{1}{3}, \frac{2}{5}, \frac{1}{2}, \frac{3}{5}, \frac{2}{3}, \frac{3}{4}, \frac{4}{5}, \frac{1}{1}\}$

Order 6: $\{\frac{0}{1}, \frac{1}{6}, \frac{1}{5}, \frac{1}{4}, \frac{1}{3}, \frac{2}{5}, \frac{1}{2}, \frac{3}{5}, \frac{2}{3}, \frac{3}{4},\frac{4}{5}, \frac{5}{6}, \frac{1}{1}\}$

The Farey sequence start with  $\{ \frac{0}{1}, \frac{1}{1} \}$. After that, at each level, a new fraction $\frac{(a+b)}{(c+d)}$ is inserted between two neighbor fractions $\frac{a}{c}$ and $\frac{b}{d}$ only if $c+d\le n$. You will need to use liked list to calculate the fares sequence. The definition of the linked list node can be found in `farey_seq.h` . The `main, print_list, delete_list` functions are given to you. You  only need to implement the farey_seq function. Your code should not create any memory leak. Sample output is also given for you.

To complie and run you code:

 `g++ -Wall -g -o farey farey_seq.c`

`./farey`

To run your code with valgrind:

`valgirnd ./farey`
