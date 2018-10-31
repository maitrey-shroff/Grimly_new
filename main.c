#include "structs.h"
#include "header.h"

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
    data->only_start = 0;
    data->current = 0;
    data->last_point = 0;
    data->can_exit = 1;
    data->steps = 0;
}

int main(int argc, char **argv)
{
    t_maze_data *data;
    char *current_file;

    if (!(data = malloc(sizeof(t_maze_data))))
        return (0);

    if (argc > 1)
    {
        while (--argc >= 1)
        {
            initialize_data(data);
            current_file = argv[argc];
            if (!(file_maze(data, current_file)))
            {
                printf("MAP ERROR\n");
                continue;
            }
            result(data); 
        }
    }
    else
    {
        initialize_data(data);
        if ((stdin_maze(data) == -1)) // if -1 then no stdin and continue
        {
            printf("ERROR\n Youfucked up");
            return (0);
        }
        result(data);
    }
    return (1);
}