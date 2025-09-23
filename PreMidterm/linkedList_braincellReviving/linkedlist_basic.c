#include <stdio.h>
#include <stdlib.h>

// ===== Node definition =====
typedef struct node {
    int data;
    struct node *next;
} Node;

// ===== Linked list struct =====
typedef struct {
    Node *head;
    int count;
} LinkedList;

// ===== Function Prototypes =====
void initList(LinkedList *L);
void insertAt(LinkedList *L, int pos, int value);
void deleteAt(LinkedList *L, int pos);
void displayList(LinkedList *L);

int main() {
    LinkedList list;
    initList(&list);

    insertAt(&list, 0, 10); // front
    insertAt(&list, 1, 20); // end
    insertAt(&list, 1, 15); // middle
    displayList(&list);     // expected: 10 -> 15 -> 20

    deleteAt(&list, 1);     // delete middle (15)
    displayList(&list);     // expected: 10 -> 20

    deleteAt(&list, 0);     // delete front
    displayList(&list);     // expected: 20

    deleteAt(&list, 0);     // delete last element
    displayList(&list);     // expected: (empty)

    return 0;
}

// ===== Function Definitions =====
void initList(LinkedList *L) {
    // TODO: set head = NULL, count = 0
    L->head = NULL;
    L->count = 0;
}

void insertAt(LinkedList *L, int pos, int value) {
    // TODO: insert at start, end, or middle
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = value;
        newNode->next = NULL;
        if(pos == 0){
            L->head = newNode;
        }else{
            Node *temp = L->head;
            int i;
            for(i=0; i < pos-1 && temp != NULL; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        L->count++;
    }
}

void deleteAt(LinkedList *L, int pos) {
    // TODO: delete at start, end, or middle
    if(L->head != NULL){
        Node *tbd;
        if(pos == 0){
            tbd = L->head;
            L->head = L->head->next;
        }else{
            int i;
            Node *trav = L->head;
            for(i=0; i<pos-1 && trav->next != NULL; i++){
                trav = trav->next;
            }
            tbd = trav->next;
            if(tbd != NULL){
                trav->next = tbd->next;
            } 
        }
        free(tbd);
        L->count--;
    }
}

void displayList(LinkedList *L) {
    // TODO: print list
    printf("List: ");
    if(L->head != NULL){
        Node *temp = L->head;
        for(int i=0; i<L->count; i++){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }else{
        printf("List is empty.");
    }
    printf("\n");
}
