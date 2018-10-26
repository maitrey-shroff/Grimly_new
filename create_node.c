#include "structs.h"
#include "header.h"

int   create_point(char c, t_maze_data *data, int y, int x)
{
    t_point *point;

    if (!(point = malloc(sizeof(t_point))))
        return (0);
    point->i = 0;
    point->y = y;
    point->x = x;
    point->visited = 0;
    point->type = c;
    data->new_point = point;
    return (1);
}