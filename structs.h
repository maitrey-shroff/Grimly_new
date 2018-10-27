#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdio.h>  //printf
#include <stdlib.h> //atoi
#include <string.h> //strchr / strndup
#include <zconf.h>
#include <fcntl.h>


typedef struct s_point
{
    int i;
    int visited;
    char type;
    int x;
    int y;
    enum {entry, ext, empty, obstacle} e_type;
}   t_point;

typedef struct s_maze_data
{
    char entry;
    char ext;
    char empty;
    char path;
    char obstacle;
    int row;
    int col;
    int start[2];
    int only_start;
    int current;
    int last_point;
    t_point *que;
    t_point *new_point;
    t_point **maze;
    int max_que;
}                t_maze_data;

#endif