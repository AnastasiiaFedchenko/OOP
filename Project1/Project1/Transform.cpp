#include "Transform.h"
#include "Load.h"

error_t move_to_from_O(point_t* p, const point_t* O, bool to)
{
	if (p == NULL || O == NULL)
		return ERR_INVALID_ARG;
	int sign = 1;
	if (to == true)
		sign = -1;
	p->x = p->x + sign * O->x;
	p->y = p->y + sign * O->y;
	p->z = p->z + sign * O->z;
	return ERR_OK;
}

// 1
error_t rotation_x(point_t* p, const point_t* O, const double angle_x)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	point_t temp;
	error_t rc = ERR_OK;
	rc = copy_point(p, &temp);
	if (rc == ERR_OK)
	{

		temp.y = (int)(p->y * cos(angle_x) + (p->z * sin(angle_x)));
		temp.z = (int)(-(p->y * sin(angle_x)) + p->z * cos(angle_x));
		p->y = temp.y;
		p->z = temp.z;
	}
	return rc;
}
error_t rotation_y(point_t* p, const point_t* O, const double angle_y)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	point_t temp;
	error_t rc = ERR_OK;
	rc = copy_point(p, &temp);
	if (rc == ERR_OK)
	{ 
		temp.x = (int)(p->x * cos(angle_y) - (p->z * sin(angle_y)));
		temp.z = (int)((p->x * sin(angle_y)) + p->z * cos(angle_y));
		p->x = temp.x;
		p->z = temp.z;
	}
	return rc;
}
error_t rotation_z(point_t* p, const point_t* O, const double angle_z)
{
	if (O == NULL || p == NULL)
		return ERR_INVALID_ARG;
	point_t temp;
	error_t rc = ERR_OK;
	rc = copy_point(p, &temp);
	if (rc == ERR_OK)
	{
		temp.x = (int)(p->x * cos(angle_z) + p->y * sin(angle_z));
		temp.y = (int)(-(p->x * sin(angle_z)) + p->y * cos(angle_z));
		p->x = temp.x;
		p->y = temp.y;
	}
	return rc;
}

double to_radians(const double degrees)
{
	return (double)(degrees * M_PI) / 180;
}

error_t rotate_point(const point_t *O, point_t *p, const rotate_t* ch)
{
	if (O == NULL || p == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	rc = move_to_from_O(p, O, true);
	rc = rotation_x(p, O, to_radians(ch->X));
	if (rc == ERR_OK)
		rc = rotation_y(p, O, to_radians(ch->Y));
	if (rc == ERR_OK)
		rc = rotation_z(p, O, to_radians(ch->Z));
	rc = move_to_from_O(p, O, true);
	return rc;
}

error_t rotate_points(point_arr_t* p, point_t* O, const rotate_t* ch)
{
	if (O == NULL || p == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	if (p->points == NULL)
		return ERR_NO_OBJECT;

	error_t rc = ERR_OK;
	for (int i = 0; rc == ERR_OK && i < p->n_points; i++)
		rc = rotate_point(O, &(p->points[i]), ch);
	return rc;
}

error_t rotation(figure_t *fig, const rotate_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	if (fig->p.points == NULL || fig->e.edges == NULL)
		return ERR_NO_OBJECT;
	error_t rc = ERR_OK;
	rc = rotate_points(&fig->p, &fig->O, ch);

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

error_t shift_point(point_t *p, const shift_t* ch)
{
	if (p == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	rc = shift_x(p, ch->X);
	if (rc == ERR_OK)
		rc = shift_y(p, ch->Y);
	if (rc == ERR_OK)
		rc = shift_z(p, ch->Z);
	return rc;
}

error_t shift_points(point_t* O, point_arr_t* p, const shift_t* ch)
{
	if (O == NULL || p == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	if (p->points == NULL)
		return ERR_NO_OBJECT;

	error_t rc = ERR_OK;
	rc = shift_point(O, ch);
	for (int i = 0; rc == ERR_OK && i < p->n_points; i++)
		rc = shift_point(&(p->points[i]), ch);
	return rc;
}

error_t shift(figure_t *fig, const shift_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;

	error_t rc = ERR_OK;
	rc = shift_points(&fig->O, &fig->p, ch);
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

error_t scaling_point(const point_t* O, point_t* p, const scale_t* ch)
{
	if (O == NULL || p == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	error_t rc = ERR_OK;
	rc = scaling_x(O, p, ch->X);
	if (rc == ERR_OK)
		rc = scaling_y(O, p, ch->Y);
	if (rc == ERR_OK)
		rc = scaling_z(O, p, ch->Z);
	return rc;
}

error_t scaling_points(const point_t* O, point_arr_t *p, const scale_t* ch)
{
	if (O == NULL || p == NULL || ch == NULL)
		return ERR_INVALID_ARG;
	if (p->points == NULL)
		return ERR_NO_OBJECT;
	
	error_t rc = ERR_OK;
	for (int i = 0; rc == ERR_OK && i < p->n_points; i++)
		rc = scaling_point(O, &(p->points[i]), ch);
	return rc;
}

error_t scaling(figure_t *fig, const scale_t *ch)
{
	if (fig == NULL || ch == NULL)
		return ERR_INVALID_ARG;

	error_t rc = ERR_OK;
	rc = scaling_points(&fig->O, &fig->p, ch);

	return rc;
}


