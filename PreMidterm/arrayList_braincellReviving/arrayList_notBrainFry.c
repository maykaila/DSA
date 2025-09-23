#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// write your code here

typedef struct{
    int *data;
    int count;
    int length;
}ArrayList;

ArrayList *createArrayList(int initialCapacity);
void addElement(ArrayList *arr, int value);
int getElement(ArrayList *arr, int index);
void freeArrayList(ArrayList *arr);

int main() {
  ArrayList *myList = createArrayList(2); // Initial capacity of 2

  addElement(myList, 10);
  addElement(myList, 20);
  addElement(myList, 30);
  addElement(myList, 25);
  addElement(myList, 35);

  printf("Element at index 0: %d\n", getElement(myList, 0));
  printf("Element at index 1: %d\n", getElement(myList, 1));
  printf("Element at index 2: %d\n", getElement(myList, 2));
  printf("Element at index 3: %d\n", getElement(myList, 3));
  printf("Element at index 4: %d\n", getElement(myList, 4));

  freeArrayList(myList);

  return 0;
}

ArrayList *createArrayList(int initialCapacity){
    /*
        Write a function called createArrayList that takes an integer initialCapacity as input.
        This function should:
        Allocate memory for an ArrayList structure using malloc.
        Allocate memory for the initial integer array using malloc, based on the initialCapacity.
        Initialize the count to 0 and length to initialCapacity.
        Return a pointer to the created ArrayList.
        Include error checking: if memory allocation fails, return NULL after freeing any allocated memory.
    */
    ArrayList *L = (ArrayList*)malloc(sizeof(ArrayList));
    if(L == NULL){
        return NULL;
    }

    L->data = (int*)malloc(sizeof(int) * initialCapacity);
    if(L->data == NULL){
        return NULL;
    }

    L->count = 0;
    L->length = initialCapacity;

    return L;
}

void addElement(ArrayList *arr, int value){
    /*
        Write a function called addElement that takes an ArrayList pointer and an integer value as input.
        This function should:
        Check if the array list is full (i.e., count equals length).
        If the array list is full:
        Double the length.
        Use realloc to allocate a new, larger array.
        Update the data pointer and the length member.
        Include error checking: if realloc fails, do nothing.
        Add the value to the end of the array list and increment the count.
    */
    if(arr->length != 0){
        if(arr->count == arr->length){
            arr->data = realloc(arr->data, sizeof(int)*(arr->length * 2));
            if(arr->data == NULL){
                return;
            }
            arr->length = arr->length*2;
        }
        arr->data[arr->count] = value;
        arr->count++;
    }
}

int getElement(ArrayList *arr, int index){
    /*
        Write a function called getElement that takes an ArrayList pointer and an integer index as input.
        This function should:
        Check if the index is within the valid range (0 to count - 1).
        If the index is valid, return the element at that index.
        If the index is invalid, return -1.
    */
    int i;
    if(index >= 0 && index < arr->count){
        for(i=0; i<arr->count && i != index; i++){}
        return arr->data[i];
    }


}

void freeArrayList(ArrayList *arr){
    /*
        Write a function called freeArrayList that takes an ArrayList pointer as input.
        This function should:
        Free the memory allocated for the integer array using free.
        Free the memory allocated for the ArrayList structure using free.
    */
    ArrayList *temp = (ArrayList*)malloc(sizeof(ArrayList));
    for(int i=0; i<arr->count; i++){
        temp->data[i] = arr->data[i];
        free(temp);
    }
}