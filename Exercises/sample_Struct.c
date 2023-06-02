#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char firstName[10];
    char middleName[10];
    char lastName[10];
}Name;

typedef struct{
    int empId;
    Name name;
    int salary;
}Employee;

void takeInput(Employee *ptr);
int search(Employee *ptr,int id,int n);
void Display(Employee *ptr,int n);

void main(){
    int n,a;
    printf("Enter the number of Employees: ");
    scanf("%d",&n);
    Employee *ptr;
    ptr = (Employee *) malloc(n*sizeof(Employee));
    if (ptr==NULL){
        printf("Error in dyanamic memory allocation\n");
        exit(0);
    }
    for (int i=0;i<n;i++){
        printf("\nEnter the details of Employee%d\n",i+1);
        takeInput(ptr+i);
    }
    printf("\nEmployee details\n");
    Display(ptr,n);
    printf("\nEnter the Employee ID to be searched: ");
    scanf("%d",&a);
    int index = search(ptr,a,n);
    if (index!=-1){
        printf("\nEmployee Details\n");
        printf("First Name: %s\n",(ptr+index)->name.firstName);
        printf("Middle Name: %s\n",(ptr+index)->name.middleName);
        printf("Last Name: %s\n",(ptr+index)->name.lastName);
        printf("Employee Id: %d\n",(ptr+index)->empId);
        printf("Salary: %d\n",(ptr+index)->salary);
    }
    else{
        printf("Employee ID is invalid\n");
    }
    printf("\n");
}

void takeInput(Employee *ptr){
    printf("Employee Id: ");
    scanf("%d",&ptr->empId);
    printf("First Name: ");
    scanf(" %s",ptr->name.firstName);
    printf("Middle Name: ");
    scanf(" %s",ptr->name.middleName);
    printf("Last Name: ");
    scanf(" %s",ptr->name.lastName);
    printf("Salary: ");
    scanf("%d",&ptr->salary);
}

int search(Employee *ptr,int id,int n){
    for (int i=0;i<n;i++){
        if ((ptr+i)->empId == id)
            return i;
    }
    return -1;
}

void Display(Employee *ptr,int n){
    for(int i=0;i<n;i++){
        printf("\nEmployee%d\n",i+1);
        printf("Employee Id: %d\n",(ptr+i)->empId);
        printf("First Name: %s\n",(ptr+i)->name.firstName);
        printf("Middle Name: %s\n",(ptr+i)->name.middleName);
        printf("Last Name: %s\n",(ptr+i)->name.lastName);
        printf("Salary: %d\n",(ptr+i)->salary);
    }
    printf("\n");
}
