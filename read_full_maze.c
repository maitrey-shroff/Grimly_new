#include "structs.h"
#include "header.h"

void get_start_point(t_maze_data *data, int y, int x)
{
    data->start[0] = y;
    data->start[1] = x;
    data->only_start = 0;
}

int check_eol(int *x, int *y, t_maze_data *data)
{
    // printf("%i:  %i:\n", *x, data->col);
    if ((*x) == data->col)
    {
        *x = 0;
        *y += 1;
        return (1);
    }
    return (0);
    
}

int fill_maze(t_maze_data *data, char *buff)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (*buff)
    {
        if ((*buff == data->entry) && !(data->only_start))
            return (0);
        if (*buff == data->entry)
            get_start_point(data, y, x);
        //check if it's also a valid mark at each point
        if (*buff == '\n')
        {
            if (!(check_eol(&x, &y, data)))
                return (0);
            buff++;
        }
        if (!(create_point(*buff, data, y, x)))
            return (0);
        data->maze[y][x] = *(data->new_point);
        x++;
        if (*buff)
            buff++;
    }
    return (1);
}

int malloc_maze(t_maze_data *data)
{
    if (!(data->maze = malloc(sizeof(t_point) * data->row)))
        return (0);
    int n = 0;
    while (n <= data->row)
    {
        if (!(data->maze[n] = malloc(sizeof(t_point) * data->col)))
            return (0);
        n++;
    }
    return (1);
}

int read_full_maze(t_maze_data *data)
{
    ssize_t size;

    char *buff;
    if ((size = data->row + (data->row * data->col)) <= 0)
        return (0);
    if (!(buff = malloc(sizeof(char) * size + 1)))
        return (0);
    if (read(0, buff, size) < 0)
        return (0);
    buff[size] = '\0';
    if (!(malloc_maze(data)))
        return (0);
    if (!(fill_maze(data, buff)))
        return (0);
    return (1);
}