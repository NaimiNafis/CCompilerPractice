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
            printf("FOUND DIGIT: %d\n", current - '0'); //converts to digit character because '0' is 48 in ASCII value
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