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
    int index;                      //index
    int nb_sons;                    //nb fils
    int nb_remaining_moves;

    struct s_node **sons;           //pointeur tous ce qui suivent (sur le fils)
    struct s_node *parent;          //pointeur sur parent
    t_localisation loc;             //position : t_localisation
    t_move precedent_move;          //mouvement précédent
    t_move* remaining_moves;         //possibilités de mouvement
};
typedef struct s_node t_node, *p_node;

t_move *getMovesArray();


#endif //UNTITLED1_DRAW_H
