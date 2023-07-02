#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"CBStackQueue.h"

//Helper Functions:


//for convert to month, this must be made more efficient pa
char* convertToMonth(int month){
	switch(month){
		case 1: return "January"; break;
		case 2: return "February"; break;
		case 3: return "March"; break;
		case 4: return "April"; break;
		case 5: return "May"; break;
		case 6: return "June"; break;
		case 7: return "July"; break;
		case 8: return "August"; break;
		case 9: return "September"; break;
		case 10: return "October"; break;
		case 11: return "November"; break;
		case 12: return "December"; break;
		default: return "NAURRR!!!";
	}
}
Date createDate(int date, int month, int year){
	Date d;
	
	d.date = date;
	d.month = month;
	d.year = year;
	
	return d;
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
		VS->data[ctr].items = createProduct(0, " ", 0, 0.00, (0,0,0));
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
	if(index != -1 && index < MAX){
		VS->data[index].link = VS->avail;
		VS->data[index].items = createProduct(0," ", 0,0.00,(0,0,0));
		VS->avail = index;
	}
}

void visualize(VirtualSpace VS){
	printf("----- VIRTUAL HEAP -----\n\n");
	printf("%5s | %5s | %-5s | %5s | %5s | %-18s |%5s\n", "INDEX", "PRODUCT ID", "PRODUCT NAME", "AVAILABLE QUANTITY", "PRICE", "EXPIRATION DATE", "LINK");
	printf("--------------------------------------------------------------------------------------------\n");
	
	int ctr;
	for(ctr = 0; ctr < MAX; ctr++){
		printf("%5d | ", ctr);
		
		(VS.data[ctr].items.prodID) ? printf("%10d | ", VS.data[ctr].items.prodID) : printf("%10s | ", " ");
		
		(strlen(VS.data[ctr].items.prodName) != 0 ) ? printf("%-12s | ", VS.data[ctr].items.prodName) : printf("%-12s | ", " ");
		
		printf("%-18d | ", VS.data[ctr].items.prodQty);
		
		printf("%-5.2lf | ", VS.data[ctr].items.prodPrice);
		
		printf("%-3d %-8s %-5d | ", VS.data[ctr].items.prodExp.date, convertToMonth(VS.data[ctr].items.prodExp.month), VS.data[ctr].items.prodExp.year);
		
		printf("%3d\n", VS.data[ctr].link);		
	}
	
	printf("--------------------------------------------------------------------------------------------\n");
	printf("AVAILABLE: %d\n", VS.avail);
	
	printf("\n\n");
}

//Stack Operations
void initStack(StackList *S){
	*S = -1;
}
bool isEmpty(StackList S){
	return(S == -1)? true: false;
}

bool isFull(StackList S){
	return(S == MAX-1)? true: false;
}

void push(VirtualSpace *VS, StackList *S, Product prod){
	if(!isFull(*S)){
		VS->data[++(*S)] = prod;
	}
}

void pop(VirtualSpace *VS, StackList *S){
	if(!isEmpty(*S)){
		--(*S);
	}
}
Product peek(VirtualSpace VS, StackList S){
	return VS.data[S].items;
}
void displayStack(VirtualSpace VS, StackList S){
	StackList temp;
	Product prod;
	
	initStack(&temp);
	
	while(S != -1){
		prod = peek(VS, Stack);
		pop(&VS, &S);
		push(&VS, &temp, prod);
	}
	
	printf("----- STACK TABLE -----\n\n");
	printf("%5s | %-5s | %5s | %5s | %-18s\n", "PRODUCT ID", "PRODUCT NAME", "AVAILABLE QUANTITY", "PRICE", "EXPIRATION DATE");
	printf("----------------------------------------------------------------------------------------\n");
	while(temp != -1){
		prod = peek(VS, temp);
		
		printf("%10d | ", prod.prodID);
		printf("%-12s | ", prod.prodName);
		printf("%-18d | ", prod.prodQty);
		
		printf("%-5.2lf | ", prod.prodPrice);
		
		printf("%-2d %s %d\n", prod.prodExp.date, convertMonth(prod.prodExp.month), prod.prodExp.year);

		
		pop(&VS, &temp);
		
		push(&VS, &S, prod);
	}
	
	printf("----------------------------------------------------------------------------------------\n\n");

}


//Queue Operations
void initQueue(Queue *Q){
	Q->front = -1;
	Q->rear = -1;
}
bool isEmpty(Queue Q){
	return (Q.rear + 1) % MAX == Q.front;
}
bool isFull(Queue Q){
	return Q.rear;
}
void enqueue(VirtualSpace *VS, Queue *Q, Product prod){
	if(!isFull(*Q)){
		Q->rear = (Q->rear+1) % MAX;
		VS->data[Q->rear] = prod;
	}
}
void dequeue(VirtualSpace *VS, Queue *Q){
	if(!isEmpty(*Q)){
		Q->front = (Q->front+1) % MAX;
	}
}

Product front(VirtualSpace VS, Queue Q){
	return VS.data[Q.front].items;
}
void displayQueue(VirtualSpace VS, Queue Q){
	Product prod;
	
	printf("----- QUEUE TABLE -----\n\n");
	printf("%5s | %-5s | %5s | %5s | %-18s\n", "PRODUCT ID", "PRODUCT NAME", "AVAILABLE QUANTITY", "PRICE", "EXPIRATION DATE");
	printf("----------------------------------------------------------------------------------------\n");
	while(Q.front != -1){
		prod = front(VS, Q);
		
		printf("%10d | ", prod.prodID);
		printf("%-12s | ", prod.prodName);
		printf("%-18d | ", prod.prodQty);
		
		printf("%-5.2lf | ", prod.prodPrice);
		
		printf("%-2d %s %d\n", prod.prodExp.date, convertToMonth(prod.prodExp.month), prod.prodExp.year);
		
		dequeue(&VS, &Q);
	}
	printf("----------------------------------------------------------------------------------------\n\n");

}


