// previous operations on STACK and QUEUE but they
// have been IMPLEMENTED using LINKED LIST.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// first define a node: |data|ptr-->|
typedef struct Node{
    int data;
    struct Node* next;
} node;

node* top = NULL;

#define max 5 // maximum size of stack

node* createNode(int dat){
    node* new = (node*)malloc(sizeof(node));
    if (!new) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new->data = dat;
    new->next = NULL;
    return new;
}

// define all the operations as functions
int size = 0;
void push(int dat){
    // stack overflow situation
    if (size >= max){
        printf("Stack overflow!\n");
        return;
    }
    node* node1 = createNode(dat);
    node1->next = top;
    top = node1; 
    size++;
}

int pop(){
    // stack underflow situation
    if (top == NULL || size == 0){
        printf("Stack underflow\n");
        return INT_MIN; // default in this case
    }
    node* temp = top;
    int popped_element = temp->data;
    top = top->next;
    free(temp); // free the memory of removed node
    size--;
    return popped_element; // return popped value
}

void view(){
    node* temp = top; // temp traverses through the stack
    if (temp == NULL){
        printf("Empty stack.\n");
        return;
    }
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, elem;
    printf("Choices:\n");
    printf("1.Push\n2.Pop\n3.View\n4.Exit\n");
    while (1){
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &elem);
                push(elem);
                break;
            case 2:
                elem = pop();
                if (elem != INT_MIN)
                    printf("Popped element: %d\n", elem);
                break;
            case 3:
                view();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Enter valid choice. Try again.\n");
                break;
        }
    }
    return 0;
}