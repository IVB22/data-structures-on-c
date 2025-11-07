// C program on Circular Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct CircularQueue {
    int front, rear;
    int items[MAX];
};

void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue* q) {
    return (q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1) % (MAX - 1));
}

int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("%d enqueued to circular queue\n", value);
}

int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int data = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return data;
}

void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->items[q->rear]);
}

int main() {
    struct CircularQueue q;
    initQueue(&q);
    
    printf("\n===== Circular Queue Operations =====\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);
    
    enqueue(&q, 50);
    display(&q);
    
    return 0;
}
