//   File:          testKiosk.c
//   Purpose:       Tests the implementation of kiosk.
//   Author:        Sophia Trump
//   Date:          30 April 2018


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "kiosk.h"

#define NUM_KIOSKS 5
#define NUM_MINUTES 60

int main(void) {
  srand(time(NULL));
  int mins = NUM_MINUTES;

  Kiosk *ks[NUM_KIOSKS];
  for(int i = 0; i < NUM_KIOSKS; i++) { //initialize each kiosk
    ks[i] = newKiosk();
  }

  //test ticks
  int t = 23;
  for(int i = 0; i < mins; i++) { //test simulation for 60 minutes
    for(int j = 0; j < NUM_KIOSKS; j++) {
      if(busy(ks[j]) == 0) { //assign a new customer if no customer
                                       //is there
        assignCustomer(ks[j], newCustomer(t));
      }
      tick(ks[j]); //perform a tick for each kiosk
    }
    t++; //increment the arrival time for customers
  }


  for(int i = 0; i < 5; i++) {
    printf("<%s: %d>\n", getKioskId(ks[i]), getTimeRemaining(ks[i]));
    printf("%s\n", kioskToString(ks[i]));
  }

  printf("%d customers were served in %d minutes.\n",
        getNServed(), mins);

  return(0);
} // main()
