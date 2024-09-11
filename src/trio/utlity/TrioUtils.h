#ifndef __TRIO_UTILS_H
#define __TRIO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void writeAndFlush(FILE* stream, const char* msg, ...);

const char* extraxtTextFromFile(const char* const path);

#endif __TRIO_UTILS_H