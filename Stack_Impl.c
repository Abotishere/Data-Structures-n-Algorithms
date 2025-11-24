#include <stdio.h>

// declaring stack globally
#define max 5
int top = -1;
int myStack[max];

void push(int stk[],int e){
    if (top == max - 1){
        printf("Stack overflow!\n");
    }
    else{
        top++;
        stk[top]=e;
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
        int e1 = stk[top--];
        return e1;
    }
}

void view(int stk[]){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("top-most element: %d\n",stk[top]);
    }
}

int main(){
    int choice, elem;
    printf("Choices:\n1.push\n2.pop\n3.view\n4.exit\n");
    // 1.push() 2.pop() 3.view() 4.exit
    while (1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 4)  break;
        switch (choice){
        case 1:
            printf("Enter element to push: ");
            scanf("%d",&elem);
            push(myStack, elem);
            break;
        case 2: {
            int status;
            elem = pop(myStack, &status);
            if (!status) break;
            printf("Popped element: %d\n", elem);
            break;
        }
        case 3:
            view(myStack);
            break;
        }
    }
    return 0;
}
