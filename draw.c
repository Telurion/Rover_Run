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


p_node *createNode(int idx, t_localisation loc, t_map map, t_node *parent, t_move *remaining_move, t_move *precedent_move){
    p_node *my_node = (p_node *)malloc(sizeof(p_node));
    my_node->cost = map.costs[loc.pos.x][loc.pos.y];
    my_node->index = idx;
    my_node->nb_sons = PHASES-4-idx;
    my_node->sons = (t_node **)malloc((PHASES-idx)*sizeof(t_node *));                               ///
    my_node->parent = parent;
    my_node->loc = loc;
    my_node->precedent = precedent_move;
    my_node->remaining = reduceMovesArray(remaining_move, my_node->precedent, my_node->nb_sons);
    return my_node;
}


t_move *reduceMovesArray(t_move *moves, t_move move, int length) {
    t_move *new_moves = (t_move*) malloc(length*sizeof(t_move)-1);
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (move != moves[i]){
            if (found == 1) {
                new_moves[i-1] = moves[i];
            }
            else {
                new_moves[i] = moves[i];
            }
        }
        if (moves[i] == move) {
            found = 1;
        }
    }
    return new_moves;
}





//addChild












//createEmptyTree

//createTree

//getBestPath

//ifWinOrFail










void freenode(t_node* node) {
    if (!node) return;

    if (node->sons) {
        for (int i = 0; i < node->nb_sons; i++) {
            freenode(node->sons[i]);
        }
    }
    free(node->sons);
    node->sons = NULL;

    if (node->remaining_moves) {
        free(node->remaining_moves);
    }
    node->remaining_moves = NULL;
    free(node);
}


void buildTree(t_node * root, int depth, t_map* map, t_position start_coord) {
    if (depth == 0 || isValidLocalisation((start_coord, map->x_max, map->y_max)) {
        return;
    }

    for (int i = 0; i < 9; i++) {
        int newX = startX + (i % 3 - 1); // Calculate new X position
        int newY = startY + (i / 3 - 1); // Calculate new Y position
        t_position new_position = {newX, newY};

        if (!isValidLocalisation(new_position, map->x_max, map->y_max)) {
            t_node * child = malloc(sizeof(t_node));
            child->cost = calculateNewCost(root->cost, i, map->soils[newX][newY]);
            child->precedent_move = i;

            root->sons[i] = child;
            buildTree(child, depth - 1, map, new_position);
        } else {
            root->sons[i] = NULL; // Invalid move
        }
    }
}

// Calculate the new cost based on the terrain type
int calculateNewCost(int currentCost, int move, t_soil terrain) {
    int moveCost = 1; // Default cost
    if (terrain == ERG) moveCost *= 2; // Increased cost for ERG
    if (terrain == CREVASSE) return 10000; // High cost for crevasse
    return currentCost + moveCost;
}

bool isLeaf(t_node* node) {
    for (int i = 0; i < 9; i++) {
        if (node->sons[i] != NULL)
            return false;
    }
    return true;
}

// Free allocated memory for the map
void freeMap(t_map* map) {
    for (int i = 0; i < map->x_max; i++) {
        free(map->soils[i]);
        free(map->costs[i]);
    }
    free(map->soils);
    free(map->costs);
    free(map);
}