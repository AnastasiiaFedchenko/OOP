#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES 
#include <math.h>

typedef struct point point_t;
typedef struct change change_t;
typedef struct figure figure_t;
struct point
{
	int x;
	int y;
	int z;
};

struct figure
{
	point_t* points;
	int n_points;
	int** edges;
	int n_edges;
};

struct change
{
	int mode; // 1 - ratation, 2 - shift, 3 - scaling
	double X;
	double Y; 
	double Z;
};

void rotation_x(point_t* p, double angle_x)
{
	point_t temp;
	memcpy( &temp, p, sizeof(point_t));
	temp.y = (int)(p->y * cos(angle_x) + p->z * sin(angle_x));
	temp.z = (int)(- (p->y * sin(angle_x)) + p->z * cos(angle_x));
	p->y = temp.y;
	p->z = temp.z;
}
void rotation_y(point_t* p, double angle_y)
{
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.x = (int)(p->x * cos(angle_y) - p->z * sin(angle_y));
	temp.z = (int)(- (p->x * sin(angle_y)) + p->z * cos(angle_y));
	p->x = temp.x;
	p->z = temp.z;
}
void rotation_z(point_t* p, double angle_z)
{
	point_t temp;
	memcpy(&temp, p, sizeof(point_t));
	temp.x = (int)(p->x * cos(angle_z) + p->y * sin(angle_z));
	temp.y = (int)(- (p->x * sin(angle_z)) + p->y * cos(angle_z));
	p->x = temp.x;
	p->y = temp.y;
}

double to_radians(double degrees)
{
	return (double)(degrees * M_PI) / 180;
}

void rotation(figure_t fig, change_t ch)
{
	for (int i = 0; i < fig.n_points; i++)
	{
		rotation_x(&fig.points[i], to_radians(ch.X));
		rotation_y(&fig.points[i], to_radians(ch.Y));
		rotation_z(&fig.points[i], to_radians(ch.Z));
	}
}

void shift_x(point_t* p, int dx) 
{
	p->x += dx;
}
void shift_y(point_t* p, int dy) 
{
	p->y -= dy; // because coordinates are upside down
}
void shift_z(point_t* p, int dz) 
{
	p->z += dz;
}

void shift(figure_t fig, change_t ch)
{
	for (int i = 0; i < fig.n_points; i++)
	{
		shift_x(&fig.points[i], ch.X);
		shift_x(&fig.points[i], ch.Y);
		shift_x(&fig.points[i], ch.Z);
	}
}

void scaling_x(point_t* p, double kx)
{
	p->x = (int)(kx * p->x);
}

void scaling_y(point_t* p, double ky)
{
	p->y = (int)(ky * p->y);
}
void scaling_z(point_t* p, double kz)
{
	p->z = (int)(kz * p->z);
}