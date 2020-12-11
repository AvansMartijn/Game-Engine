#pragma once
struct Rect {
	int x;
	int y;
	int w;
	int h;

	Rect() {}

	Rect(float rectX, float rectY, float rectWidth, float rectHeight) {
		x = (int)rectX;
		y = (int)rectY;
		w = (int)rectWidth;
		h = (int)rectHeight;
	}

	Rect(int rectX, int rectY, int rectWidth, int rectHeight) {
		x = rectX;
		y = rectY;
		w = rectWidth;
		h = rectHeight;
	}
};

