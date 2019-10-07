#include "Core.h"
#include "private.h"

struct abstract_tree *buildTree(const char *string) {
    BOOL canBeSolved = FALSE;
    BOOL isGoodFormat = FALSE;
    struct abstract_tree *tree = 0;

    // If string has a good formatting we can allocate memory and build the tree
    // if its not - we only fill info property
    isGoodFormat = checkFormat(string);

    tree = lib_malloc(sizeof(struct abstract_tree), "abstract tree");
    SAFETY(tree) // Macro for quitting if memory allocation failed
    tree->info = lib_malloc(sizeof(struct abstract_tree_info), "abstract tree info");
    SAFETY2(tree->info, tree)

    if (isGoodFormat) {
        // go build actual tree
        tree->node = lib_malloc(sizeof(struct abstract_tree_node), "top node of abstract tree");
        SAFETY3(tree->node, tree->info, tree)
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
        lib_free(tree->node,"realising top tree node");
    }
    if (tree->info) {
        lib_free(tree->info, "releasing tree info");
    }
    lib_free(tree, "releasing tree");
}

struct abstract_tree *evaluateStep(struct abstract_tree *tree) {
    SAFETY(tree)
    //TODO: implement some dark magic
    return tree; // try this for now
}

const char *traverseTree(struct abstract_tree *tree) {
    SAFETY(tree)
    SAFETY(tree->node)
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