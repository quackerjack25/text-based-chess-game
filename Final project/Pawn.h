#ifndef __PAWN_H__
#define __PAWN_H__
#include "Point.h"
#include "Piece.h"

class Pawn : public Piece {
	private:
		int direction;
		int start;
	public:
		Pawn(Color c, Point p, bool a);
		moveType canMove(Point to);
		void print();
};

#endif
