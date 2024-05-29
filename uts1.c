#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
        s->top++;
        s->items[s->top] = value;   
}

char pop(Stack *s) {
        char value = s->items[s->top];
        s->top--;
        return value;   
}

int isEmpty(Stack *s) {
    return s->top == -1;
}
void reverseString(char *input) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }
    
    int index = 0;
    while (!isEmpty(&stack)) {
        input[index++] = pop(&stack);
    }
}

int main() {
    char input[100];
    printf("Masukkan sebuah string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("String asli: %s\n", input);
    reverseString(input);
    printf("String setelah dibalik: %s\n", input);

    return 0;
}