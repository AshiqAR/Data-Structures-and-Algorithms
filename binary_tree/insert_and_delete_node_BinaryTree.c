// to insert a new node or delete a node from a binary tree

#include<stdio.h>
#include<stdlib.h>

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


struct node* getNode(int n);

struct node* searchParent(struct node* root,int x){
    if (root == NULL)
        return NULL;
    if((root->left != NULL && root->left->data == x) || (root->right != NULL && root->right->data == x) )
        return root;
    struct node* n1 = searchParent(root->left,x);
    struct node* n2 = searchParent(root->right,x);
    if(n2 == NULL)
        return n1;
    return n2;
}

struct node* delete(struct node* root,int x){
    struct node* parent = searchParent(root,x);
    if(parent == NULL){
        printf("node not found\n");
        return root;
    }
    struct node* curr;
    if(parent->left != NULL && parent->left->data == x){
        curr = parent->left;
        struct node* lchild = curr->left;
        struct node* rchild = curr->right;
        if(lchild == NULL && rchild == NULL){
            parent->left = NULL;
        }
        else if(lchild == NULL){
            parent->left = rchild;
        }
        else if(rchild == NULL){
            parent->left = lchild;
        }
        printf("node %d deleted\n",curr->data);
    }
    else{
        curr = parent->right;
        struct node* lchild = curr->left;
        struct node* rchild = curr->right;
        if(lchild == NULL && rchild == NULL){
            parent->right = NULL;
        }
        else if(lchild == NULL){
            parent->right = rchild;
        }
        else if(rchild == NULL){
            parent->right = lchild;
        }
        printf("node %d deleted\n",curr->data);
    }
    return root;
}

struct node* search(struct node* root,int x){
    if(root == NULL)
        return NULL;
    if(root->data == x)
        return root;
    return search(root->left,x);
    return search(root->right,x);
}

struct node* insert(struct node* root,int n){
    int a;
    printf("Enter the data in the data after which the node is to be inserted: ");
    scanf("%d",&a);
    struct node* par = search(root,a);
    if(par == NULL){
        printf("node with data %d not found!!\n",a);
        return root;
    }
    char temp;
    struct node* new = getNode(n);
    if(par->left == NULL){
        par->left = new;
        printf("new node inserted as left child\n");
    }
    else if(par->right == NULL){
        par->right = new;
        printf("new node inserted as right child\n");
    }
    else{
        printf("both right and left childs of the parent node if filled\n");
        printf("so no insertion possible!!\n");
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
    struct node* root = getNode(1);
    struct node* n2 = getNode(2);
    struct node* n3 = getNode(3);
    struct node* n4 = getNode(4);
    struct node* n5 = getNode(5);
    struct node* n6 = getNode(6); 

/*          
             1
          /     \
        2        3
         \      /  \
          4    5    6
*/

    root->left = n2;
    root->right = n3;
    n2->right = n4;
    n3->left = n5;
    n3->right = n6;

    printf("Insert and delete nodes in a binary tree\n");
    printf("1. Insert a node into binary tree\n");
    printf("2. Delete a node in binary tree\n");
    printf("3. Display the tree\n");
    printf("4. Exit\n");
    int choice,n;
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice){

        case 1:
            printf("Enter the data in the node to be inserted: ");
            scanf("%d",&n);
            root = insert(root,n);
            break;

        case 2:
            printf("Enter the data in the node to be deleted: ");
            scanf("%d",&n);
            root = delete(root,n);
            break;
        
        case 3:
            displayTree(root);
            break;

        case 4:
            printf("Exiting the program...\n");
            break;

        default:
            printf("Enter a valid choice !!\n");
            break;
        }
        
    }while(choice != 4);
}

struct node* getNode(int n){
    struct node* temp = (struct node*) malloc (sizeof(struct node *));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
}

