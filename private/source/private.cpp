//
// Created by Artem Martus on 10/7/19.
//


#include "private.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool checkFormat(string str) {
	if (str.empty())
		return false;
	int eqCount = count(str.begin(), str.end(), '=');

	if (eqCount > 1) // 0 or 1 '=' allowed currently
		return false;

	/**
	 * Check out is[digit|graph|punct] on the bottom of that page:
	 * https://en.cppreference.com/w/cpp/string/byte/isdigit
	 */
	/// space = 0, num = 1, operator = 2
	int num = 0;
	for (char i : str) {
		auto c = (unsigned char) i;
		if (!isgraph(c))
			continue; /*num = 0;*/ /// We don't really want to store information about spaces
		else {
			if (isdigit(c)) {
				if (num == 0) num = 1;
				else if (num == 1) continue;
				else if (num == 2) num = 1;
			} else if (ispunct(c) && c != '.' && c != ',') {
				if (num == 0) num = 2;
				else if (num == 1) num = 2;
				else if (num == 2) return false; /// Currently it's not allowed to place two operators in a row
			} else {
				/// something not actually part of a math equation passed around
				return false;
			}
		}
	}


	return true;
}

abstract_tree_node *buildNode(string equation, abstract_tree_node *parent) {
	if (!parent || equation.empty())
		return nullptr;

	abstract_tree_node *node = nullptr;
	//TODO: implement this
	return node;
}

void buildTreeHelper(abstract_tree *tree) {
	if (!tree)return;
	// look for operators with priority
	// tree->node->rawValue equals whole equation as a string
	string savedEquationString = tree->node->rawValue;
	tree->node->rawValue = "=";
	tree->node->type_code = 0;
}

bool checkIfTreeCanBeSolved(abstract_tree *tree) {
	return true; //TODO: implement this
}

void releaseTreeNode(abstract_tree_node *node) {
	if (!node)
		return;
	releaseTreeNode(node->right);
	releaseTreeNode(node->left);
}

void *lib_malloc(size_t size, const string &purpose) {
	D(cout << "Allocating " << size << " bytes for " << purpose << "\n");
	memory_used += size;
	return malloc(size);
}

void lib_free(void *pointer, const string &description, size_t size) {
	if (!pointer || description.empty() || size == 0)
		return;

	D(cout << "Freeing pointer with description:[ " << description << " ]\n");
	free(pointer);
	memory_freed += size;
}

string traverseNode(abstract_tree_node *node) {
	//TODO: implement traversing
	// left-most
	// current
	// right
	return "Hello world";
}

uint64_t memory_used = 0;
uint64_t memory_freed = 0;
