//
// Created by Corentin Monsallier on 21/10/2024.
//

#include "draw.h"
#include "moves.h"
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

t_move **getAllMoves(t_move moves){
    t_move **moves_set;
    moves_set = (t_move**)malloc(15120 * sizeof(t_move*)); //9*8*7*6*5 = 15120 because 5 elements ==> number of paths on a probability tree
    int index = 0;

    for(int i = 0; i < PHASES; i++) {
        for(int j = 0; j < PHASES; j++) {
            if (i != j) {
                for (int k = 0; k < PHASES; k++) {
                    if (i != k && j != k) {
                        for (int l = 0; l < PHASES; l++) {
                            if (i != l && j != l && k != l) {
                                for (int m = 0; m < PHASES; m++) {
                                    if (i != m && j != m && k != m && l != m) {
                                        moves_set[index] = (t_move*)malloc(5 * sizeof(t_move));
                                        moves_set[index][0] = i;
                                        moves_set[index][1] = j;
                                        moves_set[index][2] = k;
                                        moves_set[index][3] = l;
                                        moves_set[index][4] = m;
                                        index++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return moves_set;
}