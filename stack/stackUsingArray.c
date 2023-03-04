// IMPLEMENTING STACK USING ARRAY
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int n){
    if(top == MAX-1){
        printf("Stack is full!!\n");
        return;
    }
    top++;
    stack[top] = n;
}

void pop(){
    if(top == -1){
        printf("Stack is empty!!\n");
        return;
    }
    printf("%d deleted\n",stack[top]);
    top -= 1;;
}

void displayStack(){
    if (top==-1){
        printf("Stack is empty!!\n");
    }else{
        printf("Stack: \n");
        for (int i=top;i!=-1;i--){
            printf("%d\n",stack[i]);
        }
    }
    printf("\n");
}

void main(){
    int a,choice;

    printf("Stack Using Array\n");
    printf("OPERATIONS  \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display Stack\n");
    printf("4. Exit\n");
    int flag = 1;
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the number: ");
                scanf("%d",&a);
                push(a);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("You are out of the program\n");
                break;
            default:
                printf("Enter a valid input!!\n");
                break;
        }
    }while(choice != 4);
}