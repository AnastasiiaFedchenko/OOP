#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "FigureStruct.h"
#include "ChangeStruct.h"

figure_t* load_figure(const change_t ch);
void free_figure(figure* fig);
