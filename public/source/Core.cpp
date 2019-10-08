#include "Core.h"
#include "private.h"
#include <iostream>

using namespace std;

abstract_tree *buildTree(const char *str) {
	if (!str)
		return 0;

	bool canBeSolved = false;
	bool isGoodFormat = false;
	abstract_tree *tree = 0;

	// If string has a good formatting we can allocate memory and build the tree
	// if its not - we only fill info property
	isGoodFormat = checkFormat(str);
	tree = (abstract_tree*)lib_malloc(sizeof(abstract_tree), "abstract tree");
	if (!tree)
		return 0; // Macro for quitting if memory allocation failed
	tree->info = (abstract_tree_info*)lib_malloc(sizeof(abstract_tree_info), "abstract tree info");
	if (!tree->info) {
		free(tree);
		return 0;
	}

	if (isGoodFormat) {
		// go build actual tree
		tree->node = (abstract_tree_node*)lib_malloc(sizeof(abstract_tree_node), "top node of abstract tree");
		if (!tree->node) {
			free(tree->info);
			free(tree);
		}
		tree->node->rawValue = str;
		buildTreeHelper(tree);
		canBeSolved = checkIfTreeCanBeSolved(tree);
	}

	if (tree->info) {
		tree->info->canBeSolved = canBeSolved;
		tree->info->isGoodFormat = isGoodFormat;
	}
	return tree;
}

void releaseTree(abstract_tree *tree) {
	if(!tree) return;
	if (tree->node) {
		releaseTreeNode(tree->node);
		lib_free(tree->node, "realising top tree node", sizeof(abstract_tree_node));
	}
	if (tree->info) {
		lib_free(tree->info, "releasing tree info", sizeof(abstract_tree_info));
	}
	lib_free(tree, "releasing tree", sizeof(abstract_tree));
}

abstract_tree *evaluateStep(abstract_tree *tree) {
	if(!tree) return 0;

	//TODO: implement some dark magic
	return tree; // try this for now
}

const char *traverseTree(abstract_tree *tree) {
	if(!tree)
		return 0;
	if(!tree->node)
		return 0;

	D(cout<<"Until now memory used "<<memory_used<<", memory freed "<<memory_freed<<endl)

	return traverseNode(tree->node);
}
