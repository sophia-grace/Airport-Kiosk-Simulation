//   File:          kiosk.h
//   Purpose:       The header file for kiosk.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include "customer.h"


typedef struct {
  char *id;
  Customer *nowServing; //Customer this kiosk is serving (or NULL)
  int timeRemaining; //How much time still remains to serve the customer being
                    //served
} Kiosk;


Kiosk *newKiosk(); //Creaet a new Kiosk: K#


//Accessors
char *getKioskId(const Kiosk *k); // Returns kiosk ID
Customer *getCustomer(const Kiosk *k); // Returns the customer beting served
                                      //(or NULL)
int getTimeRemaining(const Kiosk *k); //Returns time remaining for k

//Functionality
void assignCustomer(Kiosk *k, Customer *c); // Assigns customer, c to kiosk, k
void tick(Kiosk *k); //Performs 1 minute of service to customer (if serving one)
                     //if customer is completely served, it resets this kiosk
                     //(to no customers)
int busy(const Kiosk *k); //Is kiosk, k serving a customer?
int getNServed(); //returns total# of customers served so far in simulation


//Print representation
char *kioskToString(const Kiosk *k);
