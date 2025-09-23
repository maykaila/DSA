#include <stdio.h>
#include <stdbool.h>
#include "types.h"

// write your functions here
void initialize(Stack *s) {
    s->top = -1;
}

bool isFull(Stack s) {
    if(s.top == MAX-1){
        return true;
    }
    return false;
}

bool isEmpty(Stack s) {
    if(s.top == -1){
        return true;
    }
    return false;
}

void push(Stack *s, int value) {
    if(s->top != MAX-1){
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s) {
    if(s->top != -1){
        int temp = s->items[s->top];
        s->top--;
        return temp;
    }
}

int peek(Stack s) {
    if(s.top != -1){
        return s.items[s.top];
    }
    return -2;
}

int top(Stack s) {
    if(s.top != -1){
        return s.top;
    }
    return -1;
}

void display(Stack s) {
    if(s.top != -1){
        while(s.top != -1){
            int temp = s.items[s.top];
            printf("%d", temp);
            printf("\n");
            s.top--;
        } 
    }
}