// implementation of node deletion in binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* getnode(int n);
void inorder(struct node* root);
struct node* search(struct node* root,int x);
struct node* insert(struct node* root,int n);
struct node* create_Sample_BST(struct node* root);      //create a sample BST


struct node* searchParent(struct node* root, int n){
    if(root == NULL )
        return NULL;
    if(root->data == n)
        return root;

    if( (root->data > n && root->left != NULL && root->left->data == n) )
        return root;
    else if( (root->data < n && root->right != NULL && root->right->data == n) )
        return root;
    
    if(root->data > n)
        return searchParent(root->left,n);
    else if(root->data < n)
        return searchParent(root->right,n);
}

int succ(struct node* root){
    if(root->left == NULL)
        return root->data;
    return succ(root->left);
}

struct node* delete(struct node* root, int n){
    struct node* parent = searchParent(root,n);
    int a;
    if(parent == NULL){
        printf("node %d is not found in BST\n",n);
        return root;
    }

    struct node* curr;
    int r = 0;
    if(root->data == n){                             //root node to be deleted
        // printf("complicated ^-^ \n");
        a = succ(root->right);
        root = delete(root,a);
        root->data = a;
        return root;
    }
    
    if(parent->data > n)
        curr = parent->left;
    else{
        curr = parent->right;
        r = 1;
    }
    
    struct node* lchild = curr->left;
    struct node* rchild = curr->right;

    if(lchild == NULL && rchild == NULL){           //deletion on leaf node
        if(r == 0)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if(lchild != NULL && rchild != NULL){      //node has two childs
        a = succ(curr->right);                      //finding the successor of n for replacement
        printf("%d\n",a);
        root = delete(root,a);
        curr->data = a;
    }
    else if(lchild != NULL){                        //has only left child   
        if(r==0)
            parent->left = lchild;
        else
            parent->right = lchild;
    }
    else if(rchild != NULL){                        //has only right child
        if(r==0)
            parent->left = rchild;
        else
            parent->right = rchild;
    }

    return root;
}



void main(){
    struct node* root = NULL;
    root = create_Sample_BST(root);
    printf("inorder traversal of created BST\n");
    inorder(root);

    printf("\nDeletion in BST\n");
    printf("1. delete a node\n");
    printf("2. display the bst \n");
    printf("3. exit\n");
    int choice,x;
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(root!=NULL){
                printf("Enter the node to be deleted: ");
                scanf("%d",&x);
                root = delete(root,x);
            }
            else{
                printf("BST is empty, No deletion\n");
            }
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
    if(root == NULL )
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

struct node* insert(struct node* root,int n){
    if(root == NULL){
        root = getnode(n);
        return root;
    }
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
    return root;
}

struct node* create_Sample_BST(struct node* root){
    root = insert(root,5);
    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,7);
    root = insert(root,9);
    root = insert(root,6);
    return root;
}