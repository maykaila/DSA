#include <stdio.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int count;
} ArrayList;

// Prototypes
void initList(ArrayList *L);
void insertLast(ArrayList *L, int val);
void display(ArrayList L);
void rotateSublist(ArrayList *L, int start, int end, int k);

int main() {
    ArrayList list;
    initList(&list);

    for (int i = 1; i <= 6; i++) {
        insertLast(&list, i * 10);
    }

    printf("Original: ");
    display(list);

    rotateSublist(&list, 1, 4, 2);

    printf("After rotation: ");
    display(list);

    return 0;
}

void initList(ArrayList *L) {
    L->count = 0;
}

void insertLast(ArrayList *L, int val) {
    if (L->count < MAX) {
        L->data[L->count++] = val;
    }
}

void display(ArrayList L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// TODO: implement rotateSublist
void rotateSublist(ArrayList *L, int start, int end, int k) {
    // student trap zone 😈
    ArrayList temp;
    int len = (end-start)+1;
    int eme = k%len;

    for (int i = 0; i < len; i++) {
        temp.data[i] = L->data[start + i];
    }

    for(int i=0; i<len; i++){
        L->data[start + (i+k) % len] = temp.data[i];
    }
}
