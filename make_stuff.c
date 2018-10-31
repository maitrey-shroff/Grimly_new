#include "structs.h"
#include "header.h"

int   create_point(char c, t_maze_data *data, int y, int x)
{
    t_point *point;

    if (!(point = malloc(sizeof(t_point))))
        return (0);
    point->y = y;
    point->x = x;
    point->visited = 0;
    point->type = c;
    point->last = NULL;
    data->new_point = point;
    return (1);
}


int malloc_maze(t_maze_data *data)
{
    if (!(data->maze = malloc(sizeof(t_point **) * (data->row + 1))))
        return (0);
    int n = 0;
    while (n <= data->row)
    {
        if (!(data->maze[n] = malloc(sizeof(t_point *) * data->col)))
            return (0);
        n++;
    }
    return (1);
}

int malloc_que(t_maze_data *data)
{
	int size;

	size = data->row * data->col;
	data->max_que = size;
	if (!(data->que = malloc(sizeof(t_point *) * (size)))) //make this smaller based on empty char count
		return (0);
	return (1);
}