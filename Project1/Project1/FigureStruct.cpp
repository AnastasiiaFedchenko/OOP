#include "FigureStruct.h"

figure_t init_figure()
{
	figure_t fig;
	fig.O.x = 0;
	fig.O.y = 0;
	fig.O.z = 0;
	fig.n_points = 0;
	fig.points = NULL;
	fig.n_edges = 0;
	fig.edges = NULL;
	return fig;
}

void copy_figure(const figure_t *sc, figure_t *ds)
{
	ds->O = sc->O;
	ds->n_points = sc->n_points;
	ds->n_edges = sc->n_edges;
	ds->points = sc->points;
	ds->edges = sc->edges;
}

void free_figure(figure* fig)
{
	if (fig != NULL)
	{
		if (fig->points != NULL)
			free(fig->points);
		if (fig->edges != NULL)
			free(fig->edges);
	}
}