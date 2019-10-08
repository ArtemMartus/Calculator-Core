#include "Core.h"
#include "private.h"
#include <iostream>

using namespace std;

abstract_tree *buildTree(const char *str) {
	if (!str)
		return 0;

	abstract_tree *tree = 0;

	// If string has a good formatting we can allocate memory and build the tree
	// if its not - we only fill info property

	if (checkFormat(str)) {
		// go build actual tree
		tree = (abstract_tree *) lib_malloc(sizeof(abstract_tree), "abstract tree");
		if (!tree) {
			D(cout << "Failed allocating memory for abstract tree" << endl)
			return 0; // Macro for quitting if memory allocation failed
		}
		// We will initialize properties of tree later on

		tree->info = (abstract_tree_info *) lib_malloc(sizeof(abstract_tree_info), "abstract tree info");
		if (!tree->info) {
			lib_free(tree, "failed tree info creation", sizeof(abstract_tree));
			return 0;
		} else {
			tree->info->canBeSolved = false;
			tree->info->isGoodFormat = true;
		}

		tree->node = (abstract_tree_node *) lib_malloc(sizeof(abstract_tree_node), "top node of abstract tree");
		if (!tree->node) {
			lib_free(tree->info, "failed tree node creation - tree_info", sizeof(abstract_tree_info));
			lib_free(tree, "failed tree node creation - tree", sizeof(abstract_tree));
			return 0;
		} else {
			// Initialize tree node with zeros
			tree->node->right = tree->node->left = tree->node->parent = 0;
			tree->node->type_code = 0;
		}

		tree->node->rawValue = str;
		buildTreeHelper(tree);
		tree->info->canBeSolved = checkIfTreeCanBeSolved(tree);

	} else {
		D(cout << str << " is not good formatted text" << endl)
		return 0;
	}

	return tree;
}

void releaseTree(abstract_tree *tree) {
	if (!tree) return;
	if (tree->node) {
		releaseTreeNode(tree->node);
		lib_free(tree->node, "realising top tree node", sizeof(abstract_tree_node));
		tree->node = 0;
	}
	if (tree->info) {
		lib_free(tree->info, "releasing tree info", sizeof(abstract_tree_info));
		tree->info = 0;
	}
	lib_free(tree, "releasing tree", sizeof(abstract_tree));
}

abstract_tree *evaluateStep(abstract_tree *tree) {
	if (!tree || !tree->node) return 0;

	//TODO: implement some dark magic
	return tree; // try this for now
}

const char *traverseTree(abstract_tree *tree) {
	if (!tree || !tree->node)
		return 0;

	return traverseNode(tree->node).c_str();
}

bool canTreeBeSolved(abstract_tree *tree) {
	if (!tree || !tree->node || !tree->info) return false;
	return tree->info->canBeSolved;
}

bool isWellFormatted(abstract_tree *tree) {
	if (!tree || !tree->node || !tree->info) return false;
	return tree->info->isGoodFormat;
}