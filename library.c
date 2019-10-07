#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFullyWritten(const char* str){
    if(strlen(str)<=0) return BAD_FORMATTING;
    int eqCount = 0;
    char* c = str;
    while (*c++) if(*c == '=') eqCount++;
    if(eqCount == 1) return FULLY_WRITTEN;
    if(eqCount == 0) return SHORTLY_WRITTEN;
    return BAD_FORMATTING;
}



void hello(void) {
    printf("Hello, World!\n");
}