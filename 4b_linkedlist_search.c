// C program on single linked list search
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    
    printf("\n===== Linked List Search =====\n");
    printf("Searching for 20: %s\n", search(head, 20) ? "Found" : "Not Found");
    printf("Searching for 50: %s\n", search(head, 50) ? "Found" : "Not Found");
    printf("================================\n");
    
    return 0;
}
