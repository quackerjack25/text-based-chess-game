#include <iostream>
#include <cmath>
#include "King.h"
using namespace std;

King::King(Color c, Point p, bool a) : Piece(KING, c, p, a) {
	start = 4;
}

moveType King::canMove(Point to) {
	int fromX, fromY, toX, toY;
	fromX = getLocation().GetX();
	fromY = getLocation().GetY();
	toX = to.GetX();
	toY = to.GetY();
		
	int dx = toX - fromX;
	int dy = toY - fromY;
	if (abs(dx) == abs(dy)) {		// diagonal move
		Piece *p;
		p = occupy(Point(toX, toY));
		if (p==0) return NORMAL;
		else if (p->getColor() != getColor()) return NORMAL;
	}
	if (dx == 0 && abs(dy)==1) {		// horizontal move
		Piece *p;
		p = occupy(Point(toX, toY));
		if (p==0) return NORMAL;
		else if (p->getColor() != getColor()) return NORMAL;
	}
	if (abs(dx) ==1 && dy == 0) {		// vertical move
		Piece *p;
		p = occupy(Point(toX, toY));
		if (p==0) return NORMAL;
		else if (p->getColor() != getColor()) return NORMAL;	
	}
	if (dx==0 && (dy == 2 || dy == -2) && start == fromY) { // castle
		Piece *p;
		p = occupy(Point(toX, toY));
		if (p==0) return NORMAL;
		
		if (dy==2) p = occupy(Point(toX, toY+1));
		else p = occupy(Point(toX, toY-1));
		if (p==0) return NORMAL;
	}
	return ILLEGAL;
}

void King::print() {
	Piece::print();
	std::cout << "K ";
}
