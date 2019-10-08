#pragma once

#include <structures.h>

abstract_tree*              buildTree(const char* str);
void                        releaseTree(abstract_tree* tree);
abstract_tree*              evaluateStep(abstract_tree* tree);
const char*                 traverseTree(abstract_tree* tree);
bool                        canTreeBeSolved(abstract_tree* tree);
bool                        isTreeWellFormatted(abstract_tree* tree);

