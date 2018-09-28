//   File:          customer.c
//   Purpose:       The source file for customer.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include <stdio.h>
#include <stdlib.h>


#include "customer.h"


static int count = 0;


//prototypes
char*genCustId(void);


Customer *newCustomer(int arrTime) {
  Customer *c = malloc(sizeof(Customer));
  c -> arrivalTime = arrTime;
  c -> serviceTime = 5 + (rand() % 4);
  c -> id = genCustId();
  return c;
} // newCustomer()


char *genCustId() {
  count++;
  char *id = malloc(5 * sizeof(char)); //Max 4-letters for ID +1 for '\0'
  sprintf(id, "C%d", count);
  return id;
} // genCustId()


//Accessors
char *getCustId(const Customer *c) {
  return c -> id;
} // getCustId()


int getArrivalTime(const Customer *c) {
  return c -> arrivalTime;
} // getArrivalTime()


int getServiceTime(const Customer *c) {
  return c -> serviceTime;
} // getServiceTime()


//Print representation
char *custToString(const Customer *c) {
  char * result = malloc(20 * sizeof(char));
  sprintf(result, "<%s: %d, %d>", getCustId(c), getArrivalTime(c),
          getServiceTime(c));
  return result;
} // custToString()
