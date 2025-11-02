#include <stdio.h>

void push(int stack[], int* top, int maxSize){
    int value;
    if (*top == maxSize - 1)
        printf("Stack is Overflow it cant insert more elements.\n");
    else {
        printf("Enter value to Push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("Value %d is pushed successfully!\n", value);
    }
}

void pop(int stack[], int* top){
    if (*top == -1)
        printf("Stack Underflow, theres no any element to pop.\n");
    else {
        printf("Value %d is popped successfully!\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int top){
    if (top == -1)
        printf("Stack is empty, no top element.\n");
    else
        printf("Top element is: %d\n", stack[top]);
}

void display(int stack[], int top){
    int i;
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements (top to bottom):\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main(){
    int stack[50];
    int top = -1, choice, maxSize;

    printf("Enter max size of stack (1-50): ");
    scanf("%d", &maxSize);

    if (maxSize > 50 || maxSize <= 0) {
        printf("Invalid size. Size must be between 1 and 50.\n");
        printf("Setting size to 50.\n");
        maxSize = 50;
    }

    do {
        printf("\nMenu:\n\t1. PUSH\n\t2. POP\n\t3. PEEK\n\t4. DISPLAY\n\t5. EXIT\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1: {
                push(stack, &top, maxSize);
                break;
            }
            case 2: {
                pop(stack, &top);
                break;
            }
            case 3: {
                peek(stack, top);
                break;
            }
            case 4: {
                display(stack, top);
                break;
            }
            case 5: {
                printf("Thank you :)\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (choice != 5);

    return 0;
}
