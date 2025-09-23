#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// ===== Function Prototypes =====
void initQueue(Queue *q);
bool isEmpty(Queue q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
void display(Queue q);

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Queue contents:\n");
    display(q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue contents:\n");
    display(q);

    return 0;
}

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue q){
    if(q.front == NULL){
        return true;
    }
    return false;
}

void enqueue(Queue *q, int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if(q->rear == NULL){
        q->front = newNode;
    }else{
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

int dequeue(Queue *q){
    int elem = -1;
    if(isEmpty(*q) == false){
        elem = q->front->data;
        Node *temp = q->front;
        q->front = q->front->next;
        free(temp);

        if(q->front == NULL){
            q->rear = NULL;
        }
    }
    return elem;
}

void display(Queue q){
    Queue temp;
    initQueue(&temp);

    while (!isEmpty(q)) {
        int val = dequeue(&q);
        printf("%d ", val);
        enqueue(&temp, val);
    }
    printf("\n");

    // restore
    while (!isEmpty(temp)) {
        enqueue(&q, dequeue(&temp));
    }
}