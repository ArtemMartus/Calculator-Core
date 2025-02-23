//
// Created by Artem Martus on 10/7/19.
//

#pragma once

#include <iostream>
#include <cstring>

/**
 * @brief check formatting of input string whether it's good for processing
 * @param str input string
 * @return TRUE or FALSE
 */
bool checkFormat(std::string str);

/**
 * @brief Tree building helper method
 * @param equation string representation of text we have to parse into tree objects
 * @param parent reference to parent node
 * @return pointer to the tree node
 */
abstract_tree_node *buildNode(std::string equation, abstract_tree_node *parent);

/**
 * @brief Method that actually builds nodes for provided abstract $tree
 * @param tree must have
 */
void buildTreeHelper(abstract_tree *tree);

/**
 * @brief Simple function that tells us whether provided equation $tree can be solved
 * @param tree pointer to the tree we want to know if it's solvable or not
 * @return TRUE or FALSE values
 */
bool checkIfTreeCanBeSolved(abstract_tree *tree);

/**
 * @brief releaseTree helper method. It's point to recursively release all nodes
 * @param node root node to be released
 */
void releaseTreeNode(abstract_tree_node *node);

/**
 * @brief wrapper over standard void* malloc(void*) function that prints 'Allocating $size bytes for $purpose'
 * @param size size of memory needed in bytes
 * @param purpose is purpose of allocation
 * @return pointer to allocated memory from malloc(size)
 */
void *lib_malloc(size_t size, const std::string &purpose);

/**
 * @brief wrapper over standard free(void*) function prints 'freeing pointer with description [$description]
 * @param pointer pointer to memory that must be freed. If null - nothing happens
 * @param description to lib_print
 * @see free()
 */
void lib_free(void *pointer, const std::string &description, size_t size);

/**
 * @brief Helper function for going through the tree
 * @param node root tree node
 * @return string with text representation of abstract tree
 */
std::string traverseNode(abstract_tree_node *node);

/**
 * @brief Semi-debug internal property made for tracking lib_malloc acting
 */
extern uint64_t memory_used;

/**
 * @brief Semi-debug internal property made for tracking lib_free acting
 */
extern uint64_t memory_freed;

/**
 * @brief uncomment this to remove all debug print information
 * NDEBUG is standard C macro
 */
#ifndef NDEBUG
#define D(x) {x;}
#else
#define D(x)
#endif