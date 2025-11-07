// C program to create and display a node in single linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayNode(struct Node* node) {
    if (node == NULL) {
        printf("Node is empty\n");
        return;
    }
    printf("Node Data: %d\n", node->data);
    printf("Next Pointer: %p\n", (void*)node->next);
}

int main() {
    struct Node* node = createNode(100);
    printf("\n===== Single Linked List Node =====\n");
    displayNode(node);
    printf("====================================\n");
    
    free(node);
    return 0;
}
