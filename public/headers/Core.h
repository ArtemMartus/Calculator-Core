/**
 * @brief Core library public C API header
 */

#pragma once

#ifndef __cplusplus

#define EXPORT
#include <stdbool.h>
#include <stdint.h>

#else

#define EXPORT extern "C"
#include <cstdbool>
#include <cstdint>

#endif

/**
 * @brief Function that builds abstract tree based on input string
 * @param str a string that contains equation
 * @return pointer to created tree structure or 0 if something has failed
 */
EXPORT struct abstract_tree *buildTree(const char *str);

/**
 * @brief Function that releases memory held by abstract tree
 * @param tree pointer to tree structure
 */
EXPORT void releaseTree(struct abstract_tree *tree);

/**
 * @brief Function that evaluates some thing in given equation
 * @param tree pointer to built abstract tree
 * @return pointer to the NEW modified tree. Check tree info to know whether we can calculate more
 */
EXPORT struct abstract_tree *evaluateStep(struct abstract_tree *tree);

/**
 * @brief Function that gives us string representation of given abstract tree
 * @param tree pointer to the abstract tree structure
 * @return 0 if failed, otherwise c-string
 */
EXPORT const char *traverseTree(struct abstract_tree *tree);

/**
 * @brief For programs that define abstract_tree* pointer as a void* pointer and cannot access info structure we can use this function
 * @param tree pointer to the abstract tree
 * @return tree->info->canBeSolved boolean
 */
EXPORT bool canTreeBeSolved(struct abstract_tree *tree);

/**
 * @brief For programs that define abstract_tree* pointer as a void* pointer and cannot access info structure we can use this function
 * @param tree pointer to the abstract tree
 * @return tree->info->isGoodFormat boolean
 */
EXPORT bool isWellFormatted(struct abstract_tree *tree);

/**
 * @brief returns internal allocated for abstract tree memory statistics
 */
EXPORT uint64_t statMemoryAllocated();

/**
 * @brief returns related to abstract tree statistics
 */
EXPORT uint64_t statMemoryFreed();