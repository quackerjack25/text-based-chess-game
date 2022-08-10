#include <iostream>
#include <cmath>
#include "Pawn.h"
using namespace std;

Pawn::Pawn(Color c, Point p, bool a) : Piece(PAWN, c, p, a) {
	//std::cout << "Setting Pawn: " << PAWN << std::endl;;
	if (c == WHITE) {
		direction = 1;
		start = 1;
	}
	else {
		direction = -1;
		start = 6;
	}
}
moveType Pawn::canMove(Point to) {
	int fromX, fromY, toX, toY;
	fromX = getLocation().GetX();
	fromY = getLocation().GetY();
	toX = to.GetX();
	toY = to.GetY();
		
	int dx = toX - fromX;
	int dy = toY - fromY;
	if (dx == direction) {		// move one step forward
		if (abs(dy) == 1) {		// kill a piece
			Piece * p = occupy(to);
			if (p!=0) {
				if (p->getColor() != getColor()) {	// killing piece is of different color
					return NORMAL;
				}
			}
		}
		if (dy == 0) {
			Piece *p = occupy(to);
			if (p==0) {	// one step forware
				return NORMAL;
			}
		}
	}
	if (dx == 2*direction && dy == 0 && fromX == start) {
		Piece *p1 = occupy(to);
		Piece *p2 = occupy(Point(to.GetX()-direction, to.GetY()));
		if (p1==0 && p2==0) {
			return DOUBLESTEP;	
		}
	}
	return ILLEGAL;
}

void Pawn::print() {
	Piece::print();
	std::cout << "P ";
}
