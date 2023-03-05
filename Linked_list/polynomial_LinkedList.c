// Polynomial implementation using linked list
// addition and multiplication of polynomials

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* getNode();
struct Node* takeInputPoly(struct Node* head);
struct Node* sumPoly(struct Node* polyA,struct Node* polyB);
struct Node* multiplyPoly(struct Node* polyA, struct Node* polyB);

void Display(struct Node* head);

void main(){
    struct Node* polyA=getNode();
    struct Node* polyB=getNode();
    printf("Polynomial A\n");
    polyA=takeInputPoly(polyA);
    printf("Polynomial B\n");
    polyB=takeInputPoly(polyB);
    printf("Polynomial A\n");
    Display(polyA);
    printf("Polynomial B\n");
    Display(polyB);
    struct Node* polySum = sumPoly(polyA,polyB);
    struct Node* polymult = multiplyPoly(polyA,polyB);
    printf("Polynomial A+B\n");
    Display(polySum);
    printf("Polynomial A*B\n");
    Display(polymult);
}

struct Node* getNode(){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        printf("Memory overflow\n");
        exit(0);
    }
    p->next=NULL;
    return p;
}

struct Node* takeInputPoly(struct Node* head){
    int n,i;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    struct Node* currNode = head;
    for(i=0;i<n;i++){
        struct Node* newNode = getNode();
        printf("\nCoefficient value: ");
        scanf("%d",&newNode->coeff);
        printf("Exponential value: ");
        scanf("%d",&newNode->exp);
        currNode->next = newNode;
        currNode = newNode;
    }
    printf("\n");
    return head;
}

void Display(struct Node* head){
    if(head==NULL || head->next==NULL)
        return;
    head = head->next;
    while(head->next!=NULL){
        printf(" %dx^%d +",head->coeff,head->exp);
        head = head->next;
    }
    head->exp==0 ? printf(" %d",head->coeff) : printf(" %dx^%d",head->coeff,head->exp);
    printf("\n");
}

struct Node* sumPoly(struct Node* polyA,struct Node* polyB){
    if(polyA==NULL || polyB==NULL){
        printf("Error in addition\n");
        return NULL;
    }
    if(polyA->next==NULL)
        return polyB;

    struct Node* sum = getNode();
    struct Node* head = sum;
    polyA = polyA->next;
    polyB = polyB->next;
    while(polyA!=NULL && polyB!=NULL){
        struct Node* newNode = getNode();
        if(polyA->exp > polyB->exp){
            newNode->exp=polyA->exp;
            newNode->coeff=polyA->coeff;
            polyA=polyA->next;
        }
        else if(polyA->exp < polyB->exp){
            newNode->exp=polyB->exp;
            newNode->coeff=polyB->coeff;
            polyB=polyB->next;
        }
        else{
            newNode->exp=polyA->exp;
            newNode->coeff = polyA->coeff + polyB->coeff;
            polyA=polyA->next;
            polyB=polyB->next;
        }
        sum->next=newNode;
        sum = newNode;
    }
    if(polyA!=NULL){
        while(polyA!=NULL){
            struct Node* newNode = getNode();
            newNode->coeff=polyA->coeff;
            newNode->exp=polyA->exp;
            sum->next=newNode;
            sum = newNode;
            polyA=polyA->next;
        }
    }

    if(polyB!=NULL){
        while(polyB!=NULL){
            struct Node* newNode = getNode();
            newNode->coeff=polyB->coeff;
            newNode->exp=polyB->exp;
            sum->next=newNode;
            sum = newNode;
            polyB=polyB->next;
        }
    }
    return head;
}

struct Node* multiplyPoly(struct Node* polyA, struct Node* polyB){
    struct Node* ab = getNode();
    struct Node* head = ab;

    if(polyA==NULL || polyB==NULL){
        printf("Cannot multiply\n");
        return NULL;
    }
    polyA = polyA->next;
    polyB = polyB->next;
    struct Node* headB = polyB;
    while(polyA!=NULL){
        polyB=headB;
        while(polyB!=NULL){
            struct Node* x = getNode();
            struct Node* newNode = getNode();
            newNode->coeff = polyA->coeff*polyB->coeff;
            newNode->exp = polyA->exp+polyB->exp;
            x->next=newNode;
            ab = sumPoly(ab,x);
            polyB=polyB->next;
        }
        polyA=polyA->next;
    }
    return ab;
}
