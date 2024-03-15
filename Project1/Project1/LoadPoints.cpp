#include "LoadPoints.h"

error_t alloca_points(point_arr_t* p)
{
	error_t rc = ERR_OK;
	p->points = (point_t*)malloc(p->n_points * sizeof(point_t));
	if (p->points == NULL)
		rc = ERR_MEM;
	return rc;
}

error_t load_n_points(int* n_points, FILE* f)
{
	error_t rc = ERR_OK;
	if (fscanf(f, "%d\n", n_points) != 1)
		rc = ERR_FILE_READ;
	return rc;
}

error_t load_point(point_t* p, FILE* f)
{
	if (f == NULL || p == NULL)
		return ERR_INVALID_ARG;

	error_t rc = ERR_OK;
	if (fscanf(f, "%d %d %d\n", &(p->x), &(p->y), &(p->z)) != 3)
		rc = ERR_FILE_READ;
	return rc;
}

error_t load_points(point_t* O, point_arr_t* p, FILE* f)
{
	error_t rc = ERR_OK;

	rc = load_point(O, f); // вводим точку O 
	rc = load_n_points(&(p->n_points), f); // вводим количество точек
	if (rc == ERR_OK)
	{
		rc = alloca_points(p);
		for (int i = 0; rc == ERR_OK && i < p->n_points; i++)
			rc = load_point(&(p->points)[i], f); // вводим точки
		if (rc == ERR_FILE_READ)
			free_points(p);
	}

	return rc;
}