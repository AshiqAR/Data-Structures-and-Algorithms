#include <stdio.h>

void insertionSort(int arr[],int n){
    int i,j,t;
    for(i=1;i<n;i++){
        t = arr[i];
        for(j=i-1;j>=0 && arr[j] > t;j--){
            arr[j+1] = arr[j];
        }
        arr[++j] = t;
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

    insertionSort(arr,n);
    displayArr(arr,n);
}