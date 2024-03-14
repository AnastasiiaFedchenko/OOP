#include "Write.h"

error_t write_point(FILE* f, point_t* p)
{
	if (f == NULL || p == NULL)
		return ERR_INVALID_ARG;
	fprintf(f, "%d %d %d\n", p->x, p->y, p->z);
	return ERR_OK;
}

error_t write_edge(FILE* f, edge_t* e)
{
	if (f == NULL || e == NULL)
		return ERR_INVALID_ARG;
	fprintf(f, "%d %d\n", e->i1, e->i2);
	return ERR_OK;
}

error_t write_points(figure_t* fig, FILE* f)
{
	if (fig == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	rc = write_point(f, &fig->O);
	fprintf(f, "%d\n", fig->n_points);
	for (int i = 0; i < fig->n_points; i++)
		rc = write_point(f, &fig->points[i]);
	return rc;
}

error_t write_edges(figure_t* fig, FILE* f)
{
	if (fig == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	fprintf(f, "%d\n", fig->n_edges);
	for (int i = 0; i < fig->n_edges; i++)
		rc = write_edge(f, &fig->edges[i]);
	return rc;
}

error_t write_figure(figure_t* fig, FILE* f)
{
	if (fig == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	write_points(fig, f);
	if (rc == ERR_OK)
		write_edges(fig, f);
	return rc;
}

error_t write_file(figure_t* fig, const load_t* ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	if (fig->points == NULL || fig->edges == NULL)
		return ERR_NO_OBJECT;
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