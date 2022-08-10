#ifndef __PIECE_H__
#define __PIECE_H__

#include "Point.h"

enum Color { WHITE, BLACK, NONE };
enum moveType { NORMAL, ILLEGAL, CASTLE, DOUBLESTEP, ENPASSANT};
enum PieceType { PAWN, ROOK, BISHOP, KNIGHT, KING, QUEEN, NOTHING };


class Piece {
	private:
		Color color;
		Point location;
		bool active;
		PieceType type;
	public:
		Piece(PieceType t, Color c, Point L, bool a);
		Piece();
		
		Color getColor();
		Point getLocation();
		bool getActive();
		PieceType getType();
		
		void setColor(Color c);
		void setLocation(Point p);
		void setActive(bool a);
		void setType(PieceType t);
		
		moveType canMove(Point to);
		void print();
		Piece * occupy(Point p);
};


#endif
