# Trees

For this question, you are given a binary search tree and you have to convert it into a doubly linked list.

Binary search tree is a binary tree such that:

- The left subtree of a node contains only nodes with keys less than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.
- Each node can have up to two successor nodes
- There must be no duplicate nodes.

An in order traversal of a binary search tree traverses the tree in sorted order. Your code must convert the tree to a doubly linked list with the values in sorted order.

To compile the code:

`make clean`

`make`

To run the code

`./convert tests/test1.txt`
