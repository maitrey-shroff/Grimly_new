#include "structs.h"
#include "header.h"

void    print_map(t_maze_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->row)
    {
        x = 0;
        while (x < data->col)
        {
            printf("%c", data->maze[y][x].type);
            x++;
        }
        y++;
        printf("\n");
    }
}