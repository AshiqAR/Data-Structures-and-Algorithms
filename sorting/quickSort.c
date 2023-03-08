#include <stdio.h>

int partition(int arr[],int beg,int end){
    int p = beg,t ;
    int f=0,l=beg,r=end;
    while(l<r){
        if(f==0){
            if(arr[p] < arr[r])
                r--;
            else{
                t = arr[p];
                arr[p] = arr[r];
                arr[r] = t;
                p = r;
                l++;
                f = 1;
            }
        }
        else{
            if(arr[p] > arr[l])
                l++;
            else{
                t = arr[p];
                arr[p] = arr[l];
                arr[l] = t;
                p = l;
                r--;
                f = 0;
            }
        }
    }
    return p;
}

void quickSort(int arr[],int beg,int end){
    if(beg >= end)
        return;

    int pivot = partition(arr,beg,end);
    quickSort(arr,beg,pivot-1);
    quickSort(arr,pivot+1,end);
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

    quickSort(arr,0,n-1);
    displayArr(arr,n);
}