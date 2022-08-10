#ifndef __ROOK_H__
#define __ROOK_H__
#include "Point.h"
#include "Piece.h"

class Rook : public Piece {
	private:
	public:
		Rook(Color c, Point p, bool a);
		moveType canMove(Point to);
		void print();
};

#endif
