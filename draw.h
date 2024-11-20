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
};
typedef struct s_node t_node, *p_node;

t_move *getMovesArray();


#endif //UNTITLED1_DRAW_H
bool isOutOfBounds(int x, int y, int rows, int cols);
void buildTree(t_node* root, int depth, t_map* map, int startX, int startY);
int calculateNewCost(int currentCost, int move, t_soil terrain);
bool isLeaf(t_node* node);
t_node* findMinLeaf(t_node* root, int* minCost);
void freeMap(t_map* map);
t_map * initializeMap(int rows, int cols);