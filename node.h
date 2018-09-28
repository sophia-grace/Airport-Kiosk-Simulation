//   File:          node.h
//   Purpose:       The header file for node.
//   Author:        Sophia Trump
//   Date:          30 April 2018


struct node {
   void *data;
   struct node *next;
};


//creates a new node with item
struct node *newNode(void *item);
