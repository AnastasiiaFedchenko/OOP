#pragma once

#define OK 0
#define ERROR 1

typedef struct point point_t;
typedef struct change change_t;
typedef struct figure figure_t;

struct point
{
	int x;
	int y;
	int z;
};

struct figure
{
	point_t O; // the center of the figure
	point_t* points;
	int n_points;
	int** edges;
	int n_edges;
};
