#include "Transform.h"

// 1
void rotation_x(const point_t O, point_t* p, const double angle_x)
{
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.y = (int)(O.y + (p->y - O.y) * cos(angle_x) + (p->z - O.z) * sin(angle_x));
	temp.z = (int)(O.z - ((p->y - O.y) * sin(angle_x)) + (p->z - O.z) * cos(angle_x));
	p->y = temp.y;
	p->z = temp.z;
}
void rotation_y(const point_t O, point_t* p, const double angle_y)
{
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.x = (int)(O.x + (p->x - O.x) * cos(angle_y) - (p->z - O.z) * sin(angle_y));
	temp.z = (int)(O.z + ((p->x - O.x) * sin(angle_y)) + (p->z - O.z) * cos(angle_y));
	p->x = temp.x;
	p->z = temp.z;
}
void rotation_z(const point_t O, point_t* p, const double angle_z)
{
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.x = (int)(O.x + (p->x - O.x) * cos(angle_z) + (p->y - O.y) * sin(angle_z));
	temp.y = (int)(O.y - ((p->x - O.x) * sin(angle_z)) + (p->y - O.y) * cos(angle_z));
	p->x = temp.x;
	p->y = temp.y;
}

double to_radians(const double degrees)
{
	return (double)(degrees * M_PI) / 180;
}

void rotation(const figure_t *fig, const change_t ch)
{
	for (int i = 0; i < fig->n_points; i++)
	{
		rotation_x(fig->O, &fig->points[i], to_radians(ch.data.rotation.X));
		rotation_y(fig->O, &fig->points[i], to_radians(ch.data.rotation.Y));
		rotation_z(fig->O, &fig->points[i], to_radians(ch.data.rotation.Z));
	}
}

// 2
void shift_x(point_t* p, const int dx)
{
	p->x += dx;
}
void shift_y(point_t* p, const int dy)
{
	p->y -= dy; // because coordinates are upside down
}
void shift_z(point_t* p, const int dz)
{
	p->z += dz;
}

void shift(figure_t *fig, const change_t ch)
{
	shift_x(&fig->O, ch.data.shifting.X);
	shift_y(&fig->O, ch.data.shifting.Y);
	shift_z(&fig->O, ch.data.shifting.Z);
	for (int i = 0; i < fig->n_points; i++)
	{
		shift_x(&fig->points[i], ch.data.shifting.X);
		shift_y(&fig->points[i], ch.data.shifting.Y);
		shift_z(&fig->points[i], ch.data.shifting.Z);
	}
}

// 3
void scaling_x(const point_t O, point_t* p, double kx)
{
	p->x = (int)(O.x + kx * (p->x - O.x));
}

void scaling_y(const point_t O, point_t* p, double ky)
{
	p->y = (int)(O.y + ky * (p->y - O.y));
}
void scaling_z(const point_t O, point_t* p, double kz)
{
	p->z = (int)(O.z + kz * (p->z - O.z));
}

void scaling(const figure_t *fig, const change_t ch)
{
	for (int i = 0; i < fig->n_points; i++)
	{
		scaling_x(fig->O, &fig->points[i], ch.data.scaling.X);
		scaling_y(fig->O, &fig->points[i], ch.data.scaling.Y);
		scaling_z(fig->O, &fig->points[i], ch.data.scaling.Z);
	}
}

figure_t *controller(figure_t *fig, const change_t ch)
{
	if (ch.mode == 1)
		rotation(fig, ch);
	else if (ch.mode == 2)
		shift(fig, ch);
	else if (ch.mode == 3)
		scaling(fig, ch);
	else if (ch.mode == 4)
	{
		free_figure(fig);
		figure_t *new_fig = load_figure(ch);
		return new_fig;
	}
	return NULL;
}

