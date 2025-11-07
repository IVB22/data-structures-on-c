// C program on stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    printf("\n===== Stack using Linked List =====\n");
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    display(top);
    top = pop(top);
    display(top);
    return 0;
}
