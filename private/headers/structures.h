//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_STRUCTURES_H
#define CORE_STRUCTURES_H

#include "types.h"

struct abstract_tree {
    struct abstract_tree_info* info;
    struct abstract_tree_node* node;
};

struct abstract_tree_info{
    BOOL  canBeSolved;
    BOOL  isGoodFormat;
};

struct abstract_tree_node{
    int type_code;
    char* rawValue;
    struct abstract_tree_node* right;
    struct abstract_tree_node* left;
    struct abstract_tree_node* node;
    struct abstract_tree_node* parent;
};

#endif //CORE_STRUCTURES_H
