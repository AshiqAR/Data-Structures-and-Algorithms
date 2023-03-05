// POLYNOMIAL IMPLEMENTATION USING STRUCT ARRAY
#include <stdio.h>

typedef struct{
    int exp;
    int coeff; 
}polynomial;

void printPolynomial(polynomial p[],int n){
    if(n==0)
        return;
    
    printf("\nP(x) :");
    printf(" %dx^%d",p[0].coeff,p[0].exp);
    for(int i=1;i<n;i++){
        if(p[i].coeff != 0)
            printf(" + %dx^%d",p[i].coeff,p[i].exp);
    }
    printf("\n");
}

void main(){
    int n,t;
    printf("Enter the degree of the polynomial: ");
    scanf("%d",&n);
    polynomial p[n+1];
    for(int i=n,j=0;i>=0;i--,j++){
        printf("coefficient of x^%d : ",i);
        scanf("%d",&p[j].coeff);
        p[j].exp = i;
    }
    printPolynomial(p,n+1);
}