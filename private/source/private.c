//
// Created by Artem Martus on 10/7/19.
//


#include "private.h"
#include <stdarg.h>

BOOL checkFormat(String str) {
    SAFETY_RET(str, FALSE)
    int eqCount = 0;
    S_TEMP("="); eqCount=stringCount(str,TEMP_STR); _S_TEMP
    if(eqCount > 1) // 0 or 1 '=' allowed currently
	    return FALSE;
    //TODO: we should check further for typos
    return TRUE;
}

struct abstract_tree_node* buildNode(String equation, struct abstract_tree_node* parent){
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
    String savedEquationString = tree->node->rawValue;
	tree->node->rawValue = S("=");
	tree->node->type_code = Equation;
	int midIndex = stringFind(savedEquationString,tree->node->rawValue);
	String subLeft = stringSub(savedEquationString,0,midIndex);
	String subRight = stringSub(savedEquationString,midIndex+1,savedEquationString->size);

	tree->node->right = buildNode(subRight,tree->node);
	tree->node->left = buildNode(subLeft,tree->node);

	_S(subLeft);
	_S(subRight);
	_S(savedEquationString);
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
    _S(node->rawValue);
}

void *lib_malloc(size_t size, String purpose) {
	struct __tag_string temp;
	temp.pointer = "Allocating %d bytes for %s\n";
	temp.size = lib_strlen(temp.pointer)+1;
	lib_print(&temp, size, CS(purpose));
	memory_used += size;
    return malloc(size);
}

void lib_free(void *pointer, String description, int size) {
    SAFETY_RET(pointer,)
	struct __tag_string temp;
	temp.pointer = "Freeing pointer with description:[ %s ]\n";
	temp.size = lib_strlen(temp.pointer)+1;
	lib_print(&temp, CS(description));
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

int lib_strlen(const char* str){
	int count = 0;
	while (*str++ != 0)count++;
	return count;
}

void *lib_realloc(void*ptr, unsigned long size, String purpose, int memory_change){
	memory_used += memory_change;
	struct __tag_string temp;
	temp.pointer = "Reallocating %d bytes for %s\n";
	temp.size = lib_strlen(temp.pointer)+1;
	lib_print(&temp, size, CS(purpose));
	return realloc(ptr,size);
}

void lib_print(String format, ...) {
	// Not using SAFETY because it recursively loops lib_print
	if(format == 0)
		return;
	va_list arg;
    va_start(arg, format);
#ifdef PRINT_TO_STDOUT
    printf(CS(format),arg);
#endif
    va_end(arg);
}

unsigned long memory_used=0;
unsigned long memory_freed=0;

inline void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}

// function to reverse buffer[i..j]
char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}

// Iterative function to implement itoa() function in C
String lib_itoa(int value)
{
	char buffer[256]={0};
	int base = 10;

	// consider absolute value of number
	int n = abs(value);

	int i = 0;
	while (n)
	{
		int r = n % base;
		buffer[i++] = '0' + r;
		n = n / base;
	}

	if (i == 0)
		buffer[i++] = '0';

	// If base is 10 and value is negative, the resulting string
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0)
		buffer[i++] = '-';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return S(reverse(buffer, 0, i - 1));
}