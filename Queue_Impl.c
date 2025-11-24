#include <stdio.h>

#define max 5
int myQueue[max];
int front = -1, rear = -1;

// enqueue()-- basically adds element to the queue
void enqueue(int x){
    if (rear >= max - 1){ // if rear crosses the queue size
        printf("Queue overflow!\n");
    }
    else{
        if (front == -1) front = 0;
        // front now refers to first index in queue
        myQueue[++rear] = x;
        // increments rear first,
        // then uses that incremented value.

        // rear increases as we enqueue more elements
        // but front remains same(the first index)
    }
}

// dequeue()-- basically removes element from the queuew
void dequeue(){
    if (front < 0 || front > rear){
        // when front goes past rear or doesnt start at first index
        printf("Queue underflow\n");
    }
    else{
        int e = myQueue[front++];
        // front is incremented after its previous value is used.
        // That is, first the element at front is read and only then
        // the front shifts to the next element, virtually dequeuing
        // or removing that element from the queue.
        printf("Dequeued element = %d\n", e);
    }
}

// view()-- displays the current queue
void view(){
    if (front < 0 || front > rear){
        printf("Queue underflow\n");
    }
    else{
        printf("Current queue: \n");
        for (int i = front; i <= rear; i++){
            printf("%d. %d\n", (i - front + 1), myQueue[i]);
            // prints all the elements correctly in order
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