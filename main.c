#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "CBStackQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualSpace VS;
	StackList s;
	Queue q;
	Product prod;
	String menuOptions[11] = {"Visualize", "Initialize", "Push", "Pop", "Peek", "Display", "Initialize", "Enqueue", "Dequeue", "Front", "Display"};
	bool checker;	
	int ctr, choice;
	
	String name;
	int id, qty, date, month, year;
	char* newline;
	double price;
		
	printf("----- W E L C O M E -----\n\n");
	system("pause");
	system("cls");
	
	printf("----- INITIALIZING VIRTUAL HEAP -----\n\n");
	system("pause");
	system("cls");
	initVSpace(&VS);
	printf("----- VIRTUAL HEAP INITIALIZED -----\n\n");
	system("pause");
	
	do{
		system("cls");
		printf("----- MAIN MENU -----\n\n");
		for(ctr = 0; ctr < 11; ctr++){
			if(ctr == 0){
				printf("< Virtual Heap >\n");
			} else if(ctr == 1){
				printf("< Stack Structure >\n");
			} else if(ctr == 6){
				printf("< Queue Structure >\n");
			}	
			
			printf("[%d] %s\n", ctr+1, menuOptions[ctr]);
			
			if(ctr == 0 || ctr == 5 || ctr == 10) printf("\n\n");
		}
		
		printf("Enter your choice <0 to EXIT>: ");
		scanf("%d", &choice);
		
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		
		switch(choice){
			case 0:
				system("cls");
				printf("----- EXITING SYSTEM -----\n\n");
				system("pause");
				system("cls");
				
				printf("----- GOOD BYE!! -----\n\n");
				
				system("pause");
				
				break;
				
			case 1:
				system("cls");
				printf("----- VISUALIZING VIRTUAL HEAP -----\n\n");
				system("pause");
				printf("\n\n");
				
				visualize(VS);
				
				system("pause");
				
				break;
				
			case 2:
				system("cls");
				printf("----- INITIALIZING STACK -----\n\n");
				system("pause");
				
				initStack(&s);
				printf("\n\n----- STACK INITIALIZED -----\n\n");
				system("pause");
				
				break;
				
			case 3:
				system("cls");
				printf("----- PUSH STACK -----\n\n");
				
				printf("Enter product name: ");
				fgets(name, 20, stdin);
				
				newline = strchr(name, '\n'); 
				if (newline) {  
				    *newline = '\0'; 
				}
				
				printf("\nEnter desired ID number: ");
				scanf("%d", &id);
				printf("\n");
				
				printf("Enter quantity:  ");
				scanf("%d", &qty);
				printf("\n");
				
				printf("Enter price: ");
				scanf("%lf", &price);
				printf("\n\n");
				
				printf("--- EXPIRY DATE ---\n\n");
				printf("Enter month: ");
				scanf("%d", &month);
				printf("\n");
				
				printf("Enter date: ");
				scanf("%d", &date);
				printf("\n");
				
				printf("Enter year: ");
				scanf("%d", &year);
				
				printf("\n\n");
				
				checker = push(&VS, &s, createProduct(id, name, qty, price, createDate(date, month, year)));
				checker ? printf("Stack has been updated\n\n") : printf("Stack is full\n\n");
				
				system("pause");
				
				break;
				
			case 4:
				system("cls");
				printf("----- POPPING STACK -----\n\n");
				
				checker = pop(&VS, &s);
				
				system("pause");
				
				printf("\n\n");
				checker ? printf("Stack has been popped and updated\n\n") : printf("Stack is empty\n\n");
				
				system("pause");
				
				break;
			
			case 5:
				system("cls");
				printf("----- TAKING A PEEK OF THE STACK -----\n\n");
				system("pause");
				
				prod = peek(VS, s);
				printf("\n\nProduct ID%24s-----%5s%d\n", " ", " ", prod.prodID);
				printf("Product Name%22s-----%5s%s\n", " ", " ", prod.prodName);
				printf("Product Available Quantity%8s-----%5s%d\n", " ", " ", prod.prodQty);
				printf("Product Price%21s-----%5sPhp. %.2lf\n", " ", " ", prod.prodPrice);
				printf("Product Expiration Date%11s-----%5s%d %s %d\n\n", " ", " ", prod.prodExp.date, convertToMonth(prod.prodExp.month), prod.prodExp.year);
				
				system("pause");
				
				break;
			
			case 6:
				system("cls");
				printf("----- DISPLAYING STACK -----\n\n");
				system("pause");
				printf("\n\n");
				
				displayStack(VS, s);
				
				system("pause");
				
				break;
				
			case 7:
				system("cls");
				printf("----- INITIALIZING QUEUE -----\n\n");
				system("pause");
				printf("\n\n");
				
				initQueue(&q);
				printf("----- QUEUE INITIALIZED -----\n\n");
				
				system("pause");
				
				break;
				
			case 8:
				system("cls");
				printf("----- ENQUEUE QUEUE -----\n\n");
				
				printf("Enter product name: ");
				fgets(name, 20, stdin);
				
				newline = strchr(name, '\n'); 
				if (newline) {  
				    *newline = '\0'; 
				}
				
				printf("\nEnter desired ID number: ");
				scanf("%d", &id);
				printf("\n");
				
				printf("Enter quantity:  ");
				scanf("%d", &qty);
				printf("\n");
				
				printf("Enter price: ");
				scanf("%lf", &price);
				printf("\n\n");
				
				printf("--- EXPIRY DATE ---\n\n");
				printf("Enter month: ");
				scanf("%d", &month);
				printf("\n");
				
				printf("Enter date: ");
				scanf("%d", &date);
				printf("\n");
				
				printf("Enter year: ");
				scanf("%d", &year);
				
				printf("\n\n");
				
				checker = enqueue(&VS, &q, createProduct(id, name, qty, price, createDate(date, month, year)));
				checker ? printf("Queue has been updated\n\n") : printf("Queue is full\n\n");
				
				system("pause");
				
				break;
				
			case 9:
				system("cls");
				printf("----- DEQUEUEING QUEUE -----\n\n");
				
				checker = dequeue(&VS, &q);
				
				system("pause");
				
				printf("\n\n");
				checker ? printf("Queue has been dequeued and updated\n\n") : printf("Queue is empty\n\n");
				
				system("pause");
				
				break;
				
			case 10:
				system("cls");
				printf("----- DISPLAYING THE FRONT OF THE QUEUE -----\n\n");
				system("pause");
				
				prod = front(VS, q);
				printf("\n\nProduct ID%24s-----%5s%d\n", " ", " ", prod.prodID);
				printf("Product Name%22s-----%5s%s\n", " ", " ", prod.prodName);
				printf("Product Available Quantity%8s-----%5s%d\n", " ", " ", prod.prodQty);
				printf("Product Price%21s-----%5sPhp. %.2lf\n", " ", " ", prod.prodPrice);
				printf("Product Expiration Date%11s-----%5s%d %s %d\n\n", " ", " ", prod.prodExp.date, convertToMonth(prod.prodExp.month), prod.prodExp.year);
				
				system("pause");
				
				break;
				
			case 11:
				system("cls");
				printf("----- DISPLAYING QUEUE -----\n\n");
				system("pause");
				printf("\n\n");
				
				displayQueue(VS, q);
				
				system("pause");
				
				
				break;
			
			default: 
				system("cls");
				printf("INVALID CHOICE\n\n");
				system("pause");
		}
	}while(choice != 0);

	
	return 0;
}
