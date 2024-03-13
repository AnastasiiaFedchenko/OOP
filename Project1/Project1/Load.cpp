#include "Load.h"

error_t load_point(FILE* f, point_t* p)
{
	error_t rc = ERR_OK;
	if (fscanf(f, "%d ", &(p->x)) != 1)
		rc = ERR_FILE_READ;
	if (rc == ERR_OK && fscanf(f, "%d ", &(p->y)) != 1)
		rc = ERR_FILE_READ;
	if (rc == ERR_OK && fscanf(f, "%d\n", &(p->z)) != 1)
		rc = ERR_FILE_READ;
	return rc;
}

error_t load_edge(FILE* f, edge_t *e)
{
	error_t rc = ERR_OK;
	if (!(fscanf(f, "%d ", &(e->i1)) == 1 && fscanf(f, "%d\n", &(e->i2)) == 1))
		rc = ERR_FILE_READ;
	return rc;
}

error_t load_figure(figure_t *fig, const load_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	FILE* f = NULL;
	f = fopen(ch->path, "r");
	if (f == NULL)
		rc = ERR_FILE_OPEN;
	else
	{
		rc = load_point(f, &(fig->O)); // вводим точку O 
		if (rc == ERR_OK && fscanf(f, "%d\n", &(fig->n_points)) == 1) // вводим количество вершин
		{
			fig->points = (point_t*)malloc(sizeof(point_t) * fig->n_points);
			if (fig->points == NULL)
				rc = ERR_MEM;
			for (int i = 0; rc == ERR_OK && i < fig->n_points; i++)
				rc = load_point(f, &(fig->points[i])); // вводим точки
			if (rc == ERR_OK && fscanf(f, "%d\n", &(fig->n_edges)) == 1) // вводим количество рёбер
			{
				fig->edges = (edge_t *)malloc(fig->n_edges * sizeof(edge));
				if (fig->edges == NULL)
					rc = ERR_MEM;
				for (int i = 0; rc == ERR_OK && i < fig->n_edges; i++)
					rc = load_edge(f, &fig->edges[i]);
			}
			else if (rc == ERR_OK)
					rc = ERR_FILE_READ;
		}
		else if (rc == ERR_OK)
				rc = ERR_FILE_READ;
		fclose(f);
	}
	if (rc != ERR_OK)
		free_figure(fig);
	return rc;
}