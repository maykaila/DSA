#include <stdio.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

// ===== Function prototypes =====
void initStack(Stack *s);
void push(Stack *s, int val);
int pop(Stack *s);
int peek(Stack *s);
int isEmpty(Stack *s);

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    printf("Peek: %d\n", peek(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Is empty? %d\n", isEmpty(&s));

    return 0;
}

void initStack(Stack *s){
    s->top = -1;
}

void push(Stack *s, int val){
    if(s->top != MAX-1){
        s->top++;
        s->data[s->top] = val;
    } 
}

int pop(Stack *s){
    if(s->top != -1){
        int temp = s->data[s->top];
        s->top--;
        return temp;
    }
}

int peek(Stack *s){
    int temp = s->data[s->top];
    return temp;
}

int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    }
}