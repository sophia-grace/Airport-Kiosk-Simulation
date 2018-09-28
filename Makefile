##MAKEFILE


##THE CUSTOMER FILES
testCustomer: testCustomer.o customer.h customer.o
	gcc -o testCustomer testCustomer.o customer.o

testCustomer.o: testCustomer.c customer.h
	gcc -c testCustomer.c

customer.o: customer.h customer.c
	gcc -c customer.c



##THE KIOSK FILES
testKiosk: testKiosk.o kiosk.o customer.o customer.h
	gcc -o testKiosk testKiosk.o kiosk.o customer.o


testKiosk.o: testKiosk.c kiosk.h customer.h
	gcc -c testKiosk.c


kiosk.o: kiosk.c kiosk.h customer.h
	gcc -c kiosk.c



##THE QUEUE FILES
testQueue: testQueue.o Queue.o List.o node.o Queue.h List.h node.h
	gcc -o testQueue testQueue.o Queue.o List.o node.o


testQueue.o: testQueue.c Queue.h List.h node.h
	gcc -c testQueue.c


Queue.o: Queue.c Queue.h List.h node.h
	gcc -c Queue.c


List.o: List.c List.h node.h
	gcc -c List.c


node.o: node.c node.h
	gcc -c node.c




##THE DES FILES
des: des.o kiosk.o customer.o Queue.o List.o node.o
	gcc -o des des.o kiosk.o customer.o Queue.o List.o node.o


des.o: des.c kiosk.h customer.h Queue.h List.h node.h
	gcc -c des.c




clean:
	rm *.o testCustomer testKiosk testQueue
