// QUEUE USING ARRAYS

#include <stdio.h>
#define N 15

int Queue[N];
int front=-1,rear=-1;

void enqueue(int value){
    if (rear == N-1){
        printf("Queue is full!\n");
        return;
    }
    if (front == -1){
        front = 0;
        rear = 0;
        Queue[rear] = value;
    }
    else{
        rear = rear+1;
        Queue[rear] = value;
    }
}

void dequeue(){
    if (front == -1){
        printf("Queue is empty!\n");
        return;
    }
    printf("%d deleted\n",Queue[front]);
    if (front == rear){
        front = rear = -1;
    }
    else{
        Queue[front]=-1;
        front += 1;
    }
}

void displayQueue(){
    if (front == -1){
        printf("Queue is Empty\n");
        return;
    }
    printf("QUEUE\n");
    for(int i = front;i<=rear;i++)
        printf("%d ",Queue[i]);
    printf("\n");
}

void main(){
    int a,choice;
    printf("Queue Using Arrays\n");
    printf("Operations\n");
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
                printf("Enter a valid input!!\n");
                break;
        }
    }while(choice != 4);
}
