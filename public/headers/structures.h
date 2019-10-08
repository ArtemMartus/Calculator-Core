/**
 * @author Created by Artem Martus on 10/7/19.
 * @brief Core calculator public API structures describing header
*/

#pragma once

/**
 * @brief Abstract tree structure container for abstract_tree_nodes
 */
typedef struct {
    struct abstract_tree_info* info;
    struct abstract_tree_node* node;
}abstract_tree;

/**
 * @brief Used to represent some descriptive data about structure
 */
struct abstract_tree_info{
	int  canBeSolved;
	int  isGoodFormat;
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

