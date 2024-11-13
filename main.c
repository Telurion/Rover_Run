#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "draw.h"

#define NUM_MOVEMENTS 7
#define PHASES 9

int main() {
    t_move *moves = getMovesArray();
    t_move **all_moves = getAllMoves(*moves);
    t_map map = createMapFromFile("..\\maps\\example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }

    displayMap(map);
    for (int i = 0; i < PHASES; i++) {
        printf("Move %d : %s\n", i+1, getMoveAsString(moves[i]));
    }

    return 0;
}
