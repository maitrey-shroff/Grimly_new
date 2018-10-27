#include "structs.h"
#include "header.h"
#define VISITED (temp->visited)
#define UP (point->y - 1)
#define DOWN (point->y + 1)
#define LEFT (point->x - 1)
#define RIGHT (point->x + 1)
#define OBSTACLE (temp->type == data->obstacle)
#define EXIT (temp->type == data->ext)

void iterate_que(t_maze_data *data)
{
	t_point *current_point;
	current_point = &data->que[data->current];

	// printf("visited status of current before +1: %d\n", data->que[data->current].visited);
	current_point->visited++; // mark current point as visited
	// printf("visited status of current after = 1: %d\n", data->que[data->current].visited);
	// before calling check neighbors, score the point
	check_neighbors(current_point, data);
	printf("\n\nneighbors\nindex: %d\n", data->current);
	if (current_point->type != data->ext && data->current < data->max_que )
		iterate_que(data);
	else
		return ; //get x and y of exit
}

void add_to_que(t_point *point, t_maze_data *data)
{
	//data->que[data->last_point] = *point;
	data->que[data->last_point] = *point;
	printf("current point: '%c'\n", data->que[data->last_point].type);
	printf("visited status of current point when add to que: %d\n", data->que[data->current].visited);
	(data->last_point)++;
	printf("is it you0");
}


void check_neighbors(t_point *point, t_maze_data *data)
{
    t_point *temp;

    data->current++;

    printf("visited status of current in neighbor: %d\n", data->que[data->current].visited);
    // change score of node
	if (LEFT >= 0)
    {
    	temp = &(data->maze[point->y][LEFT]);
    	if (!OBSTACLE && !(VISITED))
    		add_to_que(temp, data);
    }
    if (UP >= 0)
    {
    	temp = &(data->maze[UP][point->x]);
    	if (!OBSTACLE && !(VISITED))
    		add_to_que(temp, data);
    }
    if (RIGHT <= data->col)
    {
    	temp = &(data->maze[point->y][RIGHT]);
    	if (!OBSTACLE && !(VISITED))
    		add_to_que(temp, data);
    }
    if (DOWN <= data->row)
    {
    	temp = &(data->maze[DOWN][point->x]);
    	if (!OBSTACLE && !(VISITED))
    		add_to_que(temp, data);
    }
}

void score_node()
{
}

void    malloc_que(t_maze_data *data)
{
    int size;

    size = data->row * data->col;
    data->max_que = size;
    if (!(data->que = malloc(sizeof(t_point) * size))) //make this smaller based on empty char count
        return ;
    // memset(data->que, 0, size);
}

int solve_maze(t_maze_data *data)
{
	t_point *start_point;
    malloc_que(data);
    // start_maze();
    start_point = &data->maze[data->start[0]][data->start[1]];
    printf("index: %d\n", data->current);
    add_to_que(start_point, data);
    iterate_que(data);
    // check_neighbors(&data->maze[data->start[0]][data->start[1]], data);

    return (1);
}