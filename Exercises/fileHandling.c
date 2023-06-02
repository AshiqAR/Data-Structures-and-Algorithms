// Read strings from the user
// Sort them in alphabetic order
// Write the sorted strings into the file
// Search for a string using binary search

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int input_string(FILE *);
void display_string(FILE *,int );
void sort(int,char[50][10]);
void search(FILE *,int);
void swap(char [50],char[50]);

void main(){
    int choice,n;
    FILE *p;
    p = fopen("string_file.txt","w+");

    printf("Binary Searching in String\n");
    n = input_string(p);

    printf("1. Display sorted strings\n");
    printf("2. Search string (Binary search)\n");

    do{
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display_string(p,n);
                break;
            case 2:
                search(p,n);
                break;
        }
    }while(choice<3);
}

int input_string(FILE *p){
    char st[50][10];
    int n;
    printf("Enter the number of strings : ");
    scanf("%d",&n);
    printf("Enter the strings :\n");
    
    for(int i=0;i<n;++i)
        scanf("%s",st[i]);
    sort(n,st);
    printf("Sorted...\n");

    for(int i=0;i<n;++i)
        fprintf(p,"%s\n",st[i]);
    return n;
}

void display_string(FILE *p,int n){
    char st[50][10];
    printf("Sorted strings :\n");
    for(int i=0;i<n;++i){
        fscanf(p,"%s",st[i]);
        printf("%s\n",st[i]);
    }
}

void sort(int n,char st[50][10]){
    for(int i=0;i<n;++i)
        for(int j=0;j<n-1;++j)
            if(strcmp(st[j+1],st[j])<0)
                swap(st[j+1],st[j]);
}

void search(FILE *p,int n){
    char s_st[50],st[50][10];
    int mid,beg=0,last=n-1,pos=-1;
    printf("Search\n");
    rewind(p);
    for(int i=0;i<n;++i)
        fscanf(p,"%s",st[i]); 
    printf("Enter string to be searched : ");
    scanf("%s",s_st);
    mid=(beg+last)/2;

    while(beg<=last&&pos==-1){
        if(strcmp(st[mid],s_st)==0)
            pos=mid;
        else if(strcmp(st[mid],s_st)<0)
            beg=mid+1;
        else
            last=mid-1;
        mid=(beg+last)/2;
    }

    if(pos==-1)
        printf("The entered string is absent");
    else
        printf("%s is present at position %d",st[pos],pos+1);
    printf("\n");
}

void swap(char a[50],char b[50]){
    char temp[50];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}