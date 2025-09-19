#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[50];

typedef struct {
    String items[5];  // max 5 items per order
    int itemCount;
} Order;

typedef struct node {
    int orderId;
    String customer;
    Order order;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// ===== Function Prototypes =====
void initQueue(Queue *q);
bool isEmpty(Queue q);
void enqueue(Queue *q, int id, String customer, String items[], int n);
Node* dequeue(Queue *q);
void display(Queue q);

int main() {
    Queue q;
    initQueue(&q);

    String order1[] = {"Burger", "Fries"};
    String order2[] = {"Pizza", "Soda", "Wings"};

    enqueue(&q, 1, "Alice", order1, 2);
    enqueue(&q, 2, "Bob", order2, 3);

    printf("Current orders:\n");
    display(q);

    Node *processed = dequeue(&q);
    if(processed != NULL) {
        printf("Processed order %d for %s\n", processed->orderId, processed->customer);
        free(processed);
    }

    printf("Remaining orders:\n");
    display(q);

    return 0;
}
