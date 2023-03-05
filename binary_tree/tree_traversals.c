// implementation of inorder, preorder and postorder tree traversal algorithms

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

struct node* q[100];
int head = -1;
int tail = -1;
int count = 0;
void enqueue(struct node* n);
struct node* dequeue();
int notEmptyQueue();

struct node* getnode(int n);
struct node* binaryTreeCreate(int a[]);



void main(){
    int a[] = {1,2,3,4,-1,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1,-1};    //array for levelwise input tree
    int len = 17;                                               //length of the array;
    printf("Binary Tree\n");
    struct node* root = binaryTreeCreate(a);

    printf("INORDER TRAVERSAL\n");
    inorder(root);

    printf("\nPREORDER TRAVERSAL\n");
    preorder(root);

    printf("\nPOSTORDER TRAVERSAL\n");
    postorder(root);
    printf("\n");
}

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

struct node* binaryTreeCreate(int a[]){
    int n = a[0];
    struct node* root = getnode(n);
    enqueue(root);
    struct node* curr = root;
    int i=1;
    while(notEmptyQueue()){
        curr = dequeue();
        n = a[i++];
        if(n != -1){
            curr->left = getnode(n);
            enqueue(curr->left);
        }
        n = a[i++];
        if(n != -1){
            curr->right = getnode(n);
            enqueue(curr->right);
        }
    }
    return root;
}