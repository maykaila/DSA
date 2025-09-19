#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *s);
bool isFull(Stack s);
bool isEmpty(Stack s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack s);
int top(Stack s);
void display(Stack s);

#endif