#ifndef TREE
#define TREE

/* A node in a tree
*  value - the node's value
*  left - a pointer to the left node
*  right - a pointer to the right node
*/
typedef struct Node {
    int value;
    Node* left;
    Node* right;
    Node* prev_node;
    Node* head_node;
} Node;

void bst_to_dll(Node* current_node);

// Deletes a doubley linked list
void deleteList(Node* head);

// Given a file creates a tree from the file contents
Node* create_tree(char* fileName);

#endif /*!TREE*/
