// Representing Di-Graph using NODE_LIST and ADJACENCY_LIST
// Breadth First Search in Di-Graph

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 50
#define Q_size 100

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
int count = 0;

int visited[MAX];                   //visited nodes in dfs
int k = -1;                           //no. of nodes visited
struct node* queue[Q_size];            //stack for dfs
int head = -1;
int tail = -1;

void enqueue(struct node* n){
    if(head==-1)
        head++;
    tail++;
    queue[tail] = n;
}
struct node* dequeue(){
    struct node* n = queue[head];
    head++;
    if(head>tail){
        head = -1;
        tail = -1;
    }
    return n;
}
int notEmpty(){
    return head != -1;
}


struct node* getnode(int n);
struct adjlist* getadjlist();
struct node* searchNode(struct node* head,int n);
struct adjlist* setAdjList(struct node* head,int n,int index);
struct node* setGraph(int n);
void displayGraph(struct node* head);


int notVisited(int n){
    for(int i=0;i<=k;i++){
        if(visited[i] == n){
            return 0;
        }
    }
    return 1;
}

void bfs(struct node* head){
    printf("\nBreadth First Search\n");
    printf("Enter the source node : ");
    int n;
    scanf("%d",&n);
    struct node* start = searchNode(head,n);
    struct node* curr;
    if(start == NULL){
        printf("node %d not in the graph\n",n);
        return;
    }

    enqueue(start);
    struct adjlist* list;
    while(notEmpty()) {
        curr = dequeue();
        if( notVisited(curr->data) ){
            printf("%d ",curr->data);
            visited[++k] = curr->data;
        }
        list = curr->adj;
        while(list!=NULL){
            enqueue(list->pointer);
            list = list->next;
        }

    }
    
    printf("\n");
    if(k != count-1){     
        printf("\nNodes Not Visited in DFS : ");          
        for(int i=0;i<count;i++){
            if(notVisited(arr[i]))
                printf("%d ",arr[i]);
        }
    }
    printf("\n");
    
}


void main(){
    int n,i,j;
    printf("Graph\n");
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);
    count = n;
    struct node* head = setGraph(n);

    displayGraph(head);

    bfs(head);
}










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
