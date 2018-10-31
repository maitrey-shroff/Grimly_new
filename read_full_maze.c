#include "structs.h"
#include "header.h"

void get_start_point(t_maze_data *data, int y, int x)
{
    data->start[0] = y;
    data->start[1] = x;
    data->only_start += 1;
}

int check_eol(int *x, int *y, t_maze_data *data)
{
    if ((*x) == data->col)
    {
        *x = 0;
        *y += 1;
        return (1);
    }
    return (0);
}

int check_char(char ch, t_maze_data *data)
{
    if (ch == data->entry || ch == data->ext)
        return (1);
    if (ch == data->path || ch == data->obstacle)
        return (1);
    if (ch == data->empty || ch == '\n')
        return (1);
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
        if (*buff == data->entry)
            get_start_point(data, y, x);
        if ((*buff == data->entry) && (data->only_start == 2))
            return (0);
        if (!(check_char(*buff, data)))
            return (0);
        if (*buff == '\n')
        {
            if (!(check_eol(&x, &y, data)))
                return (0);
            buff++;
        }
        if (!(create_point(*buff, data, y, x)))
            return (0);
        if (x <= data->col)
            data->maze[y][x] = data->new_point;
        else
            return (0);
        x++;
        if (*buff)
            buff++;
    }
    if (data->only_start == 1)
        return (1);
    return (0);
}

int read_full_maze(t_maze_data *data, int fd)
{
    ssize_t size;

    char *buff;
    if ((size = data->row + (data->row * data->col)) <= 0)
        return (0);
    if (!(buff = malloc(sizeof(char) * size + 1)))
        return (0);
    if (read(fd, buff, size) < 0)
        return (0);
    buff[size] = '\0';
    if (!(malloc_maze(data)))
        return (0);
    if (!(fill_maze(data, buff)))
        return (0);
    return (1);
}