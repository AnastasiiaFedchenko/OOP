#include "Controller.h"

error_t controller(const change_t* ch, const draw_t* ch_draw)
{
	if (ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	static figure_t fig = init_figure();
	if (rc == ERR_OK && ch->mode == ROTATION)
		rc = rotation(&fig, &(ch->rotation));
	else if (rc == ERR_OK && ch->mode == SHIFTING)
		rc = shift(&fig, &(ch->shifting));
	else if (rc == ERR_OK && ch->mode == SCALING)
		rc = scaling(&fig, &(ch->scaling));
	else if (ch->mode == LOADING)
		rc = read_file(&fig, &(ch->loading));
	else if (rc == ERR_OK && ch->mode == SAVING)
		rc = write_file(&fig, &(ch->loading));
	else if (rc == ERR_OK && ch->mode == DRAWING)
		rc = draw_figure(&fig, ch_draw);
	else if (rc == ERR_OK)
		rc = ERR_INVALID_ARG;
	return rc;
}