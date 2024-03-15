#include "LoadEdges.h"

error_t alloca_edges(edge_arr_t* e)
{
	if (e == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	e->edges = (edge_t*)malloc(e->n_edges * sizeof(edge_t));
	if (e->edges == NULL)
		rc = ERR_MEM;
	return rc;
}

error_t load_edge(FILE* f, edge_t* e)
{
	if (f == NULL || e == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	if (fscanf(f, "%d %d\n", &(e->i1), &(e->i2)) != 2)
		rc = ERR_FILE_READ;
	return rc;
}

error_t load_n_edges(int* n_edges, FILE* f)
{
	if (n_edges == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	if (fscanf(f, "%d\n", n_edges) != 1)
		rc = ERR_FILE_READ;
	return rc;
}

error_t load_edges(edge_arr_t* e, FILE* f)
{
	if (e == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	rc = load_n_edges(&(e->n_edges), f);
	if (rc == ERR_OK)
	{
		rc = alloca_edges(e);
		for (int i = 0; rc == ERR_OK && i < e->n_edges; i++)
			rc = load_edge(f, &(e->edges)[i]);
		if (rc == ERR_FILE_READ)
			free_edges(e);
	}
	return rc;
}