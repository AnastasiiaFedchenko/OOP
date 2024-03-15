#include "Load.h"

error_t load_figure(figure_t* fig, FILE* f)
{
	if (fig == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	rc = load_points(&fig->O, &fig->p, f);// в функцию, точеки в отдельную структуру
	if (rc == ERR_OK)
		rc = load_edges(&fig->e, f); // если что-то пошло не так внутри, надо там же освобождать
	if (rc != ERR_OK)
		free_points(&fig->p); // освобождать только точки
	return rc;
}

error_t load(figure_t *fig, FILE* f)
{
	if (fig == NULL || f == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	figure_t new_fig = init_figure();

	rc = load_figure(&new_fig, f);

	if (rc == ERR_OK)
	{
		free_figure(fig);
		copy_figure(&new_fig, fig);
	}
	else if (rc == ERR_OK)
			rc = ERR_FILE_READ;
	
	return rc;
}

error_t read_file(figure_t* fig, const load_t* ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	FILE* f = NULL;
	f = fopen(ch->path, "r");
	if (f == NULL)
		rc = ERR_FILE_OPEN;
	else
	{
		rc = load(fig, f);
		fclose(f);
	}
	return rc;
}
