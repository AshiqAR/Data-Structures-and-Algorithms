#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct node* top = NULL;

void push(int n){
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = top;
    newNode->val = n;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Stack is empty!!\n");
        return ;
    }
    printf("%d deleted\n",top->val);
    top = top->next;
}

void displayStack(){
    if(top == NULL){
        printf("Stack is empty!!\n");
        return;
    }
    struct node* currNode = top;
    printf("Stack\n");
    while(currNode != NULL){
        printf("%d\n",currNode->val);
        currNode = currNode->next;
    }
    printf("\n");
}

void main(){
    int x,choice;
    printf("Stack using Linked List\n");
    printf("1. Push an element to stack\n");
    printf("2. Pop an element from stack\n");
    printf("3. Display elements of stack\n");
    printf("4. Exit\n");
    do{
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element : ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
        }
        printf("\n");
    }while(choice<4);
}
