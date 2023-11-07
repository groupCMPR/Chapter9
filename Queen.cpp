//Names: Neidy Malaga 
//Date: 10/28/2023
//Description: cpp file for class Queen

#include "Queen.h"

//precondition : size must be 1...64, column must be 1...size
//postcondition:sets board_size, fills board, sets initial_column
Queen::Queen(const int& size, const int& column) {
	board_size = size;
	board.resize(board_size);
	board = vector<vector<char>>(board_size, vector<char>(board_size, '_'));
	board.at(0).at(column - 1) = 'Q';
	backtrack_finish = true;
}


//---------------------------------------------------------------------
//							MUTATORS
//---------------------------------------------------------------------

//precondition : row (should usually be row 1)
//postcondition: fills in the board with Q using recursive 
void Queen::solve_Queens(int row) {
	//stop case
	if (row == board_size) {
		backtrack_finish = true;
		return;
	}

	for (int col = 0; col < board_size; ++col) {
		if (queen_Check(row, col)) {
			board.at(row).at(col) = 'Q';
			solve_Queens(row + 1);

			//if backtrack_finish is true, that means it has reached the base case and all answers are correct, therefore recursion call will unwind
			//if backtrack_finish is false, that means row was not filled
			//if backtrack_finish is false and row is at the inital row for recursion (aka starting row 1) will fully exit out of the function

			if (backtrack_finish) {
				return;
			}
			else {
				//since row is not filled, it will have gone to the previous row due to recursion call
				// at previous row, it will delete the Q
				board.at(row).at(col) = '_';
			}
			//will then continue with the next column, and if column is safe, it will continue the recursion solve_Queens
			//else it will go out of loop to return to previous call and 
		}


	}

	backtrack_finish = false;
	return; //returns back to recursion call if nothing is in row

}

//---------------------------------------------------------------------
//							ACCESSORS
//---------------------------------------------------------------------

//precondition : board must be filled (board_sizexboard_size)
//postcondition: returns backtrack_finish or false(board size 2 or 3)
bool Queen::is_Correct() const {
	if (board_size == 2 || board_size == 3)
		return false;

	//if backtrack_finish is true then it filled the whole rows
	//else it could not find answer as it kept backtracking until reaching the inital row
	//therefore exiting out of the recursive call
	return backtrack_finish;
}

//precondition : going through the row and columns 
//postcondition: returns false if a Q is found diagonally, horizontally, or vertically
bool Queen::queen_Check(const int& row, const int& col) const {
	for (int i = row - 1, dia_top = 1; i > -1; --i, ++dia_top) {

		if (col + dia_top < board_size && board.at(i).at(col + dia_top) == 'Q')
			return false;

		if (board.at(i).at(col) == 'Q')
			return false;

		if (col - dia_top > -1 && board.at(i).at(col - dia_top) == 'Q')
			return false;
	}

	return true;
}

//precondition : N/A
//postcondition: returns board_size
int Queen::get_Size() const {
	return board_size;
}

//precondition : board must be filled, correct row and column
//postcondition: returns char at row, column
char Queen::get_Char(const int& row, const int& col) const {
	return board.at(row).at(col);
}


//---------------------------------------------------------------------
//							FRIEND
//---------------------------------------------------------------------

//precondition : class Queen, outstream
//postcondition: displays all elements in stack of Queen
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
