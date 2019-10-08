#include "Core.h"
#include "private.h"

struct abstract_tree *buildTree(const char* str) {
	SAFETY(str)

    BOOL canBeSolved = FALSE;
    BOOL isGoodFormat = FALSE;
    struct abstract_tree *tree = 0;

    // If string has a good formatting we can allocate memory and build the tree
    // if its not - we only fill info property
    isGoodFormat = checkFormat(str);
    tree = lib_malloc(sizeof(struct abstract_tree), "abstract tree");
	SAFETY(tree) // Macro for quitting if memory allocation failed
    tree->info = lib_malloc(sizeof(struct abstract_tree_info), "abstract tree info");
    SAFETY2(tree->info, tree)

    if (isGoodFormat) {
        // go build actual tree
        tree->node = lib_malloc(sizeof(struct abstract_tree_node), "top node of abstract tree");
        SAFETY3(tree->node, tree->info, tree)
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

void releaseTree(struct abstract_tree *tree) {
    SAFETY_RET(tree,)

    if (tree->node) {
        releaseTreeNode(tree->node);
        lib_free(tree->node,"realising top tree node", sizeof(struct abstract_tree_node));
    }
    if (tree->info) {
        lib_free(tree->info, "releasing tree info",sizeof(struct abstract_tree_info));
    }
    lib_free(tree, "releasing tree",sizeof(struct abstract_tree));
}

struct abstract_tree *evaluateStep(struct abstract_tree *tree) {
    SAFETY(tree)
    if (!tree->info->canBeSolved)
	    return tree;

    //TODO: implement some dark magic
    return tree; // try this for now
}

const char *traverseTree(struct abstract_tree *tree) {
    SAFETY(tree)
    SAFETY(tree->node)

	lib_print("Until now memory used %lu, memory freed %lu\n",memory_used,memory_freed);

	return traverseNode(tree->node);
}

BOOL canTreeBeSolved(struct abstract_tree* tree){
    SAFETY_RET(tree,FALSE)
    SAFETY_RET(tree->info,FALSE)
    return tree->info->canBeSolved;
}

BOOL isTreeWellFormatted(struct abstract_tree* tree){
    SAFETY_RET(tree,FALSE)
    SAFETY_RET(tree->info,FALSE)
    return tree->info->isGoodFormat;
}