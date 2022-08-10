#include <iostream>
#include <cmath>
#include "Rook.h"
using namespace std;

Rook::Rook(Color c, Point p, bool a) : Piece(ROOK, c, p, a) {
	
}
moveType Rook::canMove(Point to) {
	int fromX, fromY, toX, toY;
	fromX = getLocation().GetX();
	fromY = getLocation().GetY();
	toX = to.GetX();
	toY = to.GetY();
		
	int dx = toX - fromX;
	int dy = toY - fromY;
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
	if (dx !=0 && dy == 0) {
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

void Rook::print() {
	Piece::print();
	std::cout << "R ";
}
