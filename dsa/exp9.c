#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    char items[MAX];
    int top;
} Stack;
void initStack(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack *s, char item) {
    if (!isFull(s)) {
        s->items[++(s->top)] = item;
    } else {
        printf("Stack is full!\n");
    }
}

// Function to pop an item from the stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty!\n");
        return '\0'; // Return a null character if stack is empty
    }
}

// Function to reverse the string using stack
void reverseString(char *str) {
    Stack stack;
    initStack(&stack);
    
    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    // Pop all characters from the stack and overwrite the original string
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from the input if present
    str[strcspn(str, "\n")] = 0;

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}