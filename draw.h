//
// Created by Corentin Monsallier on 21/10/2024.
//

#ifndef UNTITLED1_DRAW_H
#define UNTITLED1_DRAW_H

#include "stack.h"
#include "map.h"
#include "moves.h"
#include <stdbool.h>

typedef struct s_node
{
    int cost;
    int index;
    int nb_sons;

    struct s_node **sons;           //pointeur tous ce qui suivent (sur le fils)
    struct s_node *parent;          //pointeur sur parent
    t_localisation loc;             //position : t_localisation
    t_move precedent_move;               //mouvement précédent
    t_move* remaining_moves;              //possibilités de mouvement
    int nb_remaining_moves;
} t_node;
typedef struct s_node t_node, *p_node;

typedef struct s_tree
{
    p_node root;
} t_tree;


void freenode(t_node*);
t_move* getMovesArray();
t_move* reduceMovesArray(const t_move*, t_move);


#endif //UNTITLED1_DRAW_H
void buildTree(t_node* root, int depth, t_map* map, t_position start_coord);
int calculateNewCost(int currentCost, int move, t_soil terrain);
bool isLeaf(t_node* node);
t_node* findMinLeaf(t_node* root, int* minCost);
void freeMap(t_map* map);
t_map * initializeMap(int rows, int cols);