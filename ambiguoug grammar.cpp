#include <stdio.h>
#include <ctype.h>
void E();
void T();
void F();
char input[100];
int pos = 0;
int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input,"\n")] = 0;
    E();
    if (input[pos] == '\0') {
        printf("\nParsing successful. The expression is valid.\n");
    } else {
        printf("\nParsing failed. The expression is invalid.\n");
    }
    return 0;
}
void E() {
    T();
    while (input[pos] == '+' || input[pos] == '*') {
        printf("%c ", input[pos]);
        pos++;
        T();
    }
}
void T() {
    F();
    while (input[pos] == '*') {
        printf("%c ", input[pos]); 
        pos++;
        F();
    }
}
void F() {
    if (isdigit(input[pos]) || isalpha(input[pos])) {
        printf("%c ", input[pos]); 
        pos++;
    } else if (input[pos] == '(') {
        printf("%c ", input[pos]); // Print the opening parenthesis for demonstration
        pos++;
        E();
        if (input[pos] == ')') {
            printf("%c ", input[pos]); // Print the closing parenthesis for demonstration
            pos++;
        } else {
            printf("\nParsing failed. Missing closing parenthesis.\n");
            exit(1);
        }
    } else {
        printf("\nParsing failed. Unexpected character: %c\n", input[pos]);
        exit(1);
    }
}

