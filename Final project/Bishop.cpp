#include <iostream>
#include <cmath>
#include "Bishop.h"
using namespace std;

Bishop::Bishop(Color c, Point p, bool a) : Piece(BISHOP, c, p, a) {
	
}

moveType Bishop::canMove(Point to) {
int fromX, fromY, toX, toY;
	fromX = getLocation().GetX();
	fromY = getLocation().GetY();
	toX = to.GetX();
	toY = to.GetY();
		
	int dx = toX - fromX;
	int dy = toY - fromY;
	if (abs(dx) == abs(dy)) {	// diagonal
		Piece *p;
		int incx, incy;
		if (dx>0) incx = 1;
		else incx = -1;
		if (dy>0) incy = 1;
		else incy = -1;
		int sx = fromX+incx, sy = fromY+incy;
		
		while (sx != toX) {
			p = occupy(Point(sx, sy));
			if (p!=0) return ILLEGAL;
			sx += incx;
			sy += incy;
		}
		p = occupy(Point(toX, toY));
		if (p==0) return NORMAL;
		else if (p->getColor() != getColor()) return NORMAL;
	}
	return ILLEGAL;
}

void Bishop::print() {
	Piece::print();
	std::cout << "B ";
}
