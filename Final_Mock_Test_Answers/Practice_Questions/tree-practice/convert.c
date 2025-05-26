#include <stdio.h>
#include "tree.h"

// FUNCTION DEFINITIONS
Node* convert(Node* root);
void convertRecursive(Node* current, Node** lastNode);
void printList(Node* head);

// Don't change the main function
int main(int argc, char * argv[]){
    if (argc < 2){
        printf("Not enough arguments\n");
        return -1;
    }
    Node* root = create_tree(argv[1]);
    root = convert(root);
    printList(root);
    deleteList(root);
}

// 将二叉搜索树转换为双向链表
Node * convert(Node* root){
    // YOUR CODE HERE
    if (root == NULL){return NULL;}
    Node* lastNodeInList = NULL; // 递归后将指向双向链表的尾部

    convertRecursive(root, &lastNodeInList); // 执行中序遍历并链接节点

    // 递归之后, lastNodeInList 指向尾节点 (最右边的元素).
    // 我们需要找到头节点 (最左边的元素).
    // 头节点是在转换后 'left' 指针为 NULL 的节点.
    Node* head = root;
    // 在转换后的链表中遍历到最左边的节点
    // 'left' 指针现在指向链表中的前一个元素.
    while (head != NULL && head->left != NULL) {
        head = head->left;
    }
    return head; // 返回头节点
}

// 将二叉搜索树转换为双向链表的递归函数
void convertRecursive(Node* current, Node** lastNode){
    // YOUR CODE HERE
    if (current == NULL){return;}
    
    convertRecursive(current->left, lastNode); // 递归左子树
    
    // 处理当前节点（中序遍历）
    // 当前节点的"left"指针(在双向链表中是prev)应该指向已处理链表中的最后一个节点
    current->left = *lastNode; // 设置当前节点的左指针为上一个节点

    // 如果 lastNodeInList 不为 NULL (即 current 不是双向链表中的第一个节点),
    // 那么它的 'right' 指针 (在双向链表中是 next) 应该指向当前节点
    if (*lastNode != NULL) {
        (*lastNode)->right = current;
    }

    // 更新 lastNodeInList 为当前节点, 因为它现在是双向链表中的最后一个节点
    *lastNode = current;

    // 递归转换右子树
    convertRecursive(current->right, lastNode);
}


// Given a doubly linked list prints out the list from left to right
// then from right to left (ensures all left and right pointers are correct)
void printList(Node* head){
    Node* previous;
    printf("Left to right traversal: \n");
    while (head != NULL)
    {
        printf("%d ", head->value);
        previous = head;
        head = head->right;
    }
    printf("\nRight to left traversal: \n");
    head = previous;
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->left;
    }
    printf("\n");
}
