#pragma once
value struct canvas_t
{
	System::Drawing::Graphics^ g;
	System::Drawing::Pen^ pen;
	System::Drawing::Color backcolor;
	int width;
	int height;
};