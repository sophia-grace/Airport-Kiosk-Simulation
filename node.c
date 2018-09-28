//   File:          node.c
//   Purpose:       The node source file.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include <stdlib.h>
#include "node.h"


// Creates a new node with item
struct node *newNode(void *item) {
   struct node *n = malloc(sizeof(struct node));
   n->data = item;
   n->next = NULL;
   return n;
} // newNode()
