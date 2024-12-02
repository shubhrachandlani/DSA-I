#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int items[MAX];
    int top;
};

void init(struct Stack *s) {
    s->top = -1
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full, cannot push %d\n", value);
    } else {
        s->items[++(s->top)] = value;  // Increment top and add value
        printf("Pushed %d to the stack\n", value);
    }
}


int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot pop.\n");
        return -1;  // Returning -1 to indicate the stack is empty
    } else {
        printf("Popped %d from the stack\n", s->items[s->top]);
        return s->items[(s->top)--];  // Return the top value and decrement top
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    display(&stack);

    pop(&stack);
    display(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);  // Trying to pop from an empty stack

    return 0;
}