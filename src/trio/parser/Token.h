#ifndef __TRIO_TOKEN_H
#define __TRIO_TOKEN_H

#include <stdlib.h>
#include <stdint.h>


typedef enum {
    NONE_TOKEN = 0,

    // One-char tokens
    LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, SEMICOLON, COLON,
    MINUS, PLUS, STAR, SLASH,

    // Operators
    BANG, BANG_EQUAL,
    EQUAL, DOUBLE_EQUAL,
    GREATER, GREATER_OR_EQUAL,
    LESS, LESS_OR_EQUAL,
    ARROW, 

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keywords
    IF, ELSE, ELIF, SWITCH, AND, OR,
    TRUE, FALSE,
    FOR, WHILE, 
    FN, RETURN,
    CLASS, SUPER, THIS, METHOD,
    LET, TRIO_NULL,
    JMP, JO,
    
    TRIO_EOF
} Trio_TokenType;


typedef struct {
    Trio_TokenType type;
    const char* lexeme;
    size_t line;
    size_t column;
} Trio_Token;


Trio_Token* trio_createEmptyToken();
Trio_Token* trio_createToken(Trio_TokenType type, const char* lexeme, size_t line, size_t column);

#endif