    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    // Node for stack
    typedef struct node {
        int data;
        struct node *next;
    } Node;

    typedef struct {
        Node *top;
    } Stack;

    // ===== Function Prototypes =====
    void initStack(Stack *s);
    bool isEmpty(Stack s);
    void push(Stack *s, int val);
    int pop(Stack *s);
    void display(Stack s);

    int main() {
        Stack s;
        initStack(&s);

        // Test cases
        printf("Pushing 10, 20, 30...\n");
        push(&s, 10);
        push(&s, 20);
        push(&s, 30);

        printf("Current stack:\n");
        display(s);

        printf("Popped: %d\n", pop(&s));
        printf("Popped: %d\n", pop(&s));

        printf("Current stack:\n");
        display(s);

        printf("Test Print to check if 's' still has element/s:\n");
        display(s);

        return 0;
    }

    void initStack(Stack *s){
        s->top = NULL;
    }

    bool isEmpty(Stack s){
        if(s.top != NULL){
            return false;
        }
        return true;
    }

    void push(Stack *s, int val){
        Node *newNode = (Node*)malloc(sizeof(struct node));
        if(newNode != NULL){
            newNode->data = val;
            newNode->next = NULL;
            if(s->top == NULL){
                s->top = newNode;
            }else{
                newNode->next = s->top;
                s->top = newNode;
            }
        }
    }

    int pop(Stack *s){
        if(s->top != NULL){
            Node *temp = s->top;
            int elem = s->top->data;
            s->top = s->top->next;
            free(temp);
            return elem;
        }
        return -1;
    }

void display(Stack s){
    if (s.top != NULL) {
        Stack temp1, temp2;
        initStack(&temp1);
        initStack(&temp2);

        // Pop from s, print, and store into temp1
        while (s.top != NULL) {
            int elem = pop(&s);
            printf("%d\n", elem);
            push(&temp1, elem);
        }

        // Restore into temp2 (re-reverse)
        while (temp1.top != NULL) {
            push(&temp2, pop(&temp1));
        }

        // Now s is a local copy, so we don’t care if it stays empty.
        // The original stack in main is safe.
    }
}