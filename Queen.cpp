#include "Queen.h"

//precondition: size must be 1...64, column must be 1...size
//postcondition:sets board_size, fills board, sets initial_column
Queen::Queen(const int& size, const int& column) {
	board_size = size;
	board.resize(board_size);
	board = vector<vector<char>>(board_size, vector<char>(board_size, '_'));
	initial_column = column - 1;
}


//---------------------------------------------------------------------
//							MUTATORS
//---------------------------------------------------------------------

//precondition: column and row on first spot player has chosen based on how it would be on board, column(0...board_size-1), row = 0
//postcondition: fills in the board with Q using recursive (just moves it over 2 spaces and one row each time)
void Queen::solve_Queen(int column, int row) {
	//stop case
	if (row == board_size)
		return;

	if (column >= board_size) {
		if (initial_column == 0)
			column = 0 + (column - board_size);
		else
			column = 0;
	}


	board.at(row).at(column) = 'Q';
	solve_Queen(column + 2, row + 1);
}


//---------------------------------------------------------------------
//							ACCESSORS
//---------------------------------------------------------------------

//precondition: board must be filled (board_sizexboard_size)
//postcondition: checks if solution is correct, if not there is no solution 
//that can be solved without using backtracking
bool Queen::is_Correct() const {
	if (board_size == 2 || board_size == 3)
		return false;

	for (int i = 0; i < board.size(); ++i) {
		int counter = 0;
		for (int j = 0; j < board.size(); ++j) {
			if (board.at(j).at(i) == 'Q') {
				++counter;
			}

			if (counter == 2)
				return false;
		}
	}

	return true;
}

int Queen::get_Size() const {
	return board_size;
}

char Queen::get_Char(const int& row, const int& col) const {
	return board.at(row).at(col);
}

//---------------------------------------------------------------------
//							FRIEND
//---------------------------------------------------------------------
//Precondition: class Queen, outstream
//Postcondition: displays all elements in stack of Queen
ostream& operator<<(ostream& out, const Queen& obj) {
	out << "\n\t" << obj.get_Size() << "-Queens";

	out << "\n\t" << char(201) << string((obj.get_Size() * 2 - 1), char(205)) << char(187);
	for (int row = 0; row < obj.get_Size(); ++row) {
		cout << "\n\t" << char(186);

		for (int col = 0; col < obj.get_Size(); ++col) {

			out << obj.get_Char(row, col);

			if (col + 1 == obj.get_Size())
				out << char(186);
			else
				out << char(179);

		}
	}
	out << "\n\t" << char(200) << string((obj.get_Size() * 2 - 1), char(205)) << char(188);
	return out;
}
