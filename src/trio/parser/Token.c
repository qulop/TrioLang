#include "Token.h"


Trio_Token* trio_createEmptyToken() {
    Trio_Token* ret = (Trio_Token*)malloc(sizeof(Trio_Token));
    ret->type = NONE_TOKEN;
    ret->lexeme = NULL;
    ret->line = 0;
    ret->column = 0;

    return ret;
}


Trio_Token* trio_createToken(Trio_TokenType type, const char* lexeme, size_t line, size_t column) {
    Trio_Token* ret = trio_createEmptyToken();
    ret->type = type;
    ret->lexeme = lexeme;
    ret->line = line;
    ret->column = column;

    return ret;
}