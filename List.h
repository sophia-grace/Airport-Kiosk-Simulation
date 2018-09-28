//   File:          List.h
//   Purpose:       The header file for the linked list.
//                  in a linked list.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include "node.h"

typedef struct {
   int size;
   struct node *head;
   struct node *tail;
} List;


// Creates a new empty list
List *newList();
// Returns the size of list-l
int size(const List *l);
// is the list-l empty?
int empty(const List *l);
// removes all items from list-l
void clear(List *l);
// Add item at end of list-l
void add(List *l, void *item);
// Returns item at index in list-l
void *get(const List *L, int index);
// Does list-l have item? Use compare() to check
void *contains(const List *l, void *item,
                int (*comp)(const void *, const void *));
//remove item from l at index. return the removed index
void *removeItem(List *l, int index);

// prints contents of list
void print(const List *l);
