/***********************************************
 *  A chatgpt problem,                         *
 *  that i didn't bother solving               *
 *  because the exam is not about linked list  *
 *  but about stacks and queues...             *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int ticketNo;
} Passenger;

typedef struct Node {
    Passenger data;      // nested struct
    struct Node *next;
} Node;

Node* createNode(char *name, int age, int ticketNo) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    newNode->data.age = age;
    newNode->data.ticketNo = ticketNo;
    newNode->next = NULL;
    return newNode;
}

void boardAtStart(Node **head, char *name, int age, int ticketNo) {
    Node *newNode = createNode(name, age, ticketNo);
    newNode->next = *head;
    *head = newNode;
}

void boardAtEnd(Node **head, char *name, int age, int ticketNo) {
    Node *newNode = createNode(name, age, ticketNo);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void boardAtPosition(Node **head, char *name, int age, int ticketNo, int pos) {
    if (pos <= 1 || *head == NULL) {
        boardAtStart(head, name, age, ticketNo);
        return;
    }
    Node *newNode = createNode(name, age, ticketNo);
    Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void removePassenger(Node **head, char *name) {
    if (*head == NULL) return;
    Node *temp = *head;
    if (strcmp(temp->data.name, name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    Node *prev = NULL;
    while (temp != NULL && strcmp(temp->data.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // not found
    prev->next = temp->next;
    free(temp);
}

void showTrain(Node *head) {
    if (head == NULL) {
        printf("Train is empty.\n");
        return;
    }
    printf("Train: [\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("  Name: %s | Age: %d | Ticket#: %d\n",
               temp->data.name, temp->data.age, temp->data.ticketNo);
        temp = temp->next;
    }
    printf("]\n");
}

int main() {
    Node *train = NULL;

    boardAtStart(&train, "Alice", 25, 1001);
    showTrain(train);

    boardAtEnd(&train, "Bob", 30, 1002);
    showTrain(train);

    boardAtPosition(&train, "Charlie", 22, 1003, 2);
    showTrain(train);

    removePassenger(&train, "Alice");
    showTrain(train);

    boardAtStart(&train, "Diana", 28, 1004);
    showTrain(train);

    return 0;
}