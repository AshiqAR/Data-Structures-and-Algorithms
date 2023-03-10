#include <stdio.h>

void swap(int arr[],int i,int j){
    int a = arr[i];
    arr[i] = arr[j];
    arr[j] = a;
}

void heapify(int arr[],int i){
    if(i==0 && (i-1)/2<0)
        return;
    if( arr[(i-1)/2] < arr[i] ){
        swap(arr,i,(i-1)/2);
        heapify(arr,(i-1)/2);
    }
}

void reheap(int arr[],int i,int limit){
    if(i >= limit)
        return;
    int l = 2*i+1;
    int r = 2*i+2;
    if(r < limit){
        if(arr[r] > arr[l] && arr[r] > arr[i]){
            swap(arr,i,r);
            reheap(arr,r,limit);
        }
        else if( (arr[l] > arr[r] && arr[l] > arr[i] ) ){
            swap(arr,i,l);
            reheap(arr,l,limit);
        }
        else if(arr[l] > arr[i]){
            swap(arr,i,l);
            reheap(arr,l,limit);
        }
        else if(arr[r] > arr[i]){
            swap(arr,i,r);
            reheap(arr,r,limit);
        }
    }
    else if(l < limit){
        if(arr[l] > arr[i]){
            swap(arr,i,l);
            reheap(arr,l,limit);
        }
    }
    return;
}

void heapSort(int arr[],int n){
    int i,temp;
    for(i=0;i<n;i++)
        heapify(arr,i);

    for(i=n-1;i>-1;i--){
        swap(arr,i,0);
        reheap(arr,0,i);
    }
}

void displayArr(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void main(){
    printf("Enter the number of elements: ");
    int n,a;
    scanf("%d",&n);
    int arr[n];

    printf("Enter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
    displayArr(arr,n);
}
