// POLYNOMIAL IMPLEMENTATION USING ARRAY
#include <stdio.h>

void main(){
    int n;
    printf("Enter the degree of the polynomial: ");
    scanf("%d",&n);
    if(n==0)
        return;
    int p[n+1];

    for(int i=0;i<=n;i++){
        printf("coefficient of x^%d : ",n-i);
        scanf("%d",&p[i]);
    }

    printf("\nP(x) :");
    printf(" %dx^%d",p[0],n);
    for(int i=1;i<=n;i++){
        if(p[i] != 0)
            printf(" + %dx^%d",p[i],n-i);
    }
    printf("\n");
}