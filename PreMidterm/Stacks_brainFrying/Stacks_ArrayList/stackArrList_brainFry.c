//what gpt calls difficult
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    char actions[MAX][MAX];
    int top;
} ActionStack;

// ===== Function prototypes =====
void initActionStack(ActionStack *s);
void performAction(ActionStack *undo, ActionStack *redo, char *action);
char* undoAction(ActionStack *undo, ActionStack *redo);
char* redoAction(ActionStack *undo, ActionStack *redo);
int isEmptyAction(ActionStack *s);

int main() {
    ActionStack undo, redo;
    initActionStack(&undo);
    initActionStack(&redo);

    // Perform actions
    performAction(&undo, &redo, "Type A");
    performAction(&undo, &redo, "Type B");
    performAction(&undo, &redo, "Type C");

    printf("Undo 1: %s\n", undoAction(&undo, &redo)); // should undo C
    printf("Undo 2: %s\n", undoAction(&undo, &redo)); // should undo B

    printf("Redo 1: %s\n", redoAction(&undo, &redo)); // should redo B
    printf("Perform D\n");
    performAction(&undo, &redo, "Type D"); // new action clears redo
    printf("Redo 2: %s\n", redoAction(&undo, &redo)); // should be NULL

    printf("Undo 3: %s\n", undoAction(&undo, &redo)); // should undo D
    printf("Undo 4: %s\n", undoAction(&undo, &redo)); // should undo B
    printf("Undo 5: %s\n", undoAction(&undo, &redo)); // should undo A
    printf("Undo 6: %s\n", undoAction(&undo, &redo)); // should be NULL

    return 0;
}

void initActionStack(ActionStack *s){
    s->top = -1;
}

void performAction(ActionStack *undo, ActionStack *redo, char *action){
    undo->top++;
    strcpy(undo->actions[undo->top], action);

    redo->top = -1;
}

char* undoAction(ActionStack *undo, ActionStack *redo){
    if(undo->top != -1){
        redo->top++;
        strcpy(redo->actions[redo->top], undo->actions[undo->top]);
        undo->top--;
        return redo->actions[redo->top];
    }
    return NULL;
}

char* redoAction(ActionStack *undo, ActionStack *redo){
    if(redo->top != -1){
        undo->top++;
        strcpy(undo->actions[undo->top], redo->actions[redo->top]);
        redo->top--;
        return undo->actions[undo->top];
    }
    return NULL;
}

int isEmptyAction(ActionStack *s){
    if(s->top == -1){
        return 1;
    }
}