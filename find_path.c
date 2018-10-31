#include "structs.h"
#include "header.h"

void find_path(t_point **point, t_maze_data *data)
{
    t_point *current_point;

    current_point = *point;
    while (current_point)
    {
        if (!(current_point->type == data->ext || current_point->type == data->entry))
        {
            current_point->type = data->path;
            data->steps++;
        }
            current_point = current_point->last;
    }
}
