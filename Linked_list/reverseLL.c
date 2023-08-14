#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* GetNode(int n){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory Overflow\n");
        exit(0);
    }
    p->data=n;
    p->next=NULL;
    return p;
}

void Display(struct node* head){
    if(head==NULL){
        printf("No elements in list\n");
        return;
    }
    printf("Linked List : ");
    while(head !=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* reverse(struct node* head){
    if(head == NULL || head->next == NULL)
        return head;
    struct node* curr = head;
    struct node* newH = reverse(head->next);
    struct node* n = newH;
    while(n->next != NULL)
        n = n->next;
    n->next = curr;
    curr->next = NULL;
    return newH;
}

void main(){
    struct node* head = GetNode(1);
    struct node* head2 = GetNode(2);
    struct node* head3 = GetNode(3);
    struct node* head4 = GetNode(4);
    struct node* head5 = GetNode(5);

    head->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    Display(head);

    struct node* newHead = reverse(head);
    Display(newHead);
}