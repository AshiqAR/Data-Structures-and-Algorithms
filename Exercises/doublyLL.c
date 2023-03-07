// Doubly Linked List Implementation

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* getNode(){
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    if(p==NULL)
        printf("Error in allocating memory\n");
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertBeg(){
    if(head==NULL){
        head = getNode();
        tail = getNode();
        printf("Enter the value: ");
        scanf("%d",&head->data);
        tail = head;
        head->next = NULL;
        tail->next = NULL;
        head->prev = NULL;
        tail->prev = NULL;

        return ;
    }

    struct Node* newNode = getNode();
    printf("Enter the value: ");
    scanf("%d",&newNode->data);

    newNode->next = head;
    head->prev = newNode;

    head = newNode;
    return ;
}

void insertEnd(){
    if(tail== NULL){
        head = getNode();
        tail = getNode();
        printf("Enter the value: ");
        scanf("%d",&tail->data);
        head = tail;
        head->next = NULL;
        tail->next = NULL;
        head->prev = NULL;
        tail->prev = NULL;

        return ;
    }
    struct Node* newNode = getNode();
    printf("Enter the value: ");
    scanf("%d",&newNode->data);

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return ;
}

void insertAt(int n){
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct Node* currNode = head;

    while(currNode != NULL){
        if(currNode->data == n){
            struct Node* newNode = getNode();
            printf("Enter the value: ");
            scanf("%d",&newNode->data);

            newNode->next = currNode->next;
            if(currNode->next!=NULL)
                currNode->next->prev = newNode;
            
            currNode->next = newNode;
            newNode->prev = currNode;
            return;
        }
        currNode = currNode->next;
    }
    printf("There is no node with the entered data\n");
}

void delete(){
    if(head == NULL){
        return;
    }
    int n;
    printf("Enter the data of the Node to be deleted: ");
    scanf("%d",&n);
    struct Node* currNode = head;
    while(currNode!=NULL){
        if(currNode->data==n){
            struct Node* nextNode = currNode->next;
            struct Node* prevNode = currNode->prev;
            if(nextNode!=NULL && prevNode!=NULL){
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                free(currNode);
            }
            else if(nextNode==NULL && prevNode==NULL){
                head = NULL;
                tail = NULL;
            }
            else if(nextNode==NULL){
                tail = tail->prev;
                tail->next = NULL;
            }
            else if(prevNode==NULL){
                head = head->next;
                head->prev = NULL;
            }
        }
        currNode = currNode->next;
    }
}

void display(){
    struct Node* currNode = getNode();

    if(head == NULL){
        printf("Linked list is empty\n");
        return ;
    }
    printf("Linked List\n");
    currNode = head;
    while(currNode!=NULL){
        printf("%d =>",currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n\n");
}

void main(){
    printf("Doubly Linked List\n");
    printf("MENU\n");
    printf("1. Insert at begining\n");
    printf("2. Insert at End\n");
    printf("3. Insert at after a specified position\n");
    printf("4. Delete a node\n");
    printf("5. Exit\n");
    int choice,n;

    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

        case 1:
            insertBeg();
            display();
            break;
        case 2:
            insertEnd();
            display();
            break;
        case 3:
            printf("Enter the node after which to be inserted: ");
            scanf("%d",&n);
            insertAt(n);
            display();
            break;
        case 4:
            delete();
            display();
            break;
        case 5:
            printf("You are out of the proram\n");
            break;
        default:
            printf("Enter a valid input\n");
            break;
            
        }
    }
    while(choice!=5);
}
