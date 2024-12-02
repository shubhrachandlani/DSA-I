#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return -1;
    struct Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

int top(struct Node* top) {
    return (top == NULL) ? -1 : top->data;
}

int size(struct Node* top) {
    int count = 0;
    while (top) {
        count++;
        top = top->next;
    }
    return count;
}
int main() {
    struct Node* stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
  printf("Top: %d\n", top(stack));
 printf("Size: %d\n", size(stack));
printf("Popped: %d\n", pop(&stack));
  printf("Top: %d\n", top(stack));
 printf("Size: %d\n", size(stack));
 return 0;
}