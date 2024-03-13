#include "Draw.h"

error_t draw_figure(const figure_t* fig, const draw_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	int i1, i2;
	Pen^ pen = gcnew Pen(Color::Black);
	Graphics^ g = ch->e->Graphics;
	pen->Width = 3;
	for (int i = 0; i < fig->n_edges; i++)
	{
		i1 = fig->edges[i].i1, i2 = fig->edges[i].i2;
		g->DrawLine(pen, fig->points[i1].x + ch->offset_x, fig->points[i1].y + ch->offset_y,
			fig->points[i2].x + ch->offset_x, fig->points[i2].y + ch->offset_y);
	}
	return rc;
}