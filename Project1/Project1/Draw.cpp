#include "Draw.h"

error_t draw_edge(point_t* p1, point_t* p2, const draw_t* ch)
{
	if (p1 == NULL || p2 == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	Pen^ pen = gcnew Pen(Color::Black);
	Graphics^ g = ch->e->Graphics;
	pen->Width = 3;
	g->DrawLine(pen, p1->x + ch->offset_x, p1->y + ch->offset_y,
		p2->x + ch->offset_x, p2->y + ch->offset_y);
	return ERR_OK;
}

error_t draw_edges(const point_arr_t *p, const edge_arr_t *e, const draw_t* ch)
{
	if (p == NULL || e == NULL || ch == NULL)
		return ERR_INVALID_ARG;

	error_t rc = ERR_OK;
	int i1, i2;
	for (int i = 0; i < e->n_edges; i++)
	{
		i1 = e->edges[i].i1, i2 = e->edges[i].i2;
		rc = draw_edge(&p->points[i1], &p->points[i2], ch);
	}
	return rc;
}

error_t draw_figure(const figure_t* fig, const draw_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	if (fig->p.points == NULL || fig->e.edges == NULL)
		return ERR_NO_OBJECT;
	error_t rc = ERR_OK;
	rc = draw_edges(&fig->p, &fig->e, ch);
	
	return rc;
}