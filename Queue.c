//   File:          Queue.c
//   Purpose:       The source file for Queue.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include <stdlib.h>


#include "Queue.h"


//Creates a new Queue
Queue *newQueue() {
  Queue *q = malloc(sizeof(Queue));
  q -> L = newList();
} // newQueue()


//Basic necessities...
int sizeQ(const Queue *q) {
  return size(q -> L);
} // sizeQ()


int emptyQ(const Queue *q) {
  return empty(q -> L);
} // emptyQ()


//Core functions for a Queue
void insertQ(Queue *q, void *item) {
  add(q -> L, item);
} // insertQ()

void *removeQ(Queue *q) {
  removeItem(q -> L, 0); //the front of the queue is the top
} // removeQ()
