#pragma once

#define ROTATION 1
#define SHIFTING 2
#define SCALING 3
#define LOADING 4
#define DRAWING 5
typedef struct rotate rotate_t;
typedef struct shift shift_t;
typedef struct scale scale_t;
typedef struct load load_t;
typedef value struct draw draw_t;
typedef struct change change_t;
struct rotate
{
	int X;
	int Y;
	int Z;
};
struct shift
{
	int X;
	int Y;
	int Z;
};
struct scale
{
	double X;
	double Y;
	double Z;
};
struct load
{
	char* path;
};
value struct draw
{
	System::Windows::Forms::PaintEventArgs^ e;
	int offset_x;
	int offset_y;
};

struct change
{
	int mode; // 1 - rotation, 2 - shifting, 3 - scaling, 4 - loading, 5 - drawing
	union
	{
		rotate_t rotation;
		shift_t shifting;
		scale_t scaling;
		load_t loading;
	};
};
