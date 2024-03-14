#include "FigureStruct.h"

figure_t init_figure()
{
	figure_t fig{};
	fig.O.x = 0;
	fig.O.y = 0;
	fig.O.z = 0;
	fig.n_points = 0;
	fig.points = NULL;
	fig.n_edges = 0;
	fig.edges = NULL;
	return fig;
}

error_t copy_figure(const figure_t *sc, figure_t *ds)
{
	if (sc == NULL || ds == NULL)
		return ERR_INVALID_ARG;
	ds->O = sc->O;
	ds->n_points = sc->n_points;
	ds->n_edges = sc->n_edges;
	ds->points = sc->points;
	ds->edges = sc->edges;
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

void free_figure(figure_t *fig)
{
	if (fig != NULL)
	{
		if (fig->points != NULL)
			free(fig->points);
		if (fig->edges != NULL)
			free(fig->edges);
	}
}