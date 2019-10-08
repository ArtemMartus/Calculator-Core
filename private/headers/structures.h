//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_STRUCTURES_H
#define CORE_STRUCTURES_H

#include "types.h"

/**
 * @brief Abstract tree structure container for abstract_tree_nodes
 */
struct abstract_tree {
    struct abstract_tree_info* info;
    struct abstract_tree_node* node;
};

/**
 * @brief Used to represent some descriptive data about structure
 */
struct abstract_tree_info{
    BOOL  canBeSolved;
    BOOL  isGoodFormat;
};

/**
 * @brief Binary tree node with type, raw value and pointers to neighbours
 */
struct abstract_tree_node{
    int type_code;
	const char* rawValue;
    struct abstract_tree_node* right;
    struct abstract_tree_node* left;
    struct abstract_tree_node* node;
    struct abstract_tree_node* parent;
};

#endif //CORE_STRUCTURES_H
