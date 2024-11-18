//
// Created by Corentin Monsallier on 21/10/2024.
//

#include "draw.h"
#include "moves.h"
#include "stack.h"
#include "queue.h"
#include "map.h"
#include "loc.h"
#include <stdlib.h>

#define NUM_MOVEMENTS 7
#define PHASES 9

t_move *getMovesArray() {
    int prob[NUM_MOVEMENTS] = {22, 37, 44, 51, 72, 93, 100};
    t_move *moves;
    moves = (t_move*)malloc(PHASES * sizeof(t_move));
    if (!moves) {
        return NULL;
    }

    for (int i=0; i < PHASES; i++) {
        int val = rand() % prob[6] + 1;
        int temp=-1;

        if (val <= prob[0]) {
            moves[i] = F_10;
            temp = 0;
        } else if (val <= prob[1]) {
            moves[i] = F_20;
            temp = 1;
        } else if (val <= prob[2]) {
            moves[i] = F_30;
            temp = 2;
        } else if (val <= prob[3]) {
            moves[i] = B_10;
            temp = 3;
        } else if (val <= prob[4]) {
            moves[i] = T_LEFT;
            temp = 4;
        } else if (val <= prob[5]) {
            moves[i] = T_RIGHT;
            temp = 5;
        } else if (val <= prob[6]) {
            moves[i] = U_TURN;
            temp = 6;
        } else {
            free(moves);
            return NULL;
        }

        if (temp > 0) {
            for (int j = temp; j < NUM_MOVEMENTS; j++) {
                prob[j]--;
            }
        }
    }
    return moves;
}

p_node createNode(int idx, t_localisation loc, t_map map, t_node *parent){
    t_node *my_node;
    my_node = (t_node *)malloc(sizeof(t_node));
    my_node->cost = map.costs[loc.pos.x][loc.pos.y];
    my_node->index = idx;
    my_node->nb_sons = PHASES-idx;
    my_node->nb_remaining_moves;
    my_node->sons = (t_node **)malloc((PHASES-idx)*sizeof(t_node *));
    my_node->parent = parent;

    my_node->loc = loc;             //position : t_localisation
    my_node->precedent_move;
    my_node->remaining_moves;
    return my_node;
}

t_move *reduceMovesArray(t_move *moves, t_move move) {

}

//Faire fonction avec un tableau de moov et un moov donné et qui renvoie le tableau sans le moov donné