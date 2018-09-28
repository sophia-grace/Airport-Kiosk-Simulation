//   File:          des.c
//   Purpose:       Simulation of customers arriving to kiosks.
//                  Prints the average queue length over a specified amt of time.
//   Author:        Sophia Trump
//   Date:          30 April 2018




//libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "kiosk.h"
#include "Queue.h"



//prototypes
int arrivals();
void simulate(int m, int nk);



int main(int argc, char * argv[]) {

  srand(time(NULL));

  if(argc != 3) {
    printf("Too few arguments.\n");
    exit(1);
  }

  int duration = atoi(argv[1]); //convert ascii string to integer
  int numCust = atoi(argv[2]);

  simulate(duration, numCust);

  return(0);
} // main()




int arrivals() { //Returns the no. of customers that arrived (any value [0...3])
  return rand()%4;
} // arrival()



void simulate(int m, int nk) { //simulate for m minutes on k kiosks
  //used to keep track of the avg queue length during simulation
  int queueLength = 0; //total of all queue lengths during simulation

  //create nk kiosks
  Kiosk *kiosks[nk];
  for(int i = 0; i < nk; i++) {
    kiosks[i] = newKiosk();
  }

  #ifdef DEBUG
    printf("There are %d kiosks.\n", nk);

    printf("[ "); // let us print out each kiosk...

    for(int i = 0; i < nk; i++){
      printf("%s ", kioskToString(kiosks[i]));
    }
    printf(" ]\n");

  #endif


  //create a queue of Customers
  Queue *checkInQueue;
  checkInQueue = newQueue();

  int nc = 0; //total customers arrived
  //for each minute...
  for(int t = 1; t <= m; t++) {
    //n Customers arrive
    int n = arrivals();


    //create and add each customer to the queue
    for(int i = 1; i <= n; i++) {
      Customer *c = newCustomer(t);
      insertQ(checkInQueue, c);
      nc++;
    }




    //check for idle kiosks and assign customers to them
    for(int k = 0; k < nk; k++) {
      if(!busy(kiosks[k]) && !emptyQ(checkInQueue)) {
        Customer *assignMe = removeQ(checkInQueue);
        assignCustomer(kiosks[k], assignMe);
      }
      //each kiosk serves a customer assigned to them for 1 minute
      tick(kiosks[k]);
    }
    queueLength += sizeQ(checkInQueue);

    #ifdef DEBUG
      printf("At time %d there are %d customers on Q.\n", t,
            sizeQ(checkInQueue));

    #endif

    #ifdef DEBUG
      printf("[ "); //print out status of all kiosks
      for(int i = 0; i < nk; i++) {
        printf("%s ", kioskToString(kiosks[i]));
      }
      printf(" ]\n");

    #endif
  }


    //Metrics
    printf("\n");
    printf("Simulation: %d minutes, with %d kiosks\n", m, nk);
    printf("%d customers arrived\n", nc);
    printf("%d customers served.\n", getNServed());
    printf("Average queue length: %0.1f\n", ((float)(queueLength)/(float)m));
    printf("\n");

} // simulate()
