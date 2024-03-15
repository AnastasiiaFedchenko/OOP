#pragma once
#include <stdlib.h>
#include "Errors.h"

typedef struct point point_t;
typedef struct edge edge_t;
typedef struct point_arr point_arr_t;
typedef struct edge_arr edge_arr_t;
typedef struct figure figure_t;

struct point
{
	int x;
	int y;
	int z;
};

struct edge
{
	int i1;
	int i2;
};

struct point_arr
{
	point_t* points;
	int n_points;
};

struct edge_arr
{
	edge_t* edges;
	int n_edges;
};

struct figure
{
	point_t O; // the center of the figure
	point_arr_t p;
	edge_arr_t e;	
};

figure_t init_figure();
error_t copy_figure(const figure_t* sc, figure_t* ds);
error_t copy_point(const point_t* sc, point_t* ds);
error_t copy_points(point_t* sc, point_t* ds, int n);
void free_points(point_arr_t* p);
void free_edges(edge_arr_t* e);
void free_figure(figure_t* fig);
