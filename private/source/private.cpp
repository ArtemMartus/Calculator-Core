//
// Created by Artem Martus on 10/7/19.
//


#include "private.h"
#include <cstdarg>
#include <iostream>

using namespace std;

bool checkFormat(const char* str) {
    if(!str)
	    return false;
    int eqCount = 0;


    if(eqCount > 1) // 0 or 1 '=' allowed currently
	    return false;
    //TODO: we should check further for typos
    return true;
}

abstract_tree_node* buildNode(const char* equation, abstract_tree_node* parent){
	if(!parent || !equation)
		return nullptr;

	abstract_tree_node* node = nullptr;
	//TODO: implement this
	return node;
}

void buildTreeHelper(abstract_tree *tree) {
	if(!tree)return;
    // look for operators with priority
    // tree->node->rawValue equals whole equation as a string
    const char* savedEquationString = tree->node->rawValue;
	tree->node->rawValue = "=";
	tree->node->type_code = 0;
//	int midIndex = stringFind(savedEquationString,tree->node->rawValue);
//	String subLeft = stringSub(savedEquationString,0,midIndex);
//	String subRight = stringSub(savedEquationString,midIndex+1,savedEquationString->size);
//
//	tree->node->right = buildNode(subRight,tree->node);
//	tree->node->left = buildNode(subLeft,tree->node);
}

bool checkIfTreeCanBeSolved(abstract_tree *tree) {
    return true; //TODO: implement this
}

void releaseTreeNode(abstract_tree_node *node) {
    if(!node)
	    return;
    releaseTreeNode(node->right);
    releaseTreeNode(node->left);
}

void *lib_malloc(size_t size, const char* purpose) {
	D(cout<<"Allocating "<<size<<" bytes for "<<purpose<<"\n");
	memory_used += size;
    return malloc(size);
}

void lib_free(void *pointer, const char* description, int size) {
    if(!pointer||!description||size<=0)
	    return;

	D(cout<<"Freeing pointer with description:[ "<<description<<" ]\n");
    free(pointer);
	memory_freed+=size;
}

const char *traverseNode(abstract_tree_node *node) {
	//TODO: implement traversing
	// left-most
	// current
	// right
    return "Hello world";
}

unsigned long memory_used=0;
unsigned long memory_freed=0;
