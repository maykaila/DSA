#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct gradeNode {
    int grade;
    struct gradeNode *next;
} GradeNode;

typedef struct student {
    int id;
    char name[24];
    GradeNode *grades;  // nested linked list
    struct student *next;
} Student;

typedef struct {
    Student *top;
} StudentStack;

// ===== Function Prototypes =====
void initStack(StudentStack *s);
bool isEmpty(StudentStack s);
void push(StudentStack *s, int id, char name[], int grades[], int n);
Student pop(StudentStack *s);
void displayTop(StudentStack s);

int main() {
    StudentStack s;
    initStack(&s);

    int grades1[] = {90, 85, 88};
    int grades2[] = {70, 75};
    int grades3[] = {100, 95, 98, 99};

    printf("Pushing students...\n");
    push(&s, 1, "Alice", grades1, 3);
    push(&s, 2, "Bob", grades2, 2);
    push(&s, 3, "Charlie", grades3, 4);

    printf("\nTop student:\n");
    displayTop(s);

    printf("\n\nPopping top student...\n");
    Student popped = pop(&s);
    printf("Popped student: %s (ID: %d)\n", popped.name, popped.id);

    printf("\nNew top student:\n");
    displayTop(s);

    return 0;
}

void initStack(StudentStack *s){
    s->top = NULL;
}

bool isEmpty(StudentStack s){
    return (s.top == NULL) ? true : false;
}

void push(StudentStack *s, int id, char name[], int grades[], int n){ //n is the size of grades[]
    Student *newStudent = (Student*)malloc(sizeof(struct student));
    if(newStudent != NULL){
        strcpy(newStudent->name, name);
        newStudent->id = id;
        // build grades linked list
        newStudent->grades = NULL;
        for(int i=0; i<n; i++){
            GradeNode *newGrade = (GradeNode*)malloc(sizeof(GradeNode));
            newGrade->grade = grades[i];
            newGrade->next = newStudent->grades;
            newStudent->grades = newGrade;
        }
        newStudent->next = s->top;
        s->top = newStudent;
    }
}

Student pop(StudentStack *s){
    Student dummy;
    dummy.id = -1;
    strcpy(dummy.name, "N/A");
    dummy.grades = NULL;
    dummy.next = NULL;

    if(isEmpty(*s)) return dummy;

    Student *temp = s->top;
    Student node;

    // copy only the safe fields
    node.id = temp->id;
    strcpy(node.name, temp->name);
    node.grades = NULL;   // original grades will be freed
    node.next = NULL;

    // update stack
    s->top = s->top->next;

    // free old grades
    GradeNode *cur = temp->grades;
    while(cur != NULL){
        GradeNode *next = cur->next;
        free(cur);
        cur = next;
    }

    // free student
    free(temp);

    return node;
}


void displayTop(StudentStack s){
    Student *st = s.top;
    printf("Name: %s | ID: %d | Grades: ", st->name, st->id);

    // ✅ only loop here
    for(GradeNode *g = st->grades; g != NULL; g = g->next){
        printf("%d ", g->grade);
    }
}