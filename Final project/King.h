#ifndef __King_H__
#define __King_H__
#include "Point.h"
#include "Piece.h"

class King : public Piece {
	private:
		int start;
	public:
		King(Color c, Point p, bool a);
		moveType canMove(Point to);
		void print();
};

#endif
