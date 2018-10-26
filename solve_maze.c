#include "structs.h"
#include "header.h"
#define VISITED (temp.visited)
#define UP (point->y - 1)
#define DOWN (point->y + 1)
#define LEFT (point->x - 1)
#define RIGHT (point->x + 1)
#define OBSTACLE (temp.type == data->obstacle)
#define EXIT (temp.type == data->ext)




// void check_neighbors(t_point *point, t_maze_data *data)
// {
//     t_point temp;

//     if (UP < 0 || DOWN > data->row || LEFT < 0 || RIGHT > data->col)
//     {   
//         if ((UP >= 0))
//         {
//             temp = data->maze[point->y - 1][point->x];
//             if (!OBSTACLE && !VISITED && !EXIT)
//                 ;
//                 // add_que();

//         }
//     }
//     // check_top();
//     // score_node();
// }

// void score_node()
// {
// }

// void    make_que(t_maze_data *data)
// {
//     int size;

//     size = data->row * data->col;
//     if (!(data->que = malloc(sizeof(t_point) * size)))
//         return ;
//     memset(data->que, 0, size);
// }

// int solve_maze(t_maze_data *data)
// {
//     make_que(data);
//     // start_maze();
//     check_neighbors(&data->maze[data->start[0]][data->start[1]], data);

//     return (1);
// }