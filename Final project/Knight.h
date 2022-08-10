#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "Point.h"
#include "Piece.h"

class Knight : public Piece {
	private:
	public:
		Knight(Color c, Point p, bool a);
		moveType knightMove(Point to);
		moveType canMove(Point to);
		void print();
};

#endif
