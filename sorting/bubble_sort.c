#include <stdio.h>

void bubbleSort(int arr[],int n){
    int t,i,j;
    for( i=0;i<n;i++){
        for( j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void main(){
    printf("Enter the number of elements: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr,n);
    printArr(arr,n);
}