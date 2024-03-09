#include "Draw.h"

//using namespace System::Drawing;

void draw_line(Graphics^ g, Pen^ pen, figure_t* fig, int i, int offset_x, int offset_y)
{
	int t1 = fig->edges[i][0], t2 = fig->edges[i][1];
	g->DrawLine(pen, fig->points[t1].x + offset_x, fig->points[t1].y + offset_y,
			fig->points[t2].x + offset_x, fig->points[t2].y + offset_y);
}

void draw_figure(Graphics^ g, figure_t* fig, int offset_x, int offset_y)
{
	Pen^ pen = gcnew Pen(Color::Black);
	pen->Width = 3;
	for (int i = 0; i < fig->n_edges; i++)
	{
		draw_line(g, pen, fig, i, offset_x, offset_y);
	}
}