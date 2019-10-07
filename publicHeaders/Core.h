#ifndef CORE_CORE_H
#define CORE_CORE_H

#include "types.h"

struct abstract_tree*       buildTree(struct __tag_string* str);
void                        releaseTree(struct abstract_tree* tree);
struct abstract_tree*       evaluateStep(struct abstract_tree* tree);
const char*                 traverseTree(struct abstract_tree* tree);
BOOL                        canTreeBeSolved(struct abstract_tree* tree);
BOOL                        isTreeWellFormatted(struct abstract_tree* tree);

#endif //CORE_CORE_H