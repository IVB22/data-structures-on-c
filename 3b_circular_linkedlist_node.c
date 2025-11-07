// C program to create and display a node in circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void displayNode(struct Node* node) {
    if (node == NULL) {
        printf("Node is empty\n");
        return;
    }
    printf("Node Data: %d\n", node->data);
    printf("Next Pointer: %p (points to itself)\n", (void*)node->next);
}

int main() {
    struct Node* node = createNode(300);
    printf("\n===== Circular Linked List Node =====\n");
    displayNode(node);
    printf("======================================\n");
    
    free(node);
    return 0;
}
