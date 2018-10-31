#include "structs.h"
#include "header.h"

int file_maze(t_maze_data *data, char *file_name)
{
    int fd;

    if ((fd = open(file_name, O_RDONLY)) == -1)
        return (0);
    if (!(read_first_line_of_fd(data, fd)))
        return (0);
    if (!(read_full_maze(data, fd)))
        return (0);
    if (close(fd) == -1)
        return(0);
    return (1);
}

int stdin_maze(t_maze_data *data)
{
    if (!(read_first_line_of_fd(data, 0)))
        return (0);
    if (!(read_full_maze(data, 0)))
        return (0);
    return (1);
}

int read_first_line_of_fd(t_maze_data *data, int fd)
{
    char c;
    char ch[30];
    int n;
    int read_value;

    n = 0;
    while (((read_value = read(fd, &c, 1)) >= 0) && c != '\n')
    {
        ch[n++] = c;
    }
    if (read_value < 0 || n < 8)
        return (0);
    ch[n] = '\0';
    if (!(fill_data(ch, n, data)))
        return (0);
    return (1);
}

int get_dimensions(char *ch, t_maze_data *data)
{
    char *ptr;

    if (!(ptr = strchr(ch, 'x')))
        return (0);
    *ptr = '\0';
    data->col = atoi(ptr + 1);
    data->row = atoi(ch);
    return (1);
}

int fill_data(char *ch, int n, t_maze_data *data)
{
    data->obstacle = ch[n - 5];
    data->empty = ch[n - 4];
    data->path = ch[n - 3];
    data->entry = ch[n - 2];
    data->ext = ch[n - 1];
    ch[n - 5] = '\0';
    if (!(get_dimensions(ch, data)))
        return (0);
    return (1);
}