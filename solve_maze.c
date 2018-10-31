#include "structs.h"
#include "header.h"
#define VISITED (temp->visited)
#define UP ((*point)->y - 1)
#define DOWN ((*point)->y + 1)
#define LEFT ((*point)->x - 1)
#define RIGHT ((*point)->x + 1)
#define OBSTACLE (temp->type == data->obstacle)
#define EXIT (temp->type == data->ext)

int iterate_que(t_maze_data *data)
{
	t_point *current_point;
	current_point = data->que[data->current];
	if (data->current == data->last_point)
	{
		data->can_exit = 0;
		return(0);
	}
	check_neighbors(&current_point, data);
	if (current_point->type != data->ext)
	{	
		iterate_que(data);
	}
	else
		find_path(&current_point, data);
	return (1);
}

void add_to_que(t_point **point, t_maze_data *data)
{
	data->que[data->last_point] = *point;
	(*point)->visited += 1;
	data->last_point++;
}

void check_neighbors(t_point **point, t_maze_data *data)
{
	t_point *temp;

	if (UP >= 0)
	{
		temp = (data->maze[UP][(*point)->x]);
		if (!OBSTACLE && !(VISITED))
		{
			temp->last = *point;
			add_to_que(&temp, data);
		}
	}
	if (LEFT >= 0)
	{

		temp = (data->maze[(*point)->y][LEFT]);
		if (!OBSTACLE && !(VISITED))
		{
			temp->last = *point;
			add_to_que(&temp, data);
		}
	}

	if (RIGHT < data->col)
	{
		temp = (data->maze[(*point)->y][RIGHT]);
		if (!OBSTACLE && !(VISITED))
		{
			temp->last = *point;
			add_to_que(&temp, data);
		}
	}
	if (DOWN < data->row)
	{
		temp = (data->maze[DOWN][(*point)->x]);
		if (!OBSTACLE && !(VISITED))
		{
			temp->last = *point;
			add_to_que(&temp, data);
		}
	}
	data->current++;
}

int solve_maze(t_maze_data *data)
{
	t_point *start_point;
	if (!(malloc_que(data)))
		return (0);
	start_point = data->maze[data->start[0]][data->start[1]];
	add_to_que(&start_point, data);
	if (!(iterate_que(data)))
		return (0);
	return (1);
}