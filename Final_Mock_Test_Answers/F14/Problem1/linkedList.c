#include "linkedList.h"


int DetectLoop(node *head)
{
  //Write code here.
  node* slow = head;
  node* fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return 1; // Loop detected
    }
  }
  return 0; // No loop detected
}

node *CopyList(node *head)
{
  //Insert Code here. You can change the return statement given.
  if (head == NULL){return NULL;}
  node* current = head;
  // 复制节点并插入原节点后
  while (current != NULL){
    node* copy = (node*)malloc(sizeof(node));
    copy->value = current->value;
    copy->next = current->next;
    current->next = copy;
    current = copy->next;
  }

  // 设置副本节点的arbitrary指针
  current = head;
  while (current != NULL){
    if (current->arbit != NULL){
      current->next->arbit = current->arbit->next;
    } else {
      current->next->arbit = NULL;
    }
    current = current->next->next;
  }

  // 分离原链表和复制链表
  current = head;
  node* newHead = head->next;
  node* temp = newHead;
  while (current != NULL){
    current->next = current->next->next;
    if (temp->next != NULL){
      temp->next = temp->next->next;
    }
    current = current->next;
    temp = temp->next;
  }

  return newHead;
}
