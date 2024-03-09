#pragma once

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
	int N;
};

struct change
{
	int mode; // 1 - rotation, 2 - shifting, 3 - scaling, 4 - loading
	union
	{
		struct rotate rotation;
		struct shift shifting;
		struct scale scaling;
		struct load loading;
	} data;
};
