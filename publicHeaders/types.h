//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_TYPES_H
#define CORE_TYPES_H

#ifndef BOOL
#define BOOL int
#define FALSE 0
#define TRUE !FALSE
#endif

#define RESULT_SUCCESS      0x00010A
#define RESULT_FAIL         0xC0CCCC

struct __tag_string{
    const char* pointer;
    int size;
};

#endif //CORE_TYPES_H
