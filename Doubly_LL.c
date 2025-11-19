#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * prev;
    struct node * next;
} node;

node* head = NULL;

node* createNew(int dat){
    node* new = (node*) malloc(sizeof(node));
    if (!new){
        printf("New node allocation failed. Try again.\n");
        return NULL;
    }
    new->data = dat;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void insert(int dat, int n){
    // invalid input
    if (n < 1){
        printf("Invalid position. Please enter a valid position.\n");
        return;
    }

    node* node1 = createNew(dat);

    // when list is empty
    if (!head){
        // this way no matter what the value of n be
        // node1 will always be the first node
        printf("List is empty. Creating list.\n");
        head = node1;
        printf("%d inserted as first element.\n",dat);
        return;
    }

    //when n = 1 (first position)
    if (n == 1){
        head->prev = node1;
        node1->next = head;
        head = node1;
        return;
    }

    // n th position
    node* ptr = head;
    for(int i = 1; i < n - 1; i++){
        ptr = ptr->next;
        if (ptr == NULL){
            printf("Position out of order.\n");
            return;
        }
    }
    node1->prev = ptr;
    node1->next = ptr->next;
    if (ptr->next != NULL) { // Check if ptr->next is not NULL
        (ptr->next)->prev = node1;
    }
    ptr->next = node1;
    return;
}

void Delete(int n){
    if (head == NULL){
        printf("Empty list.\n");
        return;
    }

    if (n < 1) {
        printf("*Invalid position.\n");
        return;
    }

    node* current = head;

    if (n == 1){
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Deleted data: %d\n", current->data);
        free(current);
        return;
    }

    for (int i = 1; i < n - 1; i++){
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
    if (temp->next != NULL) {
        temp->next->prev = current;
    }

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
    while (temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, elem, pos;
    printf("Choices:\n1. Insert\n2. Delete\n3. View\n4. Exit\n");
    while (1){
        printf("Enter a choice: ");
        scanf("%d", &choice);
        if (choice == 4){
            printf("Exiting...\n");
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
                Delete(pos);
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