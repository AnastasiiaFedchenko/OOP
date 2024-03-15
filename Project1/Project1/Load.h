#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "FigureStruct.h"
#include "ChangeStruct.h"
#include "LoadPoints.h"
#include "LoadEdges.h"
#include "Errors.h"


error_t read_file(figure_t* fig, const load_t* ch);