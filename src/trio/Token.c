#include "Token.h"


Trio_Token trio_createEmptyToken() {
    return Trio_Token {
        .type = NONE_TOKEN,
        .lexeme = NULL,
        .line = 0,
        .column = 0
    };
}


Trio_Token trio_createToken(Trio_TokenType type, const char* lexeme, size_t line, size_t column) {
    return Trio_Token {
        .type = type,
        .lexeme = lexeme,
        .line = line,
        .column = column
    };
}