// CIRCULAR QUEUE USING ARRAY

#include <stdio.h>
#define N 5

int Queue[N];
int front=-1;
int rear=-1;
int count = 0;

void enqueue(int value){
    if (count == N){
        printf("The queue is full!\n");
        return;
    }
    if (front == -1){
        front = 0;
        rear = 0;
        Queue[rear] = value;
    }
    else{
        rear = (rear+1)%N;
        Queue[rear] = value;
    }
    count ++;
}

void dequeue(){
    if (front == -1){
        printf("The queue is empty!\n");
        return;
    }
    int x= Queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front+1)%N;
    printf("%d is removed\n",x);
    count--;
}

void displayQueue(){
    if (front == -1){
        printf("The Queue is Empty\n");
        return;
    }
    printf("QUEUE \n");
    for (int i=0;i<count;i++)
        printf("%d ",Queue[(i+front)%N]);
    printf("\n");
}


void main(){
    int a,choice;
    printf("Circular Queue Operations\n");
    printf("MENU\n");
    printf("1. Insert an element(enqueue)\n");
    printf("2. Delete an element(dequeue)\n");
    printf("3. Display the entire Queue\n");
    printf("4. Exit\n");

    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){

            case 1:
                printf("Enter the number: ");
                scanf("%d",&a);
                enqueue(a);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("You are out of the program\n");
                break;
            default:
                printf("Enter a valid input\n");
                break;
        }
    }while(choice != 4);
}
