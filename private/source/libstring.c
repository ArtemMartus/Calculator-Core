//
// Created by Artem Martus on 10/7/19.
//

#include "Core.h"
#include "private.h"

/// Can't use SAFETY in here
String createStr(const char* s,int size){
	if (!s) return 0;
	if(size<1) return 0;
	struct __tag_string temp;
	temp.pointer = "Allocation of a new string";
	temp.size = lib_strlen(temp.pointer)+1;
	String str = lib_malloc(sizeof(struct __tag_string),&temp);

	temp.pointer = "Allocating space for characters";
	temp.size = (int)strlen(temp.pointer)+1;
	str->pointer = lib_malloc(size,&temp);
	memcpy((void*)str->pointer,s,size);
	str->size = size;
	return str;
}

String copyString(String str){
	SAFETY(str)
	struct __tag_string temp;
	temp.pointer = "Creating string copy";
	temp.size = lib_strlen(temp.pointer)+1;
	String s = lib_malloc(sizeof(struct __tag_string),&temp);
	s->size = str->size;
	temp.pointer = "Allocating space for characters";
	temp.size = lib_strlen(temp.pointer)+1;
	s->pointer = lib_malloc(str->size,&temp);
	memcpy((void*)s->pointer,str->pointer,str->size);
	return s;
}

const char* toCString(String str){
	SAFETY(str)
	return str->pointer; // let it be like that, it's okay for now
}

/// Can't use SAFETY in here
void freeString(String str){
	if (!str) return;

	struct __tag_string temp;
	if(str->pointer) {
		temp.pointer = "Freeing string characters";
		temp.size =  lib_strlen(temp.pointer) + 1;
		lib_free((void *) str->pointer, &temp, str->size);
		str->pointer = 0;
		str->size = 0;
	}
	temp.pointer = "Freeing string structure";
	temp.size = lib_strlen(temp.pointer)+1;
	lib_free(str,&temp, sizeof(struct __tag_string));
}

int stringCount(String str,String pattern){
	SAFETY_RET(str,-1)
	SAFETY_RET(pattern,-1)
	if (str->size < pattern->size) return -1;
	int count = 0;

	int pos = 0;
	while (pos < str->size - pattern->size){
		BOOL matched = TRUE;
		for(int i = 0; i < pattern->size && matched; ++i)
			matched = *(str->pointer + pos + i) == *(pattern->pointer + i);

		if(matched) count++;
		pos++;
	}

	return  count;
}

int stringFind(String str, String pattern){
	SAFETY_RET(str,-1)
	SAFETY_RET(pattern,-1)
	if (str->size < pattern->size) return -1;

	int pos = 0;
	while (pos < str->size - pattern->size){
		BOOL matched = TRUE;
		for(int i = 0; i < pattern->size && matched; ++i)
			matched = *(str->pointer + pos + i) == *(pattern->pointer + i);

		if(matched)
			return pos;
		pos++;
	}

	return -1;
}

String stringSub(String str,int startIndex, int endIndex){
	SAFETY(str)
	if(startIndex>=endIndex) return 0;
	return createStr(str->pointer+startIndex,endIndex-startIndex);
}

void stringPrint(String str){
	SAFETY_RET(str,)
	for(int i = 0;i < str->size; ++i) {
		printf("%c", str->pointer[i]);
	}
}

void stringConcat(String a,String b){
	SAFETY_RET(a,)
	SAFETY_RET(b,)
	int totalSize = a->size - 1 + b->size;
	void* newPtr = 0;
	String temp = copyString(a);
	S_TEMP("Reallocating string for concatenation");
	newPtr = lib_realloc((void*)a->pointer,totalSize,TEMP_STR,totalSize-a->size);
	_S_TEMP
	if(newPtr){
		a->pointer = newPtr;
		memcpy((void*)a->pointer+a->size-1,b->pointer,b->size);
		a->size = totalSize;
	}else{
		S_TEMP("Failed reallocating memory");lib_print(TEMP_STR);_S_TEMP
	}
	_S(temp);
}