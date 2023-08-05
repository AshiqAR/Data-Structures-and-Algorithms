#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* getNode(int n){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = n;
    newNode->next = NULL;
}

struct node* top = NULL;

void push(int n){
    if(top == NULL){
        top = getNode(n);
        return;
    }
    struct node* newNode = getNode(n);
    newNode->next = top;
    top = newNode;
}

int pop(){
    if(top==NULL){
        return -1;
    }
    int a = top->data;
    top = top->next;
    return a;
}

int isEmpty(){
    return top==NULL;
}

void printStack(){
    struct node* curr = top;
    while(curr!= NULL){
        printf("%d\n",curr->data);
        curr = curr->next;
    }
    printf("\n\n");
}

void insAtBott(int n){
    if(isEmpty()){
        push(n);
        return;
    }
    int a = pop();
    insAtBott(n);
    push(a);
}


void reverse(){
    if(isEmpty()){
        return;
    }
    int a = pop();
    reverse();
    insAtBott(a);
}


void main(){
    for(int i=1;i<=10;i++){
        push(i);
    }
    printStack();
    printf("\nReversed Stack\n");
    reverse();
    printStack();
}
