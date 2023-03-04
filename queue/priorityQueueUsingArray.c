// PRIORITY QUEUE USING ARRAYS
// Lower value has higher priority

#include <stdio.h>
#define MAX 10

typedef struct{
    int priority;
    int value;
}PriorityQueue;

PriorityQueue Q[MAX];
int count = 0;
int front = -1;
int rear = -1;

void dequeue(){
    if (count==0){
        printf("Queue is Empty !!\n");
        return;
    }
    printf("value %d with priority %d deleted\n",Q[front].value,Q[front].priority);
    count--;
    front++;
    if(count == 0)
        front = rear = -1;
}

void enqueue(){
    int i,n,p;
    if (count == MAX){
        printf("Queue is Full\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d",&n);
    printf("priority of %d : ",n);
    scanf("%d",&p);

    if(front == -1){
        Q[0].value=n;
        Q[0].priority=p;
        front = rear = 0;
        count++;
        return;
    }
    int index=rear+1;
    for(i=front;i<=rear;i++){
        if(Q[i].priority>p){        //finding the right position according to priority
            index = i;
            break;
        }
    }
    for(i=rear;i>=index;i--){
        Q[i+1].priority=Q[i].priority;      //shifting
        Q[i+1].value=Q[i].value;
    }
    Q[index].value=n;
    Q[index].priority=p;
    rear++;
    count++;
}

void display(){
    if(count==0){
        printf("Queue is empty !!\n");
        return;
    }
    printf("Queue (priority in parenthesis): \n");
    for(int i=front;i<=rear;i++)
        printf("%d(%d) ",Q[i].value, Q[i].priority);
}

void main(){
    int choice;
    printf("Priority Queues\n");
    printf("Operations\n");
    printf("1. Insert into the priority Queue\n");
    printf("2. Delete from the Priority Queue\n");
    printf("3. Display the Priority Queue\n");
    printf("4. Exit\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){

            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Enter a valid input !\n");
                break;
        }
    }while(choice!=4);
}
