
#include <stdio.h>
#include "../so_long.h"

void print_map(t_map *map)
{
    for (int i = 0; i < map->rows; i++)
    {
        printf("%s\n", map->data[i]);
    }
}
