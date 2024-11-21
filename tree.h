//
// Created by Corentin Monsallier on 21/11/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include "stack.h"
#include "map.h"
#include "moves.h"

typedef struct s_node
{
    int cost;
    int nb_sons;
    t_move move;
    struct s_node **sons;           //pointeur tous ce qui suivent (sur le fils)
    struct s_node *parent;          //pointeur sur parent
} t_node;
typedef struct s_node t_node, *p_node;

typedef struct
{
    t_node *root;
} t_tree;

p_node createNode(int cost, int nb_sons, t_move move, t_node **sons, t_node *parent);
t_tree createEmptyTree(int val_root);
t_move *getMovesArray();
//void addNodesToTree(p_node parent, t_move *remaining_moves);
t_tree createTreeWithCombinations(t_move *, int);
void printTree(p_node node, int depth);


#endif //UNTITLED1_TREE_H
