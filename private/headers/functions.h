//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H

/**
 * @brief check formatting of input string whether it's good for processing
 * @param str input string
 * @return TRUE or FALSE
 */
BOOL checkFormat(String str);

/**
 * @brief Tree building helper method
 * @param equation string representation of text we have to parse into tree objects
 * @param parent reference to parent node
 * @return pointer to the tree node
 */
struct abstract_tree_node* buildNode(String equation, struct abstract_tree_node* parent);
/**
 * @brief Method that actually builds nodes for provided abstract $tree
 * @param tree must have
 */
void buildTreeHelper(struct abstract_tree *tree);

/**
 * @brief Simple function that tells us whether provided equation $tree can be solved
 * @param tree pointer to the tree we want to know if it's solvable or not
 * @return TRUE or FALSE values
 */
BOOL checkIfTreeCanBeSolved(struct abstract_tree* tree);
/**
 * @brief releaseTree helper method. It's point to recursively release all nodes
 * @param node root node to be released
 */
void releaseTreeNode(struct abstract_tree_node *node);
/**
 * @brief wrapper over standard void* malloc(void*) function that prints 'Allocating $size bytes for $purpose'
 * @param size size of memory needed in bytes
 * @param purpose is purpose of allocation
 * @return pointer to allocated memory from malloc(size)
 */
void *lib_malloc(unsigned long size, String purpose);
/**
 * @brief wrapper over standard free(void*) function prints 'freeing pointer with description [$description]
 * @param pointer pointer to memory that must be freed. If null - nothing happens
 * @param description to lib_print
 * @see free()
 */
void lib_free(void *pointer, String description, int size);
void *lib_realloc(void *ptr, unsigned long size, String purpose, int memory_change);
const char* traverseNode(struct abstract_tree_node* node);
void lib_print( String format,...);
int lib_strlen(const char* str);
String lib_itoa(int i);

extern unsigned long memory_used;
extern unsigned long memory_freed;


#endif //CORE_FUNCTIONS_H
