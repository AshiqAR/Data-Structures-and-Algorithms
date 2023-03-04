// IMPLEMENTING POLYNOMIAL SUM
// POLYNOMIAL REPRESENTED IN STRUCT ARRAY

#include<stdio.h>

typedef struct{
    int expon;
    float coef;
}polynomial;

polynomial terms[100];
int avail = 0;

int polynomialZero(){
    return avail;
}

int takeInput(int n){
    printf(" (Enter the values in the decreasing degree)\n");
    for(int i=0;i<n;i++){
        printf("\nexponent value: ");
        scanf("%d",&terms[avail].expon);
        printf("coefficient value: ");
        scanf("%f",&terms[avail].coef);
        avail++;
    }
    printf("\n");
    return avail-1;
}

int addAB(int startC,int startA,int finishA,int startB,int finishB){
    int i=startA,j=startB,k=startC;
    while(i<=finishA && j<=finishB){
        if (terms[i].expon==terms[j].expon){
            terms[k].expon = terms[i].expon;
            terms[k].coef = terms[i].coef+terms[j].coef;
            j++ ; i++ ;
        }
        else if(terms[i].expon>terms[j].expon){
            terms[k].expon = terms[i].expon;
            terms[k].coef = terms[i].coef;
            i++;
        }
        else{
            terms[k].expon = terms[j].expon;
            terms[k].coef = terms[j].coef;
            j++;
        }
        k++;
    }

    for(;i<=finishA;i++,k++){
        terms[k].expon = terms[i].expon;
        terms[k].coef = terms[i].coef;
    }
    for(;j<=finishB;j++,k++){
        terms[k].expon = terms[j].expon;
        terms[k].coef = terms[j].coef;
    }
    return k-1;
    avail = k;
}

void display(int start, int finish){
    for (int i=start;i<finish;i++){
        if (terms[i].expon!=0)
            printf("%.2fx^%d + ",terms[i].coef,terms[i].expon);
        else
            printf("%.2fx + ",terms[i].coef);
    }
    if (terms[finish].expon==0)
        printf("%.2f\n",terms[finish].coef);
    else
        printf("%.2fx^%d\n",terms[finish].coef,terms[finish].expon);
}

void main(){
    int n1,n2,startA,startB,finishA,finishB,startC,finishC;

    printf("Enter the number of terms in polynomial A:");
    scanf("%d",&n1);
    startA=polynomialZero();
    printf("Enter polynomial A");
    finishA=takeInput(n1);
    printf("Enter the number of terms in polynomial B:");
    scanf("%d",&n2);
    startB=polynomialZero();
    printf("Enter polynomial B");
    finishB=takeInput(n2);
    startC=polynomialZero();
    finishC=addAB(startC,startA,finishA,startB,finishB);
    printf("\nPOLYNOMIAL A\n");
    display(startA,finishA);
    printf("\nPOLYNOMIAL B\n");
    display(startB,finishB);
    printf("\nPOLYNOMIAL C=(A+B)\n");
    display(startC,finishC);
    printf("\n");
}
