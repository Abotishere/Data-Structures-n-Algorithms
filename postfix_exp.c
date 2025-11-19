#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// declaring stack globally
#define max 50
int top = -1;
int myStack[max];

void push(int stk[], int e){
    if (top == max - 1){
        printf("Stack overflow!\n");
    }
    else{
        top++;
        stk[top] = e;
    }
}

int pop(int stk[], int *sts){
    if (top == -1){
        *sts = 0; // fail
        printf("Stack underflow!\n");
        return 0;
    }
    else{
        *sts = 1; // success
        return stk[top--];
    }
}

void view(int stk[]){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("top-most element: %d\n", stk[top]);
    }
}

int main(){
    char exp[50];
    printf("Enter a postfix expression (single-digit operands, space separated): ");
    fgets(exp, sizeof(exp), stdin);

    int i = 0;
    while (exp[i] != '\0' && exp[i] != '\n'){
        if (isspace(exp[i])){
            i++;
            continue;
        }
        if (isdigit(exp[i])){
            push(myStack, exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            int status;
            int val2 = pop(myStack, &status);
            int val1 = pop(myStack, &status);
            if (!status){
                printf("Error: Not enough operands for operator '%c'.\n", exp[i]);
                return 1;
            }
            int result = 0;
            switch (exp[i]){
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/':
                    if (val2 == 0){
                        printf("Error: Division by zero.\n");
                        return 1;
                    }
                    result = val1 / val2;
                    break;
            }
            push(myStack, result);
        }
        else{
            printf("Error: Invalid character '%c' in expression.\n", exp[i]);
            return 1;
        }
        i++;
    }

    if (top == 0){
        printf("Result: %d\n", myStack[top]);
    }
    else if (top > 0){
        printf("Error: Too many operands. Stack not empty after evaluation.\n");
    }
    else{
        printf("Error: No result on stack. Invalid expression.\n");
    }
    return 0;
}