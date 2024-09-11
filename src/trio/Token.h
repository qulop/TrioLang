#ifndef __TRIO_TOKEN_H
#define __TRIO_TOKEN_H

#include <stdlib.h>


enum Trio_TokenType {
    NONE_TOKEN = 0,

    // One-char tokens
    LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, SEMICOLON,
    MINUS, PLUS, STAR, SLASH,

    // Two(or one)-char tokens
    BANG, BANG_EQUAL,
    EQUAL, DOUBLE_EQUAL,
    GREATER, GREATER_OR_EQUAL,
    LESS, LESS_OR_EQUAL,
    ARROW, COLON,

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keywords
    IF, ELSE, ELIF, SWITCH, AND, OR,
    TRUE, FALSE,
    FOR, WHILE, 
    FN, RETURN,
    CLASS, SUPER, THIS, METHOD,
    LET, NULL_TOKEN,
    JMP, JO,
    
    EOF_TOKEN
};


struct Trio_Token {
    const Trio_TokenType type;
    const char* lexeme;
    const size_t line;
    const size_t column;
};


Trio_Token trio_createEmptyToken();
Trio_Token trio_createToken(Trio_TokenType type, const char* lexeme, size_t line, size_t column);

#endif