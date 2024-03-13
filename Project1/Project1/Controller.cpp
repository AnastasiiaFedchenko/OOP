#include "Controller.h"

error_t controller(const change_t* ch, const draw_t* ch_draw)
{
	if (ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	static figure_t fig = init_figure();
	if (fig.points == NULL || fig.edges == NULL)
		rc = ERR_NO_OBJECT;
	if (rc == ERR_OK && ch->mode == ROTATION)
		rc = rotation(&fig, &(ch->rotation));
	else if (rc == ERR_OK && ch->mode == SHIFTING)
		rc = shift(&fig, &(ch->shifting));
	else if (rc == ERR_OK && ch->mode == SCALING)
		rc = scaling(&fig, &(ch->scaling));
	else if (ch->mode == LOADING)
	{
		figure_t new_fig = init_figure();
		rc = load_figure(&new_fig, &(ch->loading));
		if (rc == ERR_OK)
		{
			free_figure(&fig);
			copy_figure(&new_fig, &fig);
		}
	}
	else if (rc == ERR_OK && ch->mode == DRAWING)
	{
		if (ch_draw == NULL)
			rc = ERR_INVALID_ARG;
		else
			rc = draw_figure(&fig, ch_draw);
	}
	else if (rc == ERR_OK)
		rc = ERR_INVALID_ARG;
	return rc;
}