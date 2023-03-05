// SPARSE MATRIX REPRESENTATION AND OPERATIONS OVER IT

#include <stdio.h>

typedef struct{
    int row;
    int col;
    int value;
}term;

void takeInput(int arr[][10],int row,int col);
void displayTuple(term x[]);
void tupleForm(int arr[][10],term x[],int row,int col);
void Transpose(term x[],term Tx[]);
void matrixSum(term x[],term y[],term sum[]);

int A[10][10],B[10][10];
int r1,r2,c1,c2;
term a[30];
term b[30];
term aT[30];
term bT[30];
term sumX[30];

void main(){
    printf("Sparse Matrix\n");
    printf("Enter the row and column size of Matrix A: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the matrix A\n");
    takeInput(A,r1,c1);
    printf("Enter the row and column size of Matrix B: ");
    scanf("%d %d",&r2,&c2);
    printf("Enter the matrix B\n");
    takeInput(B,r2,c2);
    tupleForm(A,a,r1,c1);
    tupleForm(B,b,r2,c2);
    printf("MENU\n");
    printf("1. Convert two matrices to tuple form and display it.\n");
    printf("2. Find the transpose of the Matrices A and B in tuple form.\n");
    printf("3. Find the sum of the two matrices and display the sum in tupleform.\n");
    printf("4. Exit\n");
    int flag = 1;
    int y;
    while(flag!=0){
        printf("Enter your choice: ");
        scanf("%d",&y);
        switch(y){
            case 1:
                printf("\nMatrix A in the tuple form\n\n");
                displayTuple(a);
                printf("Matrix B in the tuple form\n\n");
                displayTuple(b);
                break;
            case 2:
                Transpose(a,aT);
                printf("\nTranspose(A)\n\n");
                displayTuple(aT);
                Transpose(b,bT);
                printf("Transpose(B)\n\n");
                displayTuple(bT);
                break;
            case 3:
                matrixSum(a,b,sumX);
                printf("Matrix A+B\n\n");
                displayTuple(sumX);
                break;
            case 4:
                flag = 0;
                printf("You are out of the program\n");
                break;
            default:
                printf("Enter a valid input\n");
                break;
        }
    }
}

void takeInput(int arr[][10],int row,int col){
    for (int i =0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

void displayTuple(term x[]){
    printf("Row\tColumn\tValue\n");
    for (int i=0;i<=x[0].value;i++)
        printf("%3d\t%6d\t%5d\n",x[i].row,x[i].col,x[i].value);
    printf("\n");
}

void tupleForm(int arr[][10],term x[],int row,int col){
    x[0].row = row;
    x[0].col = col;
    int k = 1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (arr[i][j]!=0){
                x[k].row = i;
                x[k].col = j;
                x[k].value = arr[i][j];
                k++;
            }
        }
    }
    x[0].value = k-1;
}

void Transpose(term x[],term Tx[]){
    Tx[0].row = x[0].col;
    Tx[0].col = x[0].row;
    Tx[0].value = x[0].value;
    int t = 1;
    for (int i=0;i<x[0].col;i++){
        for (int j=1;j<=x[0].value;j++){
            if (i==x[j].col){
                Tx[t].row = x[j].col;
                Tx[t].col = x[j].row;
                Tx[t].value = x[j].value;
                t++;
            }
        }
    }
}

void matrixSum(term x[],term y[],term sum[]){
    if (x[0].row!=y[0].row || x[0].col!=y[0].col){
        printf("\nSum not possible, two matrices are different order\n");
        return;
    }
    sum[0].col = x[0].col;
    sum[0].row = x[0].row;
    int i=1,j=1,p=1;
    while(i<=x[0].value && j<=y[0].value){
        if (x[i].col==y[j].col && x[i].row==y[j].row){
            sum[p].row = x[i].row;
            sum[p].col = x[i].col;
            sum[p].value = x[i].value + y[j].value;
            i++;
            j++;
            p++;
        }
        else if(x[i].row<y[j].row || (x[i].row==y[j].row && x[i].col<y[j].col)){
            sum[p].row = x[i].row;
            sum[p].col = x[i].col;
            sum[p].value = x[i].value;
            i++;
            p++;
        }
        else{
            sum[p].row = y[j].row;
            sum[p].col = y[j].col;
            sum[p].value = y[j].value;
            j++;
            p++;
        }
    }
    if (i<=x[0].value){
        for (;i<=x[0].value;i++){
            sum[p].row = x[i].row;
            sum[p].col = x[i].col;
            sum[p].value = x[i].value;
            p++;
        }
    }
    if(j<=y[0].value){
        for (;j<=y[0].value;j++){
            sum[p].row = y[j].row;
            sum[p].col = y[j].col;
            sum[p].value = y[j].value;
            p++;
        }
    }
    sum[0].value = p-1;
}
