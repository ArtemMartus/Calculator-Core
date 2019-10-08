/**
 * @brief Core library public C API header
 */

#pragma once

#include "structures.h"

/**
 * @brief Function that builds abstract tree based on input string
 * @param str a string that contains equation
 * @return pointer to created tree structure or 0 if something has failed
 */
abstract_tree*      buildTree(const char* str);
/**
 * @brief Function that releases memory held by abstract tree
 * @param tree pointer to tree structure
 */
void                releaseTree(abstract_tree* tree);
/**
 * @brief Function that evaluates some thing in given equation
 * @param tree pointer to built abstract tree
 * @return pointer to the NEW modified tree. Check tree info to know whether we can calculate more
 */
abstract_tree*      evaluateStep(abstract_tree* tree);
/**
 * @brief Function that gives us string representation of given abstract tree
 * @param tree pointer to the abstract tree structure
 * @return 0 if failed, otherwise c-string
 */
const char*         traverseTree(abstract_tree* tree);
