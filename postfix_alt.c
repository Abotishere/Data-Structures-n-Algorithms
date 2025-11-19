#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 50
int top = -1, stack[max];

void push(int x) {
    if (top == max - 1) printf("Stack overflow!\n");
    else stack[++top] = x;
}

int pop(int *ok) {
    if (top == -1) { 
        *ok = 0;
        return 0;
    }
    *ok = 1;
    return stack[top--];
}

int main() {
    char exp[100];
    printf("Enter postfix (space separated): ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    char *token = strtok(exp, " ");
    while (token) {
        char *endptr;
        long num = strtol(token, &endptr, 10);
        if (*endptr == '\0') {
            push((int)num);
        }
        else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            int ok;
            int b = pop(&ok), a = pop(&ok);
            if (!ok) { 
                printf("Error: Not enough operands.\n");
                return 1;
            }
            if (token[0] == '/' && b == 0) { 
                printf("Error: Division by zero.\n");
                return 1;
            }
            int r = (token[0] == '+') ? a + b :
                    (token[0] == '-') ? a - b :
                    (token[0] == '*') ? a * b : a / b;
            push(r);
        }
        else {
            printf("Error: Invalid token '%s'.\n", token);
            return 1;
        }
        token = strtok(NULL, " ");
    }
    if (top == 0) {
        printf("Result: %d\n", stack[top]);
    }
    else if (top > 0) {
        printf("Error: Too many operands.\n");
    }
    else {
        printf("Error: Invalid expression.\n");
    }
    return 0;
}