// C program on queue using arrays
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue {
    int front, rear;
    int items[MAX];
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
    printf("%d enqueued to queue\n", value);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return q->items[q->front++];
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    
    printf("\n===== Queue Operations =====\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    
    printf("Front element: %d\n", peek(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);
    
    return 0;
}
