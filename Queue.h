//   File:          Queue.h
//   Purpose:       The header file for Queue.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include "List.h"

typedef struct {
  List *L;
} Queue;

//the head of the queue is the front (pop off head)
//the tail of the queue is the back (push onto tail)


//Creates a new Queue
Queue *newQueue();


//Basic necessities...
int sizeQ(const Queue *q); //returns the size of q
int emptyQ(const Queue *q); //returns if q is empty


//Core functions for a Queue
void insertQ(Queue *q, void *item); //inserts an item at the back (tail) of q
void *removeQ(Queue *q); //pops an item from the front (head) of q
