#include <iostream>
using namespace std;
#include "Point.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

Piece * board[8][8]; 

void display() {
	cout << "\n";
	cout << endl;
	for (int i=7; i>=0; i--) {
		cout << i+1 << "  ";
		for (int j=0; j<8; j++)
			if (board[i][j] == 0) 
				cout << "   ";
			else {
				switch (board[i][j]->getType()) {
					case PAWN: {
						((Pawn *) board[i][j])->print();
						break;
					}
					case ROOK: {
						((Rook *) board[i][j])->print();
						break;
					}
					case BISHOP: {
						((Bishop *) board[i][j])->print();
						break;
					}
					case KNIGHT: {
						((Knight *) board[i][j])->print();
						break;
					}
					case KING: {
						((King *) board[i][j])->print();
						break;
					}
					case QUEEN: {
						((Queen *) board[i][j])->print();
						break;
					}
					case NOTHING: break;
				}
			}
		cout << endl;
	}
	cout << "   ";
	for (int i=0; i<8; i++)
		cout << (char) (97+i) << "  ";
	cout << "\n";
}
void setup() {
	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++)
			board[i][j] = 0;
	
	for (int i=0; i<8; i++) {
		board[1][i] = new Pawn(WHITE, Point(1, i), true);
		board[6][i] = new Pawn(BLACK, Point(6, i), true);
	}
	board[0][0] = new Rook(WHITE, Point(0, 0), true);
	board[0][7] = new Rook(WHITE, Point(0, 7), true);
	board[7][0] = new Rook(BLACK, Point(7, 0), true);
	board[7][7] = new Rook(BLACK, Point(7, 7), true);
	
	board[0][1] = new Knight(WHITE, Point(0, 1), true);
	board[0][6] = new Knight(WHITE, Point(0, 6), true);
	board[7][1] = new Knight(BLACK, Point(7, 1), true);
	board[7][6] = new Knight(BLACK, Point(7, 6), true);
	
	board[0][2] = new Bishop(WHITE, Point(0, 2), true);
	board[0][5] = new Bishop(WHITE, Point(0, 5), true);
	board[7][2] = new Bishop(BLACK, Point(7, 2), true);
	board[7][5] = new Bishop(BLACK, Point(7, 5), true);
	
	board[0][3] = new Queen(WHITE, Point(0, 3), true);
	board[7][3] = new Queen(BLACK, Point(7, 3), true);
	
	board[0][4] = new King(WHITE, Point(0, 4), true);
	board[7][4] = new King(BLACK, Point(7, 4), true);
	
}
bool inBoard(int x, int y) {
	return x>=0 && x<8 && y>=0 && y<8;
}

Piece * pieceExist(int x, int y) {
	return board[x][y];
}

int main(int argc, char** argv) {
	string p;
	char fromChar, toChar;
	int fromX, fromY, toX, toY;
	Color turn = WHITE;
	setup();
	
	while (true) {
		display();
		if (turn == WHITE) {
			cout << "\nWhite move, type a move\n";
			cout << "You need to type from position to position\n";
			cout << "For example: e2\n\n";
		}
		cout << "From: ";
		cin >> fromChar >> fromX;	// fromX is row; fromChar is column
		fromY = fromChar - 'a';		// fromY is column
		cout << "To: ";
	
		cin >> toChar >> toX;		// toX is row
		toY = toChar - 'a';			// toY is column
		fromX--; 
		toX--; 
		
		if (!inBoard(fromX, fromY)) {
			cout << "From location is out of the board\n";
			continue;
		}
		if (!inBoard(toX, toY)) {
			cout << "Move to location is out of the board\n";
			continue;
		}
		{
			Piece * p = pieceExist(fromX, fromY);
			if (p==0) {
				cout << "No piece exist at that position\n";
				continue;
			}
			else if (p->getColor() != turn) {
				cout << "Turn is not the turn for this piece\n";
				continue;
			}
		}
		switch (board[fromX][fromY]->getType()) {
			case PAWN: {
					Pawn *From = (Pawn *) board[fromX][fromY];
					int move_type = From->canMove(Point(toX, toY));
					if (move_type != ILLEGAL) {
						board[fromX][fromY] = 0;
						From->setLocation(Point(toX, toY));
						board[toX][toY] = From;
					}
					else {
						cout << "ILLEGAL move\n";
						continue;
					}
					break;
				}
			case ROOK: {
					Rook *From = (Rook *) board[fromX][fromY];
					int move_type = From->canMove(Point(toX, toY));
					if (move_type != ILLEGAL) {
						board[fromX][fromY] = 0;
						From->setLocation(Point(toX, toY));
						board[toX][toY] = From;
					}
					else {
						cout << "ILLEGAL move\n";
						continue;
					}
					break;
			}
			case KNIGHT: {
					Knight *From = (Knight *) board[fromX][fromY];
					int move_type = From->canMove(Point(toX, toY));
					if (move_type != ILLEGAL) {
						board[fromX][fromY] = 0;
						From->setLocation(Point(toX, toY));
						board[toX][toY] = From;
					}
					else {
						cout << "ILLEGAL move\n";
						continue;
					}				
				break;
			}
			case BISHOP: {
					Bishop *From = (Bishop *) board[fromX][fromY];
					int move_type = From->canMove(Point(toX, toY));
					if (move_type != ILLEGAL) {
						board[fromX][fromY] = 0;
						From->setLocation(Point(toX, toY));
						board[toX][toY] = From;
					}
					else {
						cout << "ILLEGAL move\n";
						continue;
					}				
				break;
			}
			case QUEEN: {
					Queen *From = (Queen *) board[fromX][fromY];
					int move_type = From->canMove(Point(toX, toY));
					if (move_type != ILLEGAL) {
						board[fromX][fromY] = 0;
						From->setLocation(Point(toX, toY));
						board[toX][toY] = From;
					}
					else {
						cout << "ILLEGAL move\n";
						continue;
					}
				break;
			}
			case KING: {
					King *From = (King *) board[fromX][fromY];
					int move_type = From->canMove(Point(toX, toY));
					if (move_type != ILLEGAL) {
						board[fromX][fromY] = 0;
						From->setLocation(Point(toX, toY));
						board[toX][toY] = From;
					}
					else {
						cout << "ILLEGAL move\n";
						continue;
					}
				break;
			}
				
		}
		if (turn == WHITE) turn = BLACK;
		else turn = WHITE;
	}
	
	return 0;
}

