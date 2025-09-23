#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "arrayStack.h"

typedef char String[50];

int main() {
    String menu[5] = {"Push a container", "Pop a container", "Check if a container exists", "Display all stacks", "Exit"};
    
    Stack S[3];
    
    for (int i = 0; i < 3; i++) {
        initialize(&S[i]);
    }
    
    int choice, val;
    
    do {
        printf("\n--- Warehouse Inventory Management System ---\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, menu[i]);
        }
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {  // PUSH
                printf("Enter container ID to push: ");
                scanf("%d", &val);
                bool pushed = false;
                for (int i = 0; i < 3; i++) {
                    if (!isFull(S[i])) {
                        push(&S[i], val);
                        printf("Container %d pushed into stack %d successfully.\n\n", val, i + 1);
                        pushed = true;
                        break;
                    }
                }
                if (!pushed) {
                    printf("All stacks are full. Cannot push container %d.\n\n", val);
                }
                break;
            }
            case 2: {  // POP
                int popped = -1;
                for (int i = 0; i < 3; i++) {
                    if (!isEmpty(S[i])) {
                        popped = pop(&S[i]);
                        printf("Container %d popped from stack %d successfully.\n\n", popped, i + 1);
                        break;
                    }
                } 
                if (popped == -1) {
                    printf("All stacks are empty. Nothing to pop.\n\n");
                }
                break;
            }
            case 3: {  // CHECK
                printf("Enter container ID to check: ");
                scanf("%d", &val);

                bool found = false;
                for (int i = 0; i < 3 && !found; i++) {
                    for (int j = 0; j <= S[i].top; j++) {
                        if (val == S[i].items[j]) {
                            printf("Container %d exists in stack %d.\n\n", val, i + 1);
                            found = true;
                            break;
                        }
                    }
                }
                if (!found) {
                    printf("Container %d not found in any stack.\n\n", val);
                }
                break;
            }
            case 4: {  // DISPLAY
                for (int i = 0; i < 3; i++) {
                    printf("--- Stack %d ---\n", i + 1);
                    display(S[i]);
                }
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}
