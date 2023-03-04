#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* q[100];
int head = -1;
int tail = -1;
int count = 0;

void enqueue(struct node* n){
    count++;
    if(head == -1)
        head++;
    tail++;
    q[tail] = n;
}

struct node* dequeue(){
    if(count == 0){
        head = -1;
        tail = -1;
        return NULL;
    }
    struct node* n = q[head];
    head++;
    count--;
    return n;
}

int notEmptyQueue(){
    return count != 0;
}

struct node* getnode(int n){
    struct node* temp = (struct node*) malloc (sizeof(struct node *));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
}

struct node* binaryTreeCreate(){
    int n;
    printf("Enter the root node value : ");
    scanf("%d",&n);
    printf("Enter -1 in case of no child\n");
    struct node* root = getnode(n);
    enqueue(root);
    struct node* curr = root;
    while(notEmptyQueue()){
        curr = dequeue();
        printf("left_child of %d : ",curr->data);
        scanf("%d",&n);
        if(n != -1){
            curr->left = getnode(n);
            enqueue(curr->left);
        }
        printf("right_child of %d : ",curr->data);
        scanf("%d",&n);
        if(n != -1){
            curr->right = getnode(n);
            enqueue(curr->right);
        }
    }
    return root;
}

void displayTree(struct node* root){
    if(root == NULL)
        return;
    struct node* curr = root;
    printf("NODE\tl_node\tr_node\n");
    enqueue(curr);
    while(notEmptyQueue()){
        curr = dequeue();
        printf("%d\t",curr->data);
        if(curr->left != NULL){
            enqueue(curr->left);
            printf("%d\t",curr->left->data);
        }
        else{
            printf("*\t");
        }

        if(curr->right != NULL){
            enqueue(curr->right);
            printf("%d\t\n",curr->right->data);
        }
        else{
            printf("*\n");
        }
    }
}

void main(){
    printf("Binary Tree\n");
    struct node* root = binaryTreeCreate();
    displayTree(root);
}
