// C program to create and display a node in double linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
Add doubly linked list node creation and display    newNode->next = NULL;
    return newNode;
}

void displayNode(struct Node* node) {
    if (node == NULL) {
        printf("Node is empty\n");
        return;
    }
    printf("Prev Pointer: %p\n", (void*)node->prev);
    printf("Node Data: %d\n", node->data);
    printf("Next Pointer: %p\n", (void*)node->next);
}

int main() {
    struct Node* node = createNode(200);
    printf("\n===== Double Linked List Node =====\n");
    displayNode(node);
    printf("====================================\n");
    
    free(node);
    return 0;
}
