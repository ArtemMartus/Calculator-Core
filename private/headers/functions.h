//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H

BOOL checkFormat(const char *str);
void buildTreeHelper(struct abstract_tree *tree);
BOOL checkIfTreeCanBeSolved(struct abstract_tree* tree);
void releaseTreeNode(struct abstract_tree_node *node);
void *lib_malloc(unsigned long size, const char *purpose);
void lib_free(void *pointer, const char *description);
const char* traverseNode(struct abstract_tree_node* node);
void lib_print(const char* format,...);

#endif //CORE_FUNCTIONS_H
