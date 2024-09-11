#include "TrioUtils.h"


void writeAndFlush(FILE* stream, const char* msg, ...) {
    va_list ap;
    va_start(ap, msg);

    vfprintf_s(stream, msg, ap);
    fflush(stream);

    va_end(ap);
}


const char* extraxtTextFromFile(const char* const path) {
    FILE* file = NULL;

    if (fopen_s(&file, path, "rb")) {
        writeAndFlush(stderr, "extraxtTextFromFile() : Failed to open file: %s\n", path);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(fileSize + 1);
    if (!buffer) {
        writeAndFlush(stderr, "extraxtTextFromFile() : Failed to allocate memory for buffer!\n");
        return NULL;
    }

    size_t bytesReaded = fread(buffer, sizeof(char), fileSize, file);
    if (bytesReaded != fileSize) {
        writeAndFlush(stderr, "extraxtTextFromFile() : Failed to read all necessary bytes from file \"%s\"(readed: %d, expect: %d)\n",
            path, bytesReaded, fileSize);
        
        return NULL;
    }

    fclose(file);
    buffer[fileSize] = '\0';

    return buffer;
}