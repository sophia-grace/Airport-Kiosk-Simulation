//   File:          List.c
//   Purpose:       The linked list's functionalities.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "List.h"


// Creates a new empty list
List *newList() {
  List *L = malloc(sizeof(List));
  L->head = NULL;
  L->tail = NULL;
  L->size = 0;
  return L;
} // newList()


// Returns the size of list-l
int size(const List *l) {
   return l->size;
} // size()


// is the list-l empty?
int empty(const List *l) {
   return l->size == 0;
} // empty()


// removes all items from list-l
void clear(List *l) {
   struct node *n = l->head;
   struct node *nxt;
   while (n != NULL) {
      nxt = n->next;
      //free(n->data);
      free(n);
      n = nxt;
   }
   l->head = NULL;
   l->tail = NULL;
   l->size = 0;
} // clear()


// Add item at end of list-l
void add(List *l, void *item) {
   struct node *n= newNode(item);

   if (l->size == 0) {
     l->head = n;
     l->tail = n;
   }
   else {
      l->tail->next = n;
      l->tail = n;
   }
   l->size++;
} // add()


// Returns item at index in list-l
void* get(const List *l, int index) {

   if (index < 0 || index >= l->size) {
      printf("Error: List index out of bounds %d. Exiting!\n", index);
      exit(EXIT_FAILURE);
   }

   struct node *n=l->head;
   for (int i=0; i < index; i++)
      n = n->next;
   return n->data;
} // get()


// Does list-l have item? Use compare() to check.
void *contains(const List *l, void *item, int (*comp)(const void *, const void *)) {
   struct node *n = l->head;
   while (n != NULL) {
     //in our case, compare the Airport code with the user's input
      if (comp(n->data, item)) {

         return n->data;
       }
      n = n->next;
   }
   return NULL;
} // contains()


//prints contents of list
void print(const List *l) {
   struct node *n = l->head;
   printf("L(%d) = ", l->size);
   while (n != NULL) {
      int *d = n->data;
      printf("%d ", *d);
      n = n->next;
   }
   printf("\n");
} // print()


void *removeItem(List *l, int index) {    // Remove item at index and return it

   if (index < 0 || index >= l->size) {
      printf("Error: List index out of bounds %d. Exiting!\n", index);
      exit(EXIT_FAILURE);
   }

   void* item;    // item removed
   if (index == 0) {    // removing the first item
       item = l->head->data;
       if (l->size == 1) { // from a list with 1 item
         free(l->head);
         l->head = l->tail = NULL;
       }
       else {           // from a list with >1 items
          struct node *n = l->head;
          l->head = n->next;
          n->next = NULL;
          free(n);
       }
   }
   else {       // List has >1 item, go to the node before it
      struct node *n = l->head;
      for (int i=0; i < index-1; i++)
         n = n->next;
      item = n->next->data;
      if (index == l->size-1) {  // Removing the last item
         l->tail = n;
         free(n->next);
         l->tail->next = NULL;
      }
      else {    // Not the last item, but something in between...
         struct node *r = n->next;      // node to be removed
         n->next = r->next;
         free(r);
      }
   }
   l->size--;
   return item;
} // removeItem()
