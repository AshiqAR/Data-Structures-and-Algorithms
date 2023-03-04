// CONVERT INFIX EXPRESSION TO POSTFIX USING STACK

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 50
#define N 100

char s[MAX_SIZE];
int top = -1;

void pop(){
    top--;
}

void push(char c){
    top++;
    s[top] = c;
}

char seekTop(){
    if(top == -1){
        printf("Stack is empty\nInvalid input infix expression !!\n");
        exit(0);
    }
    return s[top];
}

void main(){
    printf("Infix to Postfix convertion\n");
    printf("Enter the infix expression: \n");
    char infix[N];
    scanf("%s",infix);
    char c,temp;
    push('(');

    printf("\nPost fix expression: \n");

    for(int i=0;i<strlen(infix);i++){
        c = infix[i];
        if(c == '('){
            push(c);
        }
        else if(c == ')'){
            while(seekTop() != '('){
                printf("%c",seekTop());
                pop();
            }
            pop();
        }
        else if(c == '+'){
            while( seekTop() == '-' || seekTop() == '+' || seekTop() == '*' || seekTop() == '/' || seekTop() == '^' ){
                printf("%c",seekTop());
                pop();
            }
            push(c);
        }
        else if(c == '-'){
            while(seekTop() == '+' || seekTop() == '-' || seekTop() == '*' || seekTop() == '/' || seekTop() == '^' ){
                printf("%c",seekTop());
                pop();
            }
            push(c);
        }
        else if(c == '/'){
            while(seekTop() == '*' || seekTop() == '/' || seekTop() == '^' ){
                printf("%c",seekTop());
                pop();
            }
            push(c);
        }
        else if(c == '*'){
            while(seekTop() == '/' || seekTop() == '*' || seekTop() == '^' ){
                printf("%c",seekTop());
                pop();
            }
            push(c);
        }
        else if(c == '^'){
            push(c);
        }
        else{
            printf("%c",c);
        }
    }
    while(top > 0){
        if(seekTop() == '('){
            printf("\nUnbalanced paranthesis found\nInvalid input infix expression!!\n");
            return;
        }
        printf("%c",seekTop());
        pop();
    }
    printf("\n");
}