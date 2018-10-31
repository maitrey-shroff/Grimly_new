#include "structs.h"
#include "header.h"

void first_line(t_maze_data *data)
{
    printf("%ix%i%c%c%c%c%c\n",
           data->row, data->col, data->obstacle, data->empty, data->path, data->entry, data->ext);
}

void print_map(t_maze_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->row)
    {
        x = 0;
        while (x < data->col)
        {
            printf("%c", data->maze[y][x]->type);
            x++;
        }
        y++;
        printf("\n");
    }
}

void steps(t_maze_data *data)
{
    printf("RESULT IN %i STEPS!\n", data->steps);
}

void result(t_maze_data *data)
{
    if (!(solve_maze(data)))
    {
        printf("MAP ERROR\n");
        return ;
    }
    if (!data->can_exit)
    {
        printf("MAP ERROR\n");
        return ;
    }
    first_line(data);
    print_map(data);
    steps(data);
}