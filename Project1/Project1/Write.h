#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "FigureStruct.h"
#include "ChangeStruct.h"
#include "Errors.h"

error_t write_file(figure_t* fig, const load_t* ch);
