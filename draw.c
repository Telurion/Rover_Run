//
// Created by Corentin Monsallier on 21/10/2024.
//

#include "draw.h"
#include "moves.h"
#include "map.h"
#include "loc.h"
#include <stdlib.h>

#define NUM_MOVEMENTS 7
#define PHASES 9

int isInMap(t_localisation loc, t_map map) {

}

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

t_move *reduceMovesArray(t_move *moves, t_move move, int length) {
    t_move* new_moves = (t_move*) malloc(length*sizeof(t_move)-1);
    int j = 0;
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (move != moves[i] && found == 0) {
            new_moves[j] = moves[i];
        }
        else {
            new_moves[j]= moves[i-1];
        }
    }
    return new_moves;
}

p_node createNode(int idx, t_localisation loc, t_map map, t_node *parent, t_move precedent_move, t_move *remaining_move){
    t_node *my_node;
    my_node = (t_node *)malloc(sizeof(t_node));
    my_node->cost = map.costs[loc.pos.x][loc.pos.y];
    my_node->index = idx;
    my_node->nb_sons = PHASES-idx;
    my_node->sons = (t_node **)malloc((PHASES-idx)*sizeof(t_node *));
    my_node->parent = parent;
    my_node->loc = loc;
    my_node->precedent = precedent_move;
    my_node->remaining = reduceMovesArray(remaining_move, my_node->precedent, my_node->nb_sons);
    return my_node;
}