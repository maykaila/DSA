#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Node for char stack
typedef struct node {
    char ch;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

// ===== Function Prototypes =====
void initStack(Stack *s);
bool isEmpty(Stack s);
void push(Stack *s, char c);
char pop(Stack *s);
void reverseWord(char word[]);

int main() {
    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);

    printf("Original: %s\n", word);
    printf("Reversed: ");
    reverseWord(word);

    return 0;
}

void initStack(Stack *s){
    s->top = NULL;
}

bool isEmpty(Stack s){
    return (s.top == NULL) ? true : false;
}

void push(Stack *s, char c){
    Node *newNode = (Node*)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->ch = c;
        newNode->next = NULL;

        if(s->top != NULL){
            newNode->next = s->top;   
        }
        s->top = newNode;
    }
}

char pop(Stack *s){
    if(isEmpty(*s) == false){
        char elem = s->top->ch;
        Node *temp = s->top;
        s->top = s->top->next;
        free(temp);
        return elem;
    }
}

void reverseWord(char word[]){
    Stack s;
    initStack(&s);
    
    int len = strlen(word);

    for(int i=0; i<len; i++){
        push(&s, word[i]);
    }

    int j=0;
    char word2[len+1];
    while(s.top != NULL){
        word2[j] = pop(&s);
        j++;
    }
    word2[j] = '\0'; 

    printf("%s", word2);
}