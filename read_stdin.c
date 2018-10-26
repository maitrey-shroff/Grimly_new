
#include "structs.h"
#include "header.h"

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

int read_first_line_of_fd(t_maze_data *data) //(add int fd) param
{
    char c;
    char ch[30];
    int n;
    int read_value;

    n = 0;
    while (((read_value = read(0, &c, 1)) >= 0) && c != '\n')
    {
        ch[n++] = c;
    }
    if (read_value < 0 || n <= 8)
        return (0);
    ch[n] = '\0';
    if (!(fill_data(ch, n, data)))
        return (0);
    return (1);
}

void test_me(t_maze_data *data)
{
    printf(
        "obstacle: %c\nempty: %c\npath: %c\nentry: %c\next: %c\nrow: %i\ncol: %i\nstart: %d, %d",
        data->obstacle, data->empty, data->path, data->entry, data->ext,
        data->row, data->col, data->start[0], data->start[1]);
}

void initialize_data(t_maze_data *data)
{
    memset(data->start, 0, sizeof(data->start)); // change to ft_memset
    data->row = 0;
    data->col = 0;
    data->entry = 42;
    data->ext = 42;
    data->empty = 42;
    data->path = 42;
    data->obstacle = 42;
    data->new_point = NULL;
    data->maze = NULL;
    data->only_start = 1;
}
    
int stdin_maze(t_maze_data *data)
{
    if (!(read_first_line_of_fd(data)))
        return (0);
    if (!(read_full_maze(data)))
        return (0);
    print_map(data);
    // test_me(data);
    return (1);
}

int main(void)
{   
     t_maze_data *data;

    if (!(data = malloc(sizeof(t_maze_data))))
        return (0);
    initialize_data(data); //initialize data
    if (!(stdin_maze(data)))
        printf("ERROR\n Youfucked up");
    // solve_maze(data);
}