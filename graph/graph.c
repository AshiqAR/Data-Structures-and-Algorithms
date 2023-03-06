// Representing Di-Graph using NODE_LIST and ADJACENCY_LIST
// adjacency matrix generation

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 50

struct adjlist{
    struct node* pointer;           //pointer to node list
    struct adjlist* next;           //link to adjlist_node
};

struct node{
    int data;
    struct adjlist* adj;
    struct node* next;
};

int arr[MAX];
int adjMat[MAX][MAX];
int count = 0;

struct node* getnode(int n){
    struct node* new = (struct node*)malloc(sizeof(struct node*));
    new->data = n;
    new->adj = NULL;
    new->next = NULL;
    return new;
}

struct adjlist* getadjlist(){
    struct adjlist* p = (struct adjlist*)malloc(sizeof(struct adjlist*));
    p->next = NULL;
    p->pointer = NULL;
    return p;
}

struct node* searchNode(struct node* head,int n){
    while(head != NULL){
        if(head->data == n)
            return head;
        head = head->next;
    }
    return NULL;
}

struct adjlist* setAdjList(struct node* head,int n,int index){
    if(n == 0)
        return NULL;

    int a,j;
    struct node* temp;
    struct adjlist* adjheader = NULL;
    struct adjlist* curr = adjheader;
    struct adjlist* newadj;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        for(j=0;j<count;j++){
            if(arr[j] == a){
                adjMat[index][j] = 1;
            }
        }
        temp = searchNode(head, a);
        if(adjheader == NULL){
            adjheader = getadjlist();
            adjheader->pointer = temp;
            curr = adjheader;
            continue;
        }
        newadj = getadjlist();
        newadj->pointer = temp;
        curr->next = newadj;
        curr = newadj;
    }
    return adjheader;
}

struct node* setGraph(int n){
    int i,j,a;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adjMat[i][j] = 0;
        }
    }

    struct node* head = NULL;
    struct node* curr;
    struct node* newNode;

    printf("Enter the data in each node\n");
    for( i=0;i<n;i++){
        printf("Data in node%d: ",i+1);
        scanf("%d",&a);
        arr[i] = a;
        if(head == NULL){
            head = getnode(a);
            curr = head;
            continue;
        }
        newNode = getnode(a);
        curr->next = newNode;
        curr = newNode;
    }
    if(head == NULL){
        printf("Graph is empty\n");
        return NULL;
    }
    curr = head;

    struct adjlist* adjheader;
    i = 0;
    while(curr != NULL){
        printf("Enter the number of nodes adjacent to %d: ",curr->data);
        scanf("%d",&a);
        
        if(a!=0)
            printf("Enter the nodes adjacent to %d\n",curr->data);
        
        adjheader = setAdjList(head,a,i);
        i++;
        curr->adj = adjheader;
        curr = curr->next;
    }
    return head;
}

void displayGraph(struct node* head){
    printf("\nGRAPH\n");
    struct adjlist* adj;
    while(head!=NULL){
        printf("%d => ",head->data);
        adj = head->adj;
        while(adj != NULL){
            printf("%d  ",adj->pointer->data);
            adj = adj->next;
        }
        head = head->next;
        printf("\n");
    }
}

void main(){
    int n,i,j;
    printf("Graph\n");
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);
    count = n;
    struct node* head = setGraph(n);
    
    printf("\nAdjacency Matrix\n    ");
    for(i=0;i<count;i++)
        printf("%d ",arr[i]);
    printf("\n");
    for(i=0;i<count;i++){
        printf("%d | ",arr[i]);
        for(j=0;j<count;j++)
            printf("%d ",adjMat[i][j]);
        printf("\n");
    }

    displayGraph(head);
}
