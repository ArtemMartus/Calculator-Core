#pragma once

#include "structures.h"
// public API header must be in pure C
struct abstract_tree*              buildTree(const char* str);
void                        releaseTree(struct abstract_tree* tree);
struct abstract_tree*              evaluateStep(struct abstract_tree* tree);
const char*                 traverseTree(struct abstract_tree* tree);
//returns 0 or 1 for FALSE or TRUE
int                        canTreeBeSolved(struct abstract_tree* tree);
int                        isTreeWellFormatted(struct abstract_tree* tree);

