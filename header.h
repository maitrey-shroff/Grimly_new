#ifndef HEADER_H
#define HEADER_H
#include "structs.h"

int get_dimensions(char *ch, t_maze_data *data);
int fill_data(char *ch, int n, t_maze_data *data);
int read_first_line_of_fd(t_maze_data *data);
void test_me(t_maze_data *data);
void initialize_data(t_maze_data *data);
int stdin_maze(t_maze_data *data);

int check_eol(int *x, int *y, t_maze_data *data);
void get_start_point(t_maze_data *data, int y, int x);
int read_full_maze(t_maze_data *data);
int malloc_maze(t_maze_data *data);
int fill_maze(t_maze_data *data, char *buff);

int create_point(char c, t_maze_data *data, int y, int x);

void print_map(t_maze_data *data);

int solve_maze(t_maze_data *data);
void    check_neighbors(t_point *point, t_maze_data *data);
void malloc_que(t_maze_data *data);

#endif