#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} CircularQueue;

// ===== Function Prototypes =====
void initQueue(CircularQueue *q);
bool isEmpty(CircularQueue q);
bool isFull(CircularQueue q);
void enqueue(CircularQueue *q, int val);
int dequeue(CircularQueue *q);
int peekFront(CircularQueue q);
int peekRear(CircularQueue q);
void display(CircularQueue q);
int sumEvenPositions(CircularQueue q); // extra challenge

int main() {
    CircularQueue q;
    initQueue(&q);

    // Testing area
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // queue should be full now

    display(q);

    printf("Dequeued: %d\n", dequeue(&q));
    enqueue(&q, 60); // testing wrap-around

    display(q);

    printf("Front element: %d\n", peekFront(q));
    printf("Rear element: %d\n", peekRear(q));

    // printf("Sum of elements at even positions: %d\n", sumEvenPositions(q));

    return 0;
}

// ===== Implement the functions below =====
void initQueue(CircularQueue *q) {
    q->front = 1;
    q->rear = 0;
    // q->size = 0;
}

bool isEmpty(CircularQueue q) {
    // TODO
    return q.front == (q.rear+1)%MAX ? true : false;
}

bool isFull(CircularQueue q) {
    // TODO
    return q.front == (q.rear+2)%MAX ? true : false;
}

void enqueue(CircularQueue *q, int val) {
    // TODO
    if(isFull(*q) == false){
        q->rear = (q->rear+1)%MAX;
        q->arr[q->rear] = val;
        // q->front = (q->front+1)%MAX;
        // q->size++;
    }
}

int dequeue(CircularQueue *q) {
    // TODO
    int temp = -1;
    if(isEmpty(*q) == false){
        temp = q->arr[q->front];
        q->front = (q->front+1)%MAX;
        // q->size--;
    }
    return temp;
}

int peekFront(CircularQueue q) {
    // TODO
    return q.arr[q.front];
}

int peekRear(CircularQueue q) {
    // TODO
    return q.arr[q.rear];
}

void display(CircularQueue q) {
    // TODO
    CircularQueue temp;
    initQueue(&temp);

    printf("Queue:\n");
    while(isEmpty(q) == false){
        int value = dequeue(&q);
        printf("%d\n", value);
        // enqueue(&temp, value);
    }

    // while(isEmpty(temp) == false){
    //     enqueue(&q, dequeue(&temp));
    // }
}

// int sumEvenPositions(CircularQueue q) {
//     // TODO
// }
