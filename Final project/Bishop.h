#ifndef __BISHOP_H__
#define __BISHOP_H__
#include "Point.h"
#include "Piece.h"

class Bishop : public Piece {
	private:
	public:
		Bishop(Color c, Point p, bool a);
		moveType canMove(Point to);
		void print();
};

#endif
