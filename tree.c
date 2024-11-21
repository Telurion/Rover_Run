//
// Created by Corentin Monsallier on 21/11/2024.
//

#include "tree.h"
#include "moves.h"
#include "map.h"
#include "loc.h"
#include <stdlib.h>
#include <stdio.h>

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

p_node createNode(int cost, int nb_sons, t_move move, t_node **sons, t_node *parent) {
    p_node my_node = (p_node)malloc(sizeof(t_node));
    my_node->cost = cost;
    my_node->nb_sons = nb_sons;
    my_node->move = move;
    my_node->sons = sons;
    my_node->parent = parent;
    return my_node;
}

t_tree createEmptyTree(int val_root) {
    t_tree t;
    t.root = createNode(val_root, 0, NO_MOVE, NULL, NULL);
    return t;
}

void addNodesToTree(int nb_possibilities, t_localisation robot, t_map map, p_node parent, t_move *remaining_moves) {

    //if a faire pour verifier si infos okk
    for (int i = 0; i < nb_possibilities; i++) {
        t_localisation new_robot_loc = robot;
        updateLocalisation(&new_robot_loc, remaining_moves[i]);
        if (isValidLocalisation(new_robot_loc.pos, map.x_max, map.y_max)) {
            // faire le new node
        }
        else {
            //mettre les nodes a 0
        }
    }
}

t_tree createTreeWithCombinations(t_move *moves, int val_root) {
    t_tree tree = createEmptyTree(val_root);
    addNodesToTree(tree.root, moves);

    return tree;
}