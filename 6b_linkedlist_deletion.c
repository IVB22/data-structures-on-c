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

Node *deleteNode(Node *head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    
    if (head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Element %d deleted from the beginning.\n", data);
        return head;
    }
    
    Node *current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            printf("Element %d deleted from the list.\n", data);
            return head;
        }
        current = current->next;
    }
    
    printf("Element %d not found in the list.\n", data);
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
    
    head = deleteNode(head, 20);
    printf("After deleting 20:\n");
    display(head);
    
    head = deleteNode(head, 10);
    printf("After deleting 10 (first element):\n");
    display(head);
    
    head = deleteNode(head, 40);
    printf("After deleting 40:\n");
    display(head);
    
    return 0;
}
