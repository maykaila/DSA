/*
    1. Insert the elements A, B, C, D, E, F, G, and H in an initially empty dictionary with hash values 1,4,9,9,0,3,4, and 3 respectively. Note: Solution for collision is linear hashing, i.e. next available space in the dictionary which is treated as a circular array.
    2. Determine the search length of each element. Search length (SL) of element x: 
        SL = Actual location of x - Hash(x)+1
        // Update formula to make it work for Actual location < Hash value
    3. Determine the Average Search Length of all 8 elements
        Ave SL = sum of SL / no. of elements
*/


#include<stdio.h>
#define EMPTY '-'
#define DELETED '*'
#define MAX 10

typedef char Dictionary[MAX];

void display(Dictionary D);
void initDict(Dictionary D);
int Hash(int key);
int insert(Dictionary D, int key, char elem);
int getSearchLen(int hash, int actual);

int main(){
    Dictionary D;
    initDict(D);

    int i1 = insert(D, 1, 'A');
    int i2 = insert(D, 4, 'B');
    int i3 = insert(D, 9, 'C');
    int i4 = insert(D, 9, 'D');
    int i5 = insert(D, 0, 'E');
    int i6 = insert(D, 3, 'F');
    int i7 = insert(D, 4, 'G');
    int i8 = insert(D, 3, 'H');

    display(D);
    
    int sumSL = 0;
    sumSL += getSearchLen(1, i1);
    sumSL += getSearchLen(4, i2);
    sumSL += getSearchLen(9, i3);
    sumSL += getSearchLen(9, i4);
    sumSL += getSearchLen(0, i5);
    sumSL += getSearchLen(3, i6);
    sumSL += getSearchLen(4, i7);
    sumSL += getSearchLen(3, i8);

    double avg = (double) sumSL / 8.0;
    printf("\nAverage Search Length = %.2f\n", avg);
}

int getSearchLen(int hash, int actual){
    if(actual >= hash){
        return (actual - hash + 1);
    }else{
        return (MAX - hash) + actual + 1;
    }
}

int insert(Dictionary D, int key, char elem){
    int index = Hash(key);
    while(D[index] != EMPTY && D[index] != DELETED){
        index = (index + 1) % MAX;
    }
    D[index] = elem;

    return index;
}

int Hash(int key){
    return key % MAX;
}

void initDict(Dictionary D){
    for(int i=0; i<MAX; i++){
        D[i] = EMPTY;
    }
}

void display(Dictionary D){
    printf("Dictionary:\n");
    for(int i=0; i<MAX; i++){
        printf("%d - %c\n", i ,D[i]);
    }
}