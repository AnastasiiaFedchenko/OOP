#include "Load.h"


error_t load_point(FILE* f, point_t* p)
{
	if (f == NULL || p == NULL)
		return ERR_INVALID_ARG;
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
	if (f == NULL || e == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	if (!(fscanf(f, "%d ", &(e->i1)) == 1 && fscanf(f, "%d\n", &(e->i2)) == 1))
		rc = ERR_FILE_READ;
	return rc;
}

error_t alloca_points(point_t** points, int* n_points)
{
	error_t rc = ERR_OK;
	(*points) = (point_t*)malloc((*n_points) * sizeof(point_t));
	if ((*points) == NULL)
		rc = ERR_MEM;
	return rc;
}

error_t load_points(point_t *O, point_t** points, int* n_points, FILE* f)
{
	error_t rc = ERR_OK;
	rc = load_point(f, O); // вводим точку O 
	if (rc == ERR_OK && fscanf(f, "%d\n", n_points) == 1) // вводим количество точек
	{
		rc = alloca_points(points, n_points);
		for (int i = 0; rc == ERR_OK && i < (*n_points); i++)
			rc = load_point(f, &(*points)[i]); // вводим точки
	}
	else
		if (rc == ERR_OK)
			rc = ERR_FILE_READ;
	return rc;
}

error_t alloca_edges(edge_t** edges, int* n_edges)
{
	error_t rc = ERR_OK;
	(*edges) = (edge_t*)malloc((*n_edges) * sizeof(edge_t));
	if ((*edges) == NULL)
		rc = ERR_MEM;
	return rc;
}

error_t load_edges(edge_t **edges, int *n_edges, FILE* f)
{
	error_t rc = ERR_OK;
	if (fscanf(f, "%d\n", n_edges) == 1) // вводим количество рёбер
	{
		rc = alloca_edges(edges, n_edges);
		for (int i = 0; rc == ERR_OK && i < (*n_edges); i++)
			rc = load_edge(f, &(*edges)[i]);
	}
	else
		rc = ERR_FILE_READ;
	return rc;
}

error_t load_figure(figure_t *fig, FILE* f)
{
	if (fig == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	figure_t new_fig = init_figure();
	rc = load_points(&new_fig.O, &new_fig.points, &new_fig.n_points, f);
	if (rc == ERR_OK)
		rc = load_edges(&new_fig.edges, &new_fig.n_edges, f);
	if (rc == ERR_OK)
	{
		free_figure(fig);
		copy_figure(&new_fig, fig);
	}
	else if (rc == ERR_OK)
			rc = ERR_FILE_READ;
	if (rc != ERR_OK)
		free_figure(&new_fig);
	return rc;
}

error_t read_file(figure_t* fig, const load_t* ch)
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
		rc = load_figure(fig, f);
		fclose(f);
	}
	return rc;
}
