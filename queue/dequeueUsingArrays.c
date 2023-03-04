// DOUBLE ENDED QUEUE USING ARRAY
// INSERT AND DELETE AT BOTH ENDS OF THE QUEUE

#include <stdio.h>
#define N 10

int Queue[N];
int front=-1;
int rear=-1;
int count = 0;

int isEmpty(){
    return front==-1;
}

int isFull(){
    return count == N;
}

void enqueueFront(int value){
    if (isFull()){
        printf("The queue is full!\n");
        return;
    }
    if (front == -1){
        front = rear = N/2;
        Queue[rear] = value;
    }
    else{
        if (front==0)
            front = N-1;
        else
            front = front-1;
        Queue[front] = value;
    }
    count ++;
}

void enqueueRear(int value){
    if (isFull()){
        printf("The queue is full!\n");
        return;
    }
    if (front == -1){
        front = rear = N/2;
        Queue[rear] = value;
    }
    else{
        rear = (rear+1)%N;
        Queue[rear] = value;
    }
    count ++;
}

void dequeueFront(){
    if (isEmpty()){
        printf("The queue is empty!\n");
        return;
    }
    int x = Queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front+1)%N;
    printf("%d is removed\n",x);
    count--;
}

void dequeueRear(){
    if (isEmpty()){
        printf("The queue is empty!\n");
        return;
    }
    int x = Queue[rear];
    if (front == rear){
        front = rear = -1;
    }
    else{
        if (rear==0)
            rear = N-1;
        else
            rear--;
    }
    printf("%d is removed\n",x);
    count--;
}

void displayQueue(){
    if (isEmpty()){
        printf("The Queue is Empty\n");
        return;
    }
    printf("QUEUE\n");
    for(int i = 0;i<count;i++)
        printf("%d ",Queue[(front+i)%N]);
    printf("\n");
}


void main(){
    int a,n=-1;
    printf("dequeue using array\n");
    printf("Operations\n");
    printf("1. Insert elements to the Front of the queue\n");
    printf("2. Insert elements to the Rear of the queue\n");
    printf("3. Delete elements from the Front of the queue\n");
    printf("4. Delete elements from the Rear of the queue\n");
    printf("5. Display the queue\n");
    printf("6. Exit\n");
    int flag = 1;
    while(flag!=0){
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch (n){

            case 1:
                printf("Enter the number: ");
                scanf("%d",&a);
                enqueueFront(a);
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d",&a);
                enqueueRear(a);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                displayQueue();
                break;
            case 6:
                printf("You are out of the program\n");
                flag = 0;
                break;
            default:
                printf("Enter a valid input\n");
                break;
        }
    }
}

