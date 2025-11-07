#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node *insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *insertAtPosition(Node *head, int data, int position) {
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    Node *newNode = createNode(data);
    Node *current = head;
    
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Position out of range.\n");
        return head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void display(Node *head) {
    Node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    
    printf("Original List:\n");
    display(head);
    
    head = insertAtBeginning(head, 5);
    printf("After inserting 5 at beginning:\n");
    display(head);
    
    head = insertAtEnd(head, 40);
    printf("After inserting 40 at end:\n");
    display(head);
    
    head = insertAtPosition(head, 15, 2);
    printf("After inserting 15 at position 2:\n");
    display(head);
    
    return 0;
}
