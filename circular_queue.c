#include <stdio.h>

#define max 5
int myQueue[max];
int front = -1, size = 0;
int capacity = max;

void enqueue(int x){
    if (size == capacity){
        printf("Queue is full\n");
    }
    else{
        int rear;
        if (front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (front + size) % capacity;
        }
        myQueue[rear] = x;
        size++;
    }
}

void dequeue(){
    if (size == 0) printf("Queue is empty\n");
    else{
        int e = myQueue[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0) front = -1; // reset front when queue is empty
        printf("Dequeued element: %d\n", e);
    }
}

void view(){
    if (size == 0) printf("Queue is empty\n");
    else{
        printf("Current Queue:\n");
        for (int i = 0; i <= size; i++){
            int j = (front + i) % capacity;
            printf("%d\n", myQueue[j]);
        }
    }
}

int main(){
    int choice, elem;
    printf("Choices:\n1.Enqueue\n2.Dequeue\n3.View\n4.Exit\n");
    while (1){
        printf("Enter a choice: ");
        scanf("%d", &choice);
        if (choice == 4){
            printf("Exiting...");
            break;
        }
        switch (choice){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &elem);
                enqueue(elem);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                view();
                break;
        }
    }
    return 0;
}