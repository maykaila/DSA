#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int minData[MAX]; // auxiliary stack for minimum
    int top;
} MinStack;

// ===== Function prototypes =====
void initMinStack(MinStack *s);
void pushMin(MinStack *s, int val);
int popMin(MinStack *s);
int getMin(MinStack *s);
int isEmptyMin(MinStack *s);

int main() {
    MinStack s;
    initMinStack(&s);

    pushMin(&s, 5);
    pushMin(&s, 3);
    pushMin(&s, 7);

    printf("Current min: %d\n", getMin(&s));
    popMin(&s);
    printf("Current min after pop: %d\n", getMin(&s));

    return 0;
}

void initMinStack(MinStack *s){
    s->top = -1;
}

void pushMin(MinStack *s, int val){
    s->top++;
    s->data[s->top] = val;

    if(s->top == 0){
        s->minData[s->top] = val;
    }else{
        s->minData[s->top] = (val < s->minData[s->top-1]) ? val : s->minData[s->top-1]; 
    }
}

int popMin(MinStack *s){
    if(s->top != -1){
        int temp = s->data[s->top];
        s->top--;
        return temp;
    }
}

int getMin(MinStack *s){
    if(s->top != -1){
        int min = s->minData[s->top];
        s->top--;
        return min;
    }
}

int isEmptyMin(MinStack *s){
    if(s->top == -1){
        return 1;
    }
}