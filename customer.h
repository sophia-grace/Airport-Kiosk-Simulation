//   File:          customer.h
//   Purpose:       The header file for customer.
//   Author:        Sophia Trump
//   Date:          30 April 2018


typedef struct {
  char * id; //id is for form 'C' + # (e.g., C23, C9, etc.)
  int arrivalTime;
  int serviceTime;
} Customer;


//Given arrival time, create a new customer
Customer *newCustomer(int at);
  //Creates a new customer, with an ID (up to 4 chars), whose
  //arrival time is arrTime, and service time is between 5-8 minutes (random)


//Accessors
char *getCustId(const Customer *c);
int getArrivalTime(const Customer *c);
int getServiceTime(const Customer *c);


//Print representation
char *custToString(const Customer *c);
