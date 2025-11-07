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

Node *replace(Node *head, int oldData, int newData) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return head;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", oldData);
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
    head->next->next->next = createNode(40);
    
    printf("Original List:\n");
    display(head);
    
    head = replace(head, 20, 25);
    printf("After replacing 20 with 25:\n");
    display(head);
    
    head = replace(head, 40, 45);
    printf("After replacing 40 with 45:\n");
    display(head);
    
    return 0;
}
