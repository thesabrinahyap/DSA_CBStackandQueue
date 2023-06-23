#include<stdbool.h>

#ifndef CB_STACK_QUEUE_H
#define CB_STACK_QUEUE_H

#define MAX 20
#define EMPTY 9999
typedef char String[20];

typedef struct{
	int date;
	int month;
	int year;
}Date;

typedef struct{
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
}Product;

typedef struct{
	Product items;
	int link;
}SType;

typedef struct{
	SType data[MAX];
	int avail;
}VirtualSpace;

typedef int StackList;

typedef struct{
	int front;
	int rear;
}Queue;

//Helper Functions:
Date createDate(int date, int month, int year);
Product createProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp);
void initVirtualSpace(VirtualSpace *VS);
int allocSpace(VirtualSpace *VS);
void deallocSpace(VirtualSpace *VS, int index);

// Stack Operations:
void initStack(StackList *S);
bool isEmpty(StackList S);
bool isFull (StackList S);
void push(VirtualSpace *VS,StackList *S,Product prod);
void pop(VirtualSpace *VS,StackList *S,);
void displayStack(VirtualSpace VS, StackList S);
void visualizeStack(VirtualSpace VS, StackList S);

//Queue Operations:
void initQueue(Queue *q);
bool isEmpty(Queue q);
bool isFull (Queue q);
void enqueue(VirtualSpace *VS, Queue *q, Product prod);
void dequeue(VirtualSpace *VS, Queue q);
void displayQueue(VirtualSpace VS, Queue q);
void visualizeQueue(VirtualSpace VS, Queue q);
#endif

