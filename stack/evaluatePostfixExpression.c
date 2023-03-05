#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define N 50

int stack[N];
int top = -1;

void push(int n){
    top ++;
    stack[top] = n;
}

int pop(){
    if(top == -1){
        printf("empty\n");
        exit(0);
    }
    int c = stack[top];
    top--;
    return c;
}

int power(int x,int n){
    if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    return x*power(x,n-1);
}

void main(){
    printf("EVALUATE POSTFIX EXPRESSIONS\n");
    char s[MAX],c;
    int a,b,temp;
    printf("Enter the postfix expression space seperated\n");
    scanf("%[^\n]",s);

    for(int i=0;i<strlen(s);i++){
        c = s[i];
        if (c == ' ' || c == ','){
            temp = 0;
            continue;
        }
        else if(c == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }
        else if(c == '-'){
            a = pop();
            b = pop();
            push(b-a);
        }
        else if(c == '/'){
            a = pop();
            b = pop();
            push(b/a);
        }
        else if (c == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }
        else if (c == '^'){
            a = pop();
            b = pop();
            push(power(b,a));
        }
        else if(c-48 >= 0 && c-48 <= 9){
            temp  = c - 48;
            do{
                i++;
                c = s[i];
                if(c-48 >= 0 && c-48 <= 9)
                    temp = (temp*10) + c - 48;
                else
                    break;
            }while(c != ' ' || c != ',' || c != '\n');
            i--;
            push(temp);
        }
        else{
            printf("Invalid input symbol or operator!!\n");
            exit(0);
        }
    }
    printf("\n%d\n",pop());
}