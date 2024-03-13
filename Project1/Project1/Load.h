#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "FigureStruct.h"
#include "ChangeStruct.h"
#include "Errors.h"

error_t load_figure(figure_t* fig, const load_t *ch);
void free_figure(figure* fig);
