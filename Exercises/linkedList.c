#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *Head = NULL;
struct node* GetNode();
void ReturnNode(struct node*);
void Display();
void InsertBeg();
void InsertEnd();
void InsertPos();
void DeleteBeg();
void DeleteEnd();
void DeletePos();

void main(){
    int choice;
    printf("Linked List Operations\n");
    printf("Menu\n");
    printf("1. Display\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at specified position\n");
    printf("5. Delete from Beginning\n");
    printf("6. Delete from End\n");
    printf("7. Delete from a specified position\n");
    printf("(Any other option to exit)\n");
    
    do{
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Display();
                break;
            case 2:
                InsertBeg();
                break;
            case 3:
                InsertEnd();
                break;
            case 4:
                InsertPos();
                break;
            case 5:
                DeleteBeg();
                break;
            case 6:
                DeleteEnd();
                break;
            case 7:
                DeletePos();
                break;
        }
    }while(choice<=7);
}

struct node* GetNode(){
struct node *p;
p = (struct node *)malloc(sizeof(struct node));
if(p==NULL){
printf("Memory Overflow\n");
exit(0);
}
p->link=NULL;
return p;
}
void Display(){
    struct node * ptr;
    ptr = Head;
    if(Head==NULL){
        printf("No elements in list\n");
        return;
    }
    printf("Linked List : ");
    while(ptr->link !=NULL){
        printf("%d ",ptr->link->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void InsertBeg(){
    struct node *new;
    int x;
    printf("Enter the data : ");
    scanf("%d",&x);
    if(Head==NULL)
        Head = GetNode();
    new=GetNode();
    new->link = Head->link;
    Head->link = new;
    new->data = x;
}

void InsertEnd(){
    struct node *new,*ptr;
    int x;
    printf("Enter the data : ");
    scanf("%d",&x);
    if(Head==NULL)
        Head = GetNode();
    new=GetNode();
    ptr = Head;
    while(ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = new;
    new->data = x;
}

void InsertPos(){
    struct node *new,*ptr;
    int x,pos;
    printf("Enter the data : ");
    scanf("%d",&x);
    printf("Enter the position of data : ");
    scanf("%d",&pos);
    if(Head==NULL && pos>1){
        printf("Not possible\n");
        return;
    }
    if(Head==NULL&&pos==1)
        Head = GetNode();
    ptr = Head;
    while(ptr->link!=NULL&& pos!=1){
        pos--;
        ptr=ptr->link;
    }
    if(pos==1){
        new=GetNode();
        new->link = ptr->link;
        ptr->link = new;
        new->data = x; 
    }
    else
        printf("Not possible\n");
}

void ReturnNode(struct node *ptr){
    free(ptr);
    ptr=NULL;
}

void DeleteBeg(){
    if(Head==NULL){
        printf("Error!List is empty\n");
        return;
    }

    struct node *ptr,*ptr1;

    ptr = Head->link;
    ptr1 = ptr->link;
    Head->link = ptr1;
    ReturnNode(ptr);
    ptr=NULL;
    if(Head->link==NULL){
        ReturnNode(Head);
        Head = NULL;
    }
    printf("Element deleted\n");
}

void DeleteEnd(){
    if(Head==NULL){
        printf("Error!List is empty\n");
        return;
    }
    struct node *ptr,*ptr1;
    ptr = Head;
    while(ptr->link!=NULL){
        ptr1 = ptr;
        ptr = ptr->link;
    }
    ptr1->link = NULL;
    ReturnNode(ptr);
    if(Head->link==NULL){
        ReturnNode(Head);
        Head = NULL;
    }
    printf("Element deleted\n");
}

void DeletePos(){
    if(Head==NULL){
        printf("Error!List is empty\n");
        return;
    }
    int pos;
    struct node *ptr,*ptr1;
    printf("Enter the position of element : ");
    scanf("%d",&pos);
    ptr = Head;
    while(ptr->link!=NULL&& pos!=1){
        pos--;
        ptr=ptr->link;
    }
    if(pos==1){
        ptr1 = ptr->link;
        ptr->link =ptr1->link;
        ReturnNode(ptr1);
    }
    else{
        printf("Deletion not possible\n");
        return;
    }
    if(Head->link==NULL){
        ReturnNode(Head);
        Head = NULL;
    }
    printf("Element deleted\n");
}
