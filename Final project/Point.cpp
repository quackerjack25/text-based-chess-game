#include "Point.h"

Point::Point() { x = y = 0; }
Point::Point(int i, int j) : x(i), y(j) {}

int Point::GetX() { return x; }
int Point::GetY() { return y; }

void Point::SetX(int i) { x = i; }
void Point::SetY(int j) { y = j; }

void Point::SetPoint(int i, int j) {
	x = i;
	y = j;
}


