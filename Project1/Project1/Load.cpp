#include "Load.h"

int load_point(FILE* f, point_t* p)
{
	int rc = OK;
	if (fscanf(f, "%d ", &(p->x)) != 1)
		rc = ERROR;
	if (rc == OK && fscanf(f, "%d ", &(p->y)) != 1)
		rc = ERROR;
	if (rc == OK && fscanf(f, "%d\n", &(p->z)) != 1)
		rc = ERROR;
	return rc;
}

figure_t* load_figure(const change_t ch)
{
	int rc = OK;
	FILE* f = NULL;
	figure_t* fig;
	if (ch.data.loading.N == 0)
		f = fopen("Cube.txt", "r");
	if (ch.data.loading.N == 1)
		f = fopen("Icosahedron.txt", "r");
	if (f != NULL)
	{
		fig = (figure_t*)malloc(sizeof(figure_t));
		if (fig != NULL)
		{
			if (load_point(f, &(fig->O)) == OK && fscanf(f, "%d\n", &(fig->n_points)) == 1)
			{
				fig->points = (point_t*)malloc(sizeof(point_t) * fig->n_points);
				if (fig->points == NULL)
					rc = ERROR;
				for (int i = 0; rc == OK && i < fig->n_points; i++)
					rc = load_point(f, &(fig->points[i]));
				if (rc == OK && fscanf(f, "%d\n", &(fig->n_edges)) == 1)
				{
					fig->edges = (int**)malloc(fig->n_edges * sizeof(int*));
					if (fig->edges == NULL)
						rc = ERROR;
					for (int i = 0; rc == OK && i < fig->n_edges; i++)
					{
						fig->edges[i] = (int *)malloc(2 * sizeof(int));
						if (fig->edges[i] == NULL || fscanf(f, "%d ", &(fig->edges[i][0])) != 1 || fscanf(f, "%d\n", &(fig->edges[i][1])) != 1)
							rc = ERROR;
					}
				}
			}
		}
		else
			rc = ERROR;
		fclose(f);
	}
	else
		rc = ERROR;
	return (rc == ERROR) ? NULL : fig;
}

void free_figure(figure *fig)
{
	if (fig != NULL)
	{
		if (fig->points != NULL)
			free(fig->points);
		if (fig->edges != NULL)
			for (int i = 0; i < fig->n_edges; i++)
				free(fig->edges[i]);
		free(fig);
	}
}