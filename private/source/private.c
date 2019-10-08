//
// Created by Artem Martus on 10/7/19.
//


#include "private.h"
#include <stdarg.h>

BOOL checkFormat(const char* str) {
    SAFETY_RET(str, FALSE)
    int eqCount = 0;


    if(eqCount > 1) // 0 or 1 '=' allowed currently
	    return FALSE;
    //TODO: we should check further for typos
    return TRUE;
}

struct abstract_tree_node* buildNode(const char* equation, struct abstract_tree_node* parent){
	SAFETY(parent)
	SAFETY(equation)

	int addIndex = -1;
	struct abstract_tree_node* node = 0;
	//TODO: implement this
	return node;
}

void buildTreeHelper(struct abstract_tree *tree) {
	SAFETY_RET(tree,)
    // look for operators with priority
    // tree->node->rawValue equals whole equation as a string
    const char* savedEquationString = tree->node->rawValue;
	tree->node->rawValue = "=";
	tree->node->type_code = Equation;
//	int midIndex = stringFind(savedEquationString,tree->node->rawValue);
//	String subLeft = stringSub(savedEquationString,0,midIndex);
//	String subRight = stringSub(savedEquationString,midIndex+1,savedEquationString->size);
//
//	tree->node->right = buildNode(subRight,tree->node);
//	tree->node->left = buildNode(subLeft,tree->node);
}

BOOL checkIfTreeCanBeSolved(struct abstract_tree *tree) {
    return TRUE; //TODO: implement this
}

void releaseTreeNode(struct abstract_tree_node *node) {
	// Not using SAFETY because we don't really want 'failure' messages
    if(node == 0)
	    return;
    releaseTreeNode(node->right);
    releaseTreeNode(node->left);
}

void *lib_malloc(size_t size, const char* purpose) {
	lib_print("Allocating %d bytes for %s\n", size, purpose);
	memory_used += size;
    return malloc(size);
}

void lib_free(void *pointer, const char* description, int size) {
    SAFETY_RET(pointer,)

	lib_print("Freeing pointer with description:[ %s ]\n", description);
    free(pointer);
	memory_freed+=size;
}

const char *traverseNode(struct abstract_tree_node *node) {
	//TODO: implement traversing
	// left-most
	// current
	// right
    return "Hello world";
}

void *lib_realloc(void*ptr, unsigned long size, const char* purpose, int memory_change){
	memory_used += memory_change;
	lib_print("Reallocating %d bytes for %s\n", size, purpose);
	return realloc(ptr,size);
}

void lib_print(const char* format, ...) {
	// Not using SAFETY because it recursively loops lib_print
	if(format == 0)
		return;
	va_list arg;
    va_start(arg, format);
#ifdef PRINT_TO_STDOUT
    printf(format,arg);
#endif
    va_end(arg);
}

unsigned long memory_used=0;
unsigned long memory_freed=0;
