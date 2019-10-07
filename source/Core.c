#include "Core.h"
#include "private.h"

struct abstract_tree *buildTree(String str) {
	SAFETY(str)

    BOOL canBeSolved = FALSE;
    BOOL isGoodFormat = FALSE;
    struct abstract_tree *tree = 0;

    // If string has a good formatting we can allocate memory and build the tree
    // if its not - we only fill info property
    isGoodFormat = checkFormat(str);
	S_TEMP("abstract tree"); tree = lib_malloc(sizeof(struct abstract_tree), TEMP_STR);  _S_TEMP;
	SAFETY(tree) // Macro for quitting if memory allocation failed
    S_TEMP("abstract tree info"); tree->info = lib_malloc(sizeof(struct abstract_tree_info), TEMP_STR); _S_TEMP;
    SAFETY2(tree->info, tree)

    if (isGoodFormat) {
        // go build actual tree
        S_TEMP("top node of abstract tree");tree->node = lib_malloc(sizeof(struct abstract_tree_node), TEMP_STR);_S_TEMP;
        SAFETY3(tree->node, tree->info, tree)
        tree->node->rawValue = S_COPY(str);
        //buildTreeHelper(tree);
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
        S_TEMP("realising top tree node");
        lib_free(tree->node,TEMP_STR, sizeof(struct abstract_tree_node));
        _S_TEMP
    }
    if (tree->info) {
        S_TEMP("releasing tree info");
        lib_free(tree->info, TEMP_STR,sizeof(struct abstract_tree_info));
        _S_TEMP
    }
    S_TEMP("releasing tree");
    lib_free(tree, TEMP_STR,sizeof(struct abstract_tree));
    _S_TEMP
}

struct abstract_tree *evaluateStep(struct abstract_tree *tree) {
    SAFETY(tree)
    if (!tree->info->canBeSolved)
	    return tree;

    //TODO: implement some dark magic
    return tree; // try this for now
}

const char *traverseTree(struct abstract_tree *tree) {
    //SAFETY(tree)
    //SAFETY(tree->node)
    String str = S("hello");
	String str2 = S(" ");
	String str3 = S("world");

	printf("Printing string one:\t");
    stringPrint(str);
	printf("\nPrinting string two:\t");
	stringPrint(str3);
	printf("\n Concat one+two:\t");
	stringConcat(str,str2);
	stringConcat(str,str3);
	stringPrint(str);
	printf("\nString sub[1-4]:\t");
	String sub = stringSub(str,1,4);
	stringPrint(sub);
	int count = 0;
	S_TEMP("world\0");count = stringCount(str,TEMP_STR);_S_TEMP
	printf("\nFind 'world'times(%d):\t",count);
	String world = 0;
	S_TEMP("world\0");world = stringSub(str,stringFind(str,TEMP_STR),str->size);_S_TEMP
	stringPrint(world);

	_S(str);
	_S(str2);
	_S(str3);
	_S(sub);
	_S(world);

	printf("\nUntil now memory used %lu, memory freed %lu\n",memory_used,memory_freed);

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