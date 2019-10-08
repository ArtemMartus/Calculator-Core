//
// Created by Artem Martus on 10/7/19.
//

#pragma once

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
	bool  canBeSolved;
	bool  isGoodFormat;
};

/**
 * @brief Binary tree node with type, raw value and pointers to neighbours
 */
struct abstract_tree_node{
    int type_code;
	const char* rawValue;
    abstract_tree_node* right;
    abstract_tree_node* left;
    abstract_tree_node* node;
    abstract_tree_node* parent;
};

