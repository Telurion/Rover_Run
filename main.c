#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "tree.h"

#define NUM_MOVEMENTS 7
#define PHASES 9

int main() {
    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    t_move *moves = getMovesArray();

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);

    for (int i = 0; i < PHASES; i++) {
        printf("Move %d : %s\n", i+1, getMoveAsString(moves[i]));
    }

    t_tree tree = createTreeWithCombinations(moves);

    // Print the tree (for testing purposes, it may be large)
    printTree(tree.root, 0);
    return 0;
}
