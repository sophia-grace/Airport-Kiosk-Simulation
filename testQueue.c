//   File:          testQueue.c
//   Purpose:       Tests the implementation of Queue.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

int main(void) {
  Queue *q;
  q = newQueue();

  printf("Q Size = %d\n", sizeQ(q));
  if(emptyQ(q)) {
    printf("The queue is empty.\n");
  }
  else {
    printf("The queue is not empty.\n");
  }

  int *n;
  printf("Adding: ");
  for(int i = 0; i < 10; i++) { //Insert 10 #'s to Q
    n = malloc(sizeof(int));
    *n = rand()%100;
    printf("%d ", *n);
    insertQ(q, n);
  }
  printf("\n");

  printf("Q Size = %d\n", sizeQ(q));
  if(emptyQ(q)) {
    printf("The queue is empty.\n");
  }
  else {
    printf("The queue is not empty.\n");
  }

  for(int i = 0; i < 8; i++) { //Remove 8 #'s from Q
    n = removeQ(q);
    printf("Removed: %d\n", *n);
  }

  printf("Q Size = %d\n", sizeQ(q));
  if(emptyQ(q)) {
    printf("The queue is empty.\n");
  }
  else {
    printf("The queue is not empty.\n");
  }

  return(0);
} // main()
