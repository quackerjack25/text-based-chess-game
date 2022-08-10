#include <iostream>
#include "Piece.h"

extern Piece * board[8][8];

Piece::Piece(PieceType t = NOTHING, Color c = WHITE, Point p = Point(0, 0), bool a = true) {
	color = c;
	location = p;
	active = a;
	type = t;
	//std::cout << "t=" << t << std::endl;
}

Piece::Piece() {
	color = WHITE;
	location.SetPoint(0, 0);
	active = true;
	type = NOTHING;
	std::cout << "NOTHING\n";
}

		
Color Piece::getColor() { return color; }
Point Piece::getLocation() { return location; }
bool Piece::getActive() { return active; }
PieceType Piece::getType() { return type; }

void Piece::setColor(Color c) { color = c; }
void Piece::setLocation(Point p) { location = p; }
void Piece::setActive(bool a) { active = a; }
void Piece::setType(PieceType t) { type = t; }

moveType Piece::canMove(Point to) {
	int toX, toY;
	
	toX = to.GetX();
	toY = to.GetY();
	
	// out of the board
	if (toX < 0 || toX > 7) return ILLEGAL;
	if (toY < 0 || toY > 7) return ILLEGAL;
	
	// location to is occupied
	Piece * p = board[toX][toY];
	if (p == 0) return NORMAL;
	if (p->getColor() == color) return ILLEGAL;
	return NORMAL;
}

void Piece::print() {
	if (color == WHITE)
		std::cout << 'W';
	else std::cout << 'B';
}

Piece * Piece::occupy(Point p) {
	return board[p.GetX()][p.GetY()];
}
