#pragma once

#define _USE_MATH_DEFINES 
#include <math.h>
#include <string.h>

#include "ChangeStruct.h"
#include "FigureStruct.h"
#include "Errors.h"

error_t rotation(figure_t* fig, const rotate_t* ch);
error_t shift(figure_t* fig, const shift_t* ch);
error_t scaling(figure_t* fig, const scale_t* ch);
