#pragma once
#include <cstddef>

#include "FigureStruct.h"
#include "ChangeStruct.h"
#include "Errors.h"
using namespace System::Drawing;

error_t draw_figure(const figure_t* fig, const draw_t *ch);
