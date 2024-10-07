#include <stdio.h>
#include <stdlib.h>

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
        printf("%c", current);
        current = fgetc(file); //fgetc reads next character from the file pointed 
    }
}

int main() {
    FILE *file;
    file = fopen("test.unn", "r");
    lexer(file);
}