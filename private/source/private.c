//
// Created by Artem Martus on 10/7/19.
//

#include "private.h"
#include <stdarg.h>


BOOL checkFormat(const char *str){
    return TRUE; //TODO: implement this
}

void buildTreeHelper(struct abstract_tree *tree){
    //TODO: implement this
}

BOOL checkIfTreeCanBeSolved(struct abstract_tree* tree){
    return TRUE; //TODO: implement this
}

void releaseTreeNode(struct abstract_tree_node *node){
    SAFETY_RET(node,)
    lib_free(node->left,"realising left node");
    lib_free(node->right,"realising right node");
}

void *lib_malloc(unsigned long size, const char *purpose){
    lib_print("Allocating %d bytes for %s\n",size,purpose);
    return malloc(size);
}

void lib_free(void *pointer, const char *description){
    SAFETY_RET(pointer,)
    lib_print("Freeing pointer with description:[%s]\n",description);
    free(pointer);
}

const char* traverseNode(struct abstract_tree_node* node){
    return "Hello world"; //TODO: implement this
}

void lib_print(const char* format,...){
    va_list arg;
    va_start(arg,format);
#ifdef PRINT_TO_STDOUT
    printf(format,arg);
#endif
    va_end(arg);
}