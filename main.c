#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SEMI,
    OPEN_PAREN,
    CLSOE_PAREN,
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


int main() {
    TokenLiteral token;
    token.type = INT;
    token.value = 6;
    printf("%d\n", token.value);
    return 0;
}
