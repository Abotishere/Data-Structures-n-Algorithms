#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

node* head = NULL;

node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insert(int item, int n){
    node* node1 = createNode(item);
    if (n < 1){
        printf("Invalid input\n");
        free(node1);
        return;
    }
    if (n == 1){
        // beginning case
        node1->next = head;
        head = node1;
    }
    else{
        node* ptr = head;
        for (int i = 0; i < n - 2; i++){
            if (ptr == NULL){
                printf("Invalid input\n");
                free(node1);
                return;
            }
            ptr = ptr->next;
        }
        node1->next = ptr->next;
        ptr->next = node1;
    }
}

void delete(int n){
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    if (n < 1) {
        printf("*Invalid input.\n");
        return;
    }
    node* current = head;
    if (n == 1){
        // beginning case
        head = current->next;
        printf("Deleted item: %d\n", current->data);
        free(current);
        return;
    }
    for (int i = 0; i < n-2; i++){
        if (current == NULL || current->next == NULL){
            printf("Position invalid.\n");
            return;
        }
        current = current->next;
    }
    node* temp = current->next;
    if (temp == NULL) {
        printf("Position invalid.\n");
        return;
    }
    current->next = temp->next;
    printf("Deleted item: %d\n", temp->data);
    free(temp);
}

void display(){
    if (head == NULL){
        printf("Empty list.\n");
        return;
    }
    node* temp = head;
    printf("Current list: \n");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, elem, pos;
    printf("Choices:\n1.Insert\n2.Delete\n3.View\n4.Exit\n");
    while (1){
        printf("Enter a choice: ");
        scanf("%d", &choice);
        if (choice == 4){
            printf("Exiting...");
            break;
        }
        switch (choice){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                printf("Enter its position: ");
                scanf("%d", &pos);
                insert(elem, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(pos);
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice. Please enter 1-4.\n");
        }
    }
    return 0;
}