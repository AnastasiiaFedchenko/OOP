#include "FigureStruct.h"

figure_t init_figure()
{
	figure_t fig{};
	fig.O.x = 0;
	fig.O.y = 0;
	fig.O.z = 0;
	fig.p.n_points = 0;
	fig.p.points = NULL;
	fig.e.n_edges = 0;
	fig.e.edges = NULL;
	return fig;
}

error_t copy_figure(const figure_t *sc, figure_t *ds)
{
	if (sc == NULL || ds == NULL)
		return ERR_INVALID_ARG;
	ds->O = sc->O;
	ds->p.n_points = sc->p.n_points;
	ds->e.n_edges = sc->e.n_edges;
	ds->p.points = sc->p.points;
	ds->e.edges = sc->e.edges;
	return ERR_OK;
}

error_t copy_point(const point_t *sc, point_t *ds)
{
	if (sc == NULL || ds == NULL)
		return ERR_INVALID_ARG;
	ds->x = sc->x;
	ds->y = sc->y;
	ds->z = sc->z;
	return ERR_OK;
}

error_t copy_points(point_t* sc, point_t* ds, int n)
{
	error_t rc = ERR_OK;
	for (int i = 0; i < n; i++)
		rc = copy_point(&(sc[i]), &(ds[i]));
	return rc;
}

void free_points(point_arr_t *p)
{
	if (p->points != NULL)
		free(p->points);
}

void free_edges(edge_arr_t* e)
{
	if (e->edges != NULL)
		free(e->edges);
}

void free_figure(figure_t *fig)
{
	if (fig != NULL)
	{
		free_points(&(fig->p));
		free_edges(&(fig->e));
	}
}