#include "Write.h"

error_t write_point(point_t* p, FILE* f)
{
	if (f == NULL || p == NULL)
		return ERR_INVALID_ARG;
	fprintf(f, "%d %d %d\n", p->x, p->y, p->z);
	return ERR_OK;
}

error_t write_edge(edge_t* e, FILE* f)
{
	if (f == NULL || e == NULL)
		return ERR_INVALID_ARG;
	fprintf(f, "%d %d\n", e->i1, e->i2);
	return ERR_OK;
}

error_t write_n_points(int n_points, FILE* f)
{
	if (n_points == NULL || f == NULL)
		return ERR_INVALID_ARG;

	fprintf(f, "%d\n", n_points);
	return ERR_OK;
}

error_t write_points(point_arr_t *p, FILE* f)
{
	if (p == NULL || f == NULL)
		return ERR_INVALID_ARG;

	error_t rc = ERR_OK;
	rc = write_n_points(p->n_points, f);
	for (int i = 0; i < p->n_points; i++)
		rc = write_point(&p->points[i], f);
	return rc;
}

error_t write_n_edges(int n_edges, FILE* f)
{
	if (n_edges == NULL || f == NULL) 
		return ERR_INVALID_ARG;

	fprintf(f, "%d\n", n_edges);
	return ERR_OK;
}

error_t write_edges(edge_arr_t *e, FILE* f)
{
	if (e == NULL || f == NULL) 
		return ERR_INVALID_ARG;
	if (e->edges == NULL) 
		return ERR_NO_OBJECT;

	error_t rc = ERR_OK;
	rc = write_n_edges(e->n_edges, f);
	for (int i = 0; i < e->n_edges; i++)
		rc = write_edge(&e->edges[i], f);
	return rc;
}

error_t write_figure(figure_t* fig, FILE* f)
{
	if (fig == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	rc = write_point(&fig->O, f);
	rc = write_points(&fig->p, f);
	if (rc == ERR_OK)
		write_edges(&fig->e, f);
	return rc;
}

error_t write_file(figure_t* fig, const load_t* ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	FILE* f = NULL;
	f = fopen(ch->path, "w");
	if (f == NULL)
		rc = ERR_FILE_OPEN;
	else
	{
		rc = write_figure(fig, f);
		fclose(f);
	}
	return rc;
}