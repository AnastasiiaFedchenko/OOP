#pragma once
#include <string>
#include "../objects/canvas.h"
#include "base_drawer.h"

class WinFormsDrawer : public BaseDrawer
{
public:
    WinFormsDrawer() = delete;
    WinFormsDrawer(canvas_t* canv) : canvas(canv) {}
    void draw_line(My_Point p1, My_Point p2) override
    {
        int offset_x = (int)(canvas->width / 2);
        int offset_y = (int)(canvas->height / 2);
        canvas->g->DrawLine(canvas->pen, (int)p1.get_x() + offset_x, (int)p1.get_y() + offset_y, 
            (int)p2.get_x() + offset_x, (int)p2.get_y() + offset_y);
    }
    void clear_scene() override
    {
        
        System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(canvas->backcolor);
        canvas->g->FillRectangle(brush, 0, 0, canvas->width, canvas->height);
    }

private:
    canvas_t* canvas;
};
