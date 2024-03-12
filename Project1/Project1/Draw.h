#pragma once

#include "FigureStruct.h"
using namespace System::Drawing;

void draw_figure(Graphics^ g, const figure_t* fig, const int offset_x, const int offset_y);
