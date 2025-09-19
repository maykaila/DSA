#include <stdio.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int count; // number of elements currently in the list
} ArrayList;

// Function prototypes
void initList(ArrayList *L);
void insertAt(ArrayList *L, int pos, int val);
void deleteAt(ArrayList *L, int pos);
void display(ArrayList L);

int main() {
    ArrayList list;
    initList(&list);

    // Test driver
    insertAt(&list, 0, 10);   // [10]
    insertAt(&list, 1, 20);   // [10, 20]
    insertAt(&list, 1, 15);   // [10, 15, 20]
    display(list);

    deleteAt(&list, 0);       // [15, 20]
    display(list);

    return 0;
}

// Initialize the list
void initList(ArrayList *L) {
    L->count = 0;
}

// Insert val at position pos
void insertAt(ArrayList *L, int pos, int val) {
    // TODO: implement
    if(L->count == 0){
        L->data[0] = val;
        L->count++;
    }else{
        int i;
        for(i=L->count; i>0 && i != pos; i--){
            L->data[i] = L->data[i-1];
        }
        L->data[i] = val;
        L->count++;
    }
}

// Delete element at position pos
void deleteAt(ArrayList *L, int pos) {
    // TODO: implement
    if(L->count != 0){
        int i;
        for(i=0; i<L->count-1; i++){
            L->data[i] = L->data[i+1];
        }
        L->count--;
    }
}

// Display elements
void display(ArrayList L) {
    // TODO: implement
    for(int i=0; i<L.count; i++){
        printf("%d ", L.data[i]);
    }
    printf("\n");
}
