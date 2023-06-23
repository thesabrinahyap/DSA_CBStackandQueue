#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"CBStackQueue.h"

//Helper Functions:
Date createDate(int date, int month, int year){
	Date d;
	
	d.date = date;
	d.month = month;
	d.year = year;
	
	return Date;
}
Product createProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp){
	Product p;
	
	p.prodID = prodID;
	strcpy(p.prodName, prodName);
	p.prodQty = prodQty;
	p.prodPrice = prodPrice;
	p.prodExp = prodExp;
	
	return p;
	
}
void initVirtualSpace(VirtualSpace *VS){
	int ctr;
	
	for(ctr=0; ctr<MAX; ctr++){
		VS->data[ctr].items = createProduct(0, " ", 0, 0.00, (0, 0, 0));
		VS->data[ctr].link = ctr-1;
	}
	
	VS->avail = MAX-1;
}

int allocSpace(VirtualSpace *VS){
	int retVal = VS->avail;
	
	if(retVal != -1){
		VS->avail = VS->data[VS->avail].link;
	}
	
	return retVal;
}
void deallocSpace(VirtualSpace *VS, int index){
	if(index != -1 && index< MAX){
		VS->data[index].link = VS->avail;
		VS->data[index].items = createProduct(0, " ", 0, 0.00, (0, 0, 0));
		VS->avail = index;
	}
}

// Stack Operations:
void initStack(StackList *S){
	*S = -1;
}
bool isEmpty(StackList S){
	return(S == -1)? true: false;
}
bool isFull (StackList S){
	return(S == MAX-1)? true: false;
}
void push(VirtualSpace *VS,StackList *S,Product prod){
	if(!(isFull(*S))){
		VS->data[++(*S)] = prod;
	}
}
void pop(VirtualSpace *VS,StackList *S){
	if(!(isEmpty(*S))){
		--(*S);
	}
}
void displayStack(VirtualSpace VS, StackList S);
void visualizeStack(VirtualSpace VS, StackList S);

//Queue Operations:
void initQueue(Queue *q){
	q->front = -1;
	q->rear = -1;
}
bool isEmpty(Queue q){
	return (q.rear + 1) % MAX == q.front;
}
bool isFull (Queue q){
	return (q.rear)
}
void enqueue(VirtualSpace *VS, Queue *q, Product prod){
	if(!isFull(*q)){
		q->rear = (q->rear+1)%MAX;
		VS->data[q->rear] = prod;
	}
}
void dequeue(VirtualSpace *VS, Queue q){
	if(!isEmpty(*q)){
		q->front = (q->front + 1) % MAX;
	}
}
void displayQueue(VirtualSpace VS, Queue q);
void visualizeQueue(VirtualSpace VS, Queue q);

#endif

