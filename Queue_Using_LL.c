// previous operations on STACK and QUEUE but they
// have been IMPLEMENTED using LINKED LIST.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node definition
typedef struct Node{
    int data;
    struct Node* next;
} node;

node* front = NULL;
node* rear = NULL;

#define max 5 // maximum size of queue

int size = 0;

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

void enqueue(int dat){
    // queue overflow situation
    if (size >= max){
        printf("Queue Overflow!\n");
        return;
    }
    node* node1 = createNode(dat);
    if (rear == NULL){
        // when queue is empty
        front = rear = node1;
    }
    else{
        rear->next = node1;
        rear = node1;
    }
    size++;
}

int dequeue(){
    // queue underflow situation
    if (front == NULL || size == 0){
        printf("Queue underflow\n");
        return INT_MIN;
    }
    node* temp = front;
    int dequeued_element = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL; // Queue is now empty
    free(temp); 
    // or we can do
    // temp->next = NULL;
    size--;
    return dequeued_element;
}

void view(){
    node* temp = front; // temp traverses through the queue
    if (temp == NULL){
        printf("Empty queue.\n");
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
    printf("1.Enqueue\n2.Dequeue\n3.View\n4.Exit\n");
    while (1){
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &elem);
                enqueue(elem);
                break;
            case 2:
                elem = dequeue();
                if (elem != INT_MIN)
                    printf("Dequeued element: %d\n", elem);
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