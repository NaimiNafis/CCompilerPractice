#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TypeSeparator;

typedef enum {
    EXIT,
} TypeKeyword;

typedef enum {
    INT,
} TypeLiteral;

typedef struct {
    TypeKeyword type;
} TokenKeyword;

typedef struct {
    TypeSeparator type;
} TokenSeparator;

typedef struct {
    TypeLiteral type;
    int value;
} TokenLiteral;

TokenLiteral *generate_number(char current, FILE *file){
    TokenLiteral *token = malloc(sizeof(TokenLiteral)); // allocate memory for TokenLiteral in heap. *token is a pointer that hold the address of the new allocated memory in heap.
    token -> type = INT; // -> used to access the fields of a struct through a pointer. usually use '.' like type.value.
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0;
    while (isdigit(current) && current != EOF){
        if (!isdigit(current)){
            break;
        }
        value[value_index] = current;
        value_index++;
        current = fgetc(file);
    }
    token->value = atoi(value); //converts the string of digits stored in value to an actual integer. 
    free(value); // remember to free the heap after use
    return(token);
}

void lexer(FILE *file){
    char current = fgetc(file);

    while(current != EOF){
        if (current == ';'){
            printf("FOUND SEMICOLON\n");
        } 
        else if (current == '('){
            printf("FOUND OPEN PAREN\n");
        }
        else if (current == ')'){
            printf("FOUND CLOSE PAREN\n");
        }
        else if (isdigit(current)){
            TokenLiteral *test_token = generate_number(current, file);
            printf("TEST TOKEN VALUE: %d\n", test_token->value);
            free(test_token);
        }
        else if (isalpha(current)){
            printf("FOUND CHARACTER: %c\n", current);
        }
        current = fgetc(file); //fgetc reads next character from the file pointed 
    }
}

int main() {
    FILE *file;
    file = fopen("test.unn", "r");
    lexer(file);
}