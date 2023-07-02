#ifndef CB_STACK_QUEUE_H
#define CB_STACK_QUEUE_H

#include<stdbool.h>

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
char* convertToMonth(int month);
Date createDate(int date, int month, int year);
Product createProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp);
void initVirtualSpace(VirtualSpace *VS);
int allocSpace(VirtualSpace *VS);
void deallocSpace(VirtualSpace *VS, int index);
void visualize(VirtualSpace VS);

//Stack Operations
void initStack(StackList *S);
bool isEmpty(StackList S);
bool isFull(StackList S);
void push(VirtualSpace *VS, StackList *S, Product prod);
void pop(VirtualSpace *VS, StackList *S);
Product peek(VirtualSpace VS, StackList S);
void displayStack(VirtualSpace VS, StackList S);

//Queue Operations
void initQueue(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(VirtualSpace *VS, Queue *Q, Product prod);
void dequeue(VirtualSpace *VS, Queue *Q);
Product front(VirtualSpace VS, Queue Q);
void displayQueue(VirtualSpace VS, Queue Q);

#endif
