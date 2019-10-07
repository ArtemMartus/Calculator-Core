//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_LIBSTRING_H
#define CORE_LIBSTRING_H

#include "types.h"

/**
 * @brief Create String from const char* and provided size
 * @param s Pointer to c-string
 * @param size size of values to be copied
 * @return pointer to String structure
 */
String createStr(const char* s,int size);
/**
 * @brief Copy String from existing one
 * @param str pointer to existing String
 * @return new String
 */
String copyString(String str);
const char* toCString(String str);
void freeString(String str);
int stringCount(String str,String pattern);
int stringFind(String str, String pattern);
String stringSub(String str, int startIndex, int endIndex);
void stringPrint(String str);
/**
 * @brief String concatenation function
 * @param a Initial string that will be modified
 * @param b String we concat to $a
 */
void stringConcat(String a,String b);

#endif //CORE_LIBSTRING_H
