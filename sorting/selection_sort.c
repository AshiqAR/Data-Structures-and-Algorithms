#include <stdio.h>

void selectionSort(int arr[],int n){
    int i,j,minIndex,t;
    for(i=0;i<n;i++){
        minIndex = i;
        for(j=i;j<n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        t = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = t;
    }
}


void displayArr(int arr[],int n){
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

    selectionSort(arr,n);
    displayArr(arr,n);
}