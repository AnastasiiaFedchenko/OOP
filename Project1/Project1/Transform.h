#pragma once

#define _USE_MATH_DEFINES 
#include <math.h>
#include <string.h>

#include "ChangeStruct.h"
#include "FigureStruct.h"
#include "Load.h"

figure_t* controller(figure_t *fig, const change_t ch); 
