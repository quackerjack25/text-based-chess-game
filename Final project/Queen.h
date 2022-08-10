#ifndef __QUEEN_H__
#define __QUEEN_H__
#include "Point.h"
#include "Piece.h"

class Queen : public Piece {
	private:
	public:
		Queen(Color c, Point p, bool a);
		moveType canMove(Point to);
		void print();
};

#endif
