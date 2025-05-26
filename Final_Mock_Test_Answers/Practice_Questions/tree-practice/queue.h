#ifndef QUEUE
#define QUEUE

#include "tree.h"
#define MAXSIZE 500

typedef struct queue {
    Node* contents[MAXSIZE];
    int head;
    int tail;
} queue;

void initQueue(queue * inQueue);

void enqueue(queue * inQueue, Node * element);

Node* dequeue(queue * inQueue);

int isEmpty(queue * inQueue);

int isFull(queue * inQueue);

#endif /*!QUEUE*/
