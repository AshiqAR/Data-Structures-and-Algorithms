#include <stdio.h>

void merge(int arr[],int beg,int mid,int end){
    int a[end-beg+1],k=0,i=beg,j=mid+1;
    while(i<mid+1 && j<end+1){
        if(arr[i] < arr[j])
            a[k++] = arr[i++];
        else 
            a[k++] = arr[j++];
    }

    while(i<mid+1)
        a[k++] = arr[i++];
    while(j<end+1)
        a[k++] = arr[j++];

    k--;
    i = end;
    for(;i>=beg;k--,i--)
        arr[i] = a[k];
}

void mergeSort(int arr[],int beg,int end){
    if(beg >= end)
        return;

    mergeSort(arr,beg,(beg+end)/2);
    mergeSort(arr,((beg+end)/2)+1,end);
    merge(arr,beg,(beg+end)/2,end);
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

    mergeSort(arr,0,n-1);
    displayArr(arr,n);
}