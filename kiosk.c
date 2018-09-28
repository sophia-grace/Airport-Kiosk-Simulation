//   File:          kiosk.c
//   Purpose:       The source file for kiosk.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include <stdio.h>
#include <stdlib.h>
#include "kiosk.h"


static int count = 0;
static int nServed = 0;


//prototypes
char * genKioskId(void);


Kiosk * newKiosk() {
  Kiosk *k = malloc(sizeof(Kiosk));
  k -> id = genKioskId();
//  printf("k id: %s\n", k -> id);
  k -> nowServing = NULL;
  k -> timeRemaining = 0;
} // newKiosk


char * genKioskId() {
  count++;
  char *result = malloc(5 * sizeof(char));
  sprintf(result, "K%d", count);
  return result;
} // genKioskId()


//Accessors
char * getKioskId(const Kiosk *k) {
  return k->id;
} // getKioskId()


Customer * getCustomer(const Kiosk *k) {
  return k -> nowServing;
} // getCustomer()

int getTimeRemaining(const Kiosk *k) {
  return k->timeRemaining;
}


//Functionality
void assignCustomer(Kiosk *k, Customer *c) {
  k -> nowServing = c;
  //assign amount of time to serve
  k -> timeRemaining = c -> serviceTime;
} // assignCustomer()


void tick(Kiosk *k) {
  if(k -> nowServing) { //make sure k actually has a customer
    k -> timeRemaining--; //perform 1 minute of service to customer by
                          //decrementing time left to serve by 1
    if(k -> timeRemaining == 0) {
      free(k -> nowServing); //get rid of mem leak
      k -> nowServing = NULL; //reset this kiosk to no customer
      nServed++; //another customer has been served
    }
  }
} // tick()


int busy(const Kiosk *k) { //return 1 if serving, return 0 if not serving
  return (k -> nowServing != NULL);
} // busy()


int getNServed() { //returns total# of Customers served so far in simulation
  return nServed;
} //getNServed()


//Print Representation
char *kioskToString(const Kiosk *k) {
  char *result = malloc(30 * sizeof(char)); //make 30 just to be safe
  if(getCustomer(k) == NULL) {
    sprintf(result, "%s: <NO CUSTOMER IS CURRENTLY BEING SERVED> [%d]",
            getKioskId(k), getTimeRemaining(k));
  }
  else {
    sprintf(result, "%s: <%s: %d, %d> [%d]", getKioskId(k),
            getCustId(getCustomer(k)), getArrivalTime(getCustomer(k)),
            getServiceTime(getCustomer(k)), getTimeRemaining(k));
  }
  return result;
} // kioskToString()
