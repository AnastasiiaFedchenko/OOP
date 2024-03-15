#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "Errors.h"
#include "FigureStruct.h"

error_t alloca_points(point_arr_t *p);
error_t load_points(point_t* O, point_arr_t* p, FILE* f);