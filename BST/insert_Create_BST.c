// create a binary search tree through insert operation

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* getnode(int n){
    struct node* temp = (struct node*) malloc (sizeof(struct node *));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
}

void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

struct node* search(struct node* root,int x){
    if(root == NULL)
        return NULL;
    if((root->left == NULL && root->data > x) || (root->right == NULL && root->data < x))
        return root;
    

    if(root->data > x)
        return search(root->left,x);
    else if(root->data < x)
        return search(root->right,x);
    else
        return NULL;
}

struct node* insert(struct node* root){
    int n;
    if(root == NULL){
        printf("BST is empty!!\n");
        printf("Enter the root node data : ");
        scanf("%d",&n);
        root = getnode(n);
        return root;
    }
    printf("Enter the node data: ");
    scanf("%d",&n);
    struct node* insertPos = search(root,n);
    if(insertPos == NULL){
        printf("node with %d data already exists\n",n);
        return root;
    }
    if(insertPos->data > n){
        insertPos->left = getnode(n);
    }
    else{
        insertPos->right = getnode(n);
    }
    printf("%d inserted\n",n);
    return root;
}

void main(){
    struct node* root = NULL;
    printf("CREATE BINARY SEARCH TREE\n");
    printf("1. insert a node\n");
    printf("2. display the bst \n");
    printf("3. exit\n");
    int choice;
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            root = insert(root);
            break;
        case 2:
            if(root != NULL){
                printf("INORDER TRAVERSAL : ");
                inorder(root);
                printf("\n");
            }
            else{
                printf("BST is empty!!\n");
            }
            break;
        case 3:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Enter a valid input!!\n");
            break;
        }
    }while(choice!=3);
}
