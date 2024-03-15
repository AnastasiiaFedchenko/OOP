#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "Errors.h"
#include "FigureStruct.h"

error_t load_edges(edge_arr_t* e, FILE* f);
