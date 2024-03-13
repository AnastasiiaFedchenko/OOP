#pragma once

#include "ChangeStruct.h"
#include "FigureStruct.h"
#include "Load.h"
#include "Draw.h"
#include "Errors.h"
#include "Transform.h"

error_t controller(const change_t* ch, const draw_t* ch_draw);