#ifndef CORE_LIBRARY_H
#define CORE_LIBRARY_H

#ifndef BOOL
#define BOOL int
#define TRUE 1
#define FALSE 0
#endif


#define OPERATOR_ADD        0x0001
#define OPERATOR_SUB        0x0002
#define OPERATOR_MUL        0x0003
#define OPERATOR_DIV        0x0004

#define TYPE_OPERATOR       0x0005
#define TYPE_SPACING        0x0006
#define TYPE_LETTER         0x0007
#define TYPE_NUMBER         0x0008
#define TYPE_BRACKET        0x0009

#define FULLY_WRITTEN       0x000A
#define SHORTLY_WRITTEN     0x000B
#define BAD_FORMATTING      0x000C

void hello(void);
int isFullyWritten(const char* str);

#endif //CORE_LIBRARY_H