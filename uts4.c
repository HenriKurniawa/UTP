#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        char value = s->items[s->top];
        s->top--;
        return value;
    }
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int charToInt(char c) {
    return c - '0';
}

int main() {
    Stack stack;
    initStack(&stack);

    char input[] = "12345"; 
    int result = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        push(&stack, input[i]);
    }

    while (!isEmpty(&stack)) {
        char digit = pop(&stack);
        int intValue = charToInt(digit);
        result = result * 10 + intValue;
    }

    printf("hasil konversi (integert) : %d\n", result);

    return 0;
}