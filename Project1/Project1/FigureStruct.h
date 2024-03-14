#pragma once
#include <stdlib.h>
#include "Errors.h"

typedef struct point point_t;
typedef struct edge edge_t;
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

struct figure
{
	point_t O; // the center of the figure
	point_t* points;
	int n_points;
	edge_t* edges;
	int n_edges;
};

figure_t init_figure();
error_t copy_figure(const figure_t* sc, figure_t* ds);
error_t copy_point(const point_t* sc, point_t* ds);
void free_figure(figure_t* fig);
