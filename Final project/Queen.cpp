#include <iostream>
#include <cmath>
#include "Queen.h"
using namespace std;

Queen::Queen(Color c, Point p, bool a) : Piece(QUEEN, c, p, a) {
	
}

moveType Queen::canMove(Point to) {
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
	if (dx == 0 && dy!=0) {		// horizontal move
		Piece *p;
		int inc;
		if (dy>0) inc=1;
		else inc=-1;
		int i=fromY+inc;
		while (i!=toY) {
			p = occupy(Point(fromX, i));
			if (p != 0) return ILLEGAL;
			i += inc;
		}
		p = occupy(Point(fromX, toY));
		if (p==0) return NORMAL;
		else {
			if (p->getColor() != getColor()) return NORMAL;
		}
	}
	if (dx !=0 && dy == 0) {		// vertical move
		Piece *p;
		int inc;
		if (dx>0) inc=1;
		else inc=-1;
		int i=fromX+inc;
		while (i!=toX) {
			p = occupy(Point(i, fromY));
			if (p != 0) return ILLEGAL;
			i += inc;
		}
		p = occupy(Point(toX, fromY));
		if (p==0) return NORMAL;
		else {
			if (p->getColor() != getColor()) return NORMAL;
		}		
	}
	return ILLEGAL;
}

void Queen::print() {
	Piece::print();
	std::cout << "Q ";
}
