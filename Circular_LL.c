#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* tail = NULL;

node* createNew(int val){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insert(int val, int pos){
    node* node1 = createNew(val);
    if (tail == NULL){
        // when list doesnt exist yet
        if (pos != 1){
            printf("Invalid input\n");
            free(node1);
            return;
        }
        tail = node1;
        node1->next = node1;
        return;
    }
    if (pos == 1){
        // beginning case
        node1->next = tail->next;
        tail->next = node1;
        return;
    }
    node* ptr = tail->next;
    for (int i = 1; i < pos - 1; i++){
        ptr = ptr->next;
        if (ptr == tail->next){
            printf("Invalid position, out of order.\n");
            free(node1);
            return;
        }
    }
    node1->next = ptr->next;
    ptr->next = node1;
    if (ptr == tail){
        // end case
        tail = node1;
    }
}

void delete(int pos){
    if (tail == NULL){
        printf("Empty list.\n");
        return;
    }
    node* head = tail->next;
    if (head == tail){
        // when there is only one element
        printf("Deleted element: %d\n", head->data);
        free(head);
        tail = NULL;
    }
    if (pos == 1){
        // beginning case
        tail->next = head->next;
        printf("Deleted element: %d\n", head->data);
        free(head);
    }
    node* prev = head;
    for (int i = 1; i < pos - 1; i++){
        prev = prev->next;
        if (prev == tail->next){
            printf("Invalid position, out of order\n");
            return;
        }
    }
    node* temp = prev->next;
    if (temp == tail) tail = prev;
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display(){
    if (tail == NULL){
        printf("Enpty list.\n");
        return;
    }
    node* ptr = tail->next;
    do{
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
    printf("(back to head)\n");
}

int main(){
    int choice, val, pos;
    printf("Choices:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insert(val, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}