//
// Created by Corentin Monsallier on 21/10/2024.
//

#ifndef UNTITLED1_DRAW_H
#define UNTITLED1_DRAW_H

#include "stack.h"
#include "map.h"
#include "moves.h"

typedef struct s_node
{
    int cost;
    int index;
    int nb_sons;

    struct s_node **sons;           //pointeur tous ce qui suivent (sur le fils)
    struct s_node *parent;          //pointeur sur parent
    t_localisation loc;             //position : t_localisation
    t_move precedent;          //mouvement précédent
    t_move* remaining;         //possibilités de mouvement
};
typedef struct s_node t_node, *p_node;

t_move *getMovesArray();


#endif //UNTITLED1_DRAW_H
