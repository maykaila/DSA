#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef unsigned int SET[MAX];

SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);

int main(){
    SET A = {1,0,0,1,1};
    SET B = {0,0,1,0,1};

    SET *C = Union(A, B);

    printf("Union result: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", (*C)[i]);
    }

    SET *D = Intersection(A, B);
    printf("\nIntersection result: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", (*D)[i]);
    }

    SET *E = Difference(A, B);
    printf("\nDifference result: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", (*E)[i]);
    }

    free(C);
    free(D);
    free(E);
    return 0;
}

SET* Difference(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET)); 
    int i;
    for (int i = 0; i < MAX; i++) {
        (*C)[i] = A[i] & !B[i]; 
    }

    return C;
}

SET* Intersection(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET)); 
    int i;
    for (int i = 0; i < MAX; i++) {
        (*C)[i] = A[i] & B[i];
    }

    return C;
}

SET* Union(SET A, SET B){ // A and B are pointers to the 1st element of their respective arrays
    SET *C = (SET*)malloc(sizeof(SET)); // is dynamically allocated bc if it isnt it, C in main would be a dangling pointer or would not have any value inside it
    int i;
    for (int i = 0; i < MAX; i++) {
        (*C)[i] = A[i] | B[i];
    }

    return C; //returns the address of the SET that is found in heap
}