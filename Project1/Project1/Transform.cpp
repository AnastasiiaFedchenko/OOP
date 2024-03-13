#include "Transform.h"

// 1
error_t rotation_x(const point_t *O, point_t* p, const double angle_x)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.y = (int)(O->y + (p->y - O->y) * cos(angle_x) + (p->z - O->z) * sin(angle_x));
	temp.z = (int)(O->z - ((p->y - O->y) * sin(angle_x)) + (p->z - O->z) * cos(angle_x));
	p->y = temp.y;
	p->z = temp.z;
	return ERR_OK;
}
error_t rotation_y(const point_t *O, point_t* p, const double angle_y)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.x = (int)(O->x + (p->x - O->x) * cos(angle_y) - (p->z - O->z) * sin(angle_y));
	temp.z = (int)(O->z + ((p->x - O->x) * sin(angle_y)) + (p->z - O->z) * cos(angle_y));
	p->x = temp.x;
	p->z = temp.z;
	return ERR_OK;
}
error_t rotation_z(const point_t *O, point_t* p, const double angle_z)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.x = (int)(O->x + (p->x - O->x) * cos(angle_z) + (p->y - O->y) * sin(angle_z));
	temp.y = (int)(O->y - ((p->x - O->x) * sin(angle_z)) + (p->y - O->y) * cos(angle_z));
	p->x = temp.x;
	p->y = temp.y;
	return ERR_OK;
}

double to_radians(const double degrees)
{
	return (double)(degrees * M_PI) / 180;
}

error_t rotation(const figure_t *fig, const rotate_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	point_t* temp = (point_t*)malloc(fig->n_points * sizeof(point_t));
	if (temp == NULL)
		rc = ERR_MEM;
	else
		memcpy(temp, fig->points, fig->n_points * sizeof(point_t));
	for (int i = 0;rc == ERR_OK && i < fig->n_points; i++)
	{
		rc = rotation_x(&(fig->O), &temp[i], to_radians(ch->X));
		if (rc == ERR_OK)
			rc = rotation_y(&(fig->O), &temp[i], to_radians(ch->Y));
		if (rc == ERR_OK)
			rc = rotation_z(&(fig->O), &temp[i], to_radians(ch->Z));
	}
	if (rc == ERR_OK)
		memcpy(fig->points, temp, fig->n_points * sizeof(point_t));
	if (temp != NULL)
		free(temp);
	return rc;
}

// 2
error_t shift_x(point_t* p, const int dx)
{
	if (p == NULL)
		return ERR_INVALID_ARG;
	p->x += dx;
	return ERR_OK;
}
error_t shift_y(point_t* p, const int dy)
{
	if (p == NULL)
		return ERR_INVALID_ARG;
	p->y -= dy; // because coordinates are upside down
	return ERR_OK;
}
error_t shift_z(point_t* p, const int dz)
{
	if (p == NULL)
		return ERR_INVALID_ARG;
	p->z += dz;
	return ERR_OK;
}

error_t shift(figure_t *fig, const shift_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	point_t temp_O = fig->O;
	point_t* temp = (point_t*)malloc(fig->n_points * sizeof(point_t));
	if (temp == NULL)
		rc = ERR_MEM;
	else
		memcpy(temp, fig->points, fig->n_points * sizeof(point_t));
	rc = shift_x(&temp_O, ch->X);
	if (rc == ERR_OK)
		rc = shift_y(&temp_O, ch->Y);
	if (rc == ERR_OK)
		rc = shift_z(&temp_O, ch->Z);
	for (int i = 0; rc == ERR_OK && i < fig->n_points; i++)
	{
		rc = shift_x(&temp[i], ch->X);
		if (rc == ERR_OK)
			rc = shift_y(&temp[i], ch->Y);
		if (rc == ERR_OK)
			rc = shift_z(&temp[i], ch->Z);
	}
	if (rc == ERR_OK)
	{
		fig->O = temp_O;
		memcpy(fig->points, temp, fig->n_points * sizeof(point_t));
	}
	if (temp != NULL)
		free(temp);
	return rc;
}

// 3
error_t scaling_x(const point_t *O, point_t* p, double kx)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	p->x = (int)(O->x + kx * (p->x - O->x));
	return ERR_OK;
}

error_t scaling_y(const point_t *O, point_t* p, double ky)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	p->y = (int)(O->y + ky * (p->y - O->y));
	return ERR_OK;
}
error_t scaling_z(const point_t *O, point_t* p, double kz)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	p->z = (int)(O->z + kz * (p->z - O->z));
	return ERR_OK;
}

error_t scaling(const figure_t *fig, const scale_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	point_t* temp = (point_t*)malloc(fig->n_points * sizeof(point_t));
	if (temp == NULL)
		rc = ERR_MEM;
	else
		memcpy(temp, fig->points, fig->n_points * sizeof(point_t));
	for (int i = 0; rc == ERR_OK && i < fig->n_points; i++)
	{
		rc = scaling_x(&(fig->O), &temp[i], ch->X);
		if (rc == ERR_OK)
			rc = scaling_y(&(fig->O), &temp[i], ch->Y);
		if (rc == ERR_OK)
			rc = scaling_z(&(fig->O), &temp[i], ch->Z);
	}
	if (rc == ERR_OK)
		memcpy(fig->points, temp, fig->n_points * sizeof(point_t));
	if (temp != NULL)
		free(temp);
	return rc;
}


