#include <iostream>
#include <cmath>
#include "Knight.h"
using namespace std;

Knight::Knight(Color c, Point p, bool a) : Piece(KNIGHT, c, p, a) {
	
}

moveType Knight::knightMove(Point to) {
	int fromX, fromY, toX, toY;
	fromX = getLocation().GetX();
	fromY = getLocation().GetY();
	toX = to.GetX();
	toY = to.GetY();
		
	int dx = toX - fromX;
	int dy = toY - fromY;
	if (dx == 1)
		if (dy == 2 || dy == -2) return NORMAL;
	if (dx == -1)
		if (dy == 2 || dy == -2) return NORMAL;
	if (dx == 2)
		if (dy == 1 || dy == -1) return NORMAL;
	if (dx == -2)
		if (dy == 1 || dy == -1) return NORMAL;
	return ILLEGAL;
}
moveType Knight::canMove(Point to) {
	Piece *p = occupy(to);
	if (p == 0) {
		return knightMove(to);
	}
	else {
		if (p->getColor() != getColor()) {
			return knightMove(to);
		}
	}	
	return ILLEGAL;
}

void Knight::print() {
	Piece::print();
	std::cout << "N ";
}
