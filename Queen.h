//Names: Neidy Malaga 
//Date: 10/28/2023
//Description: Header file for class Queen

#pragma 
#include <iostream>
#include <vector>
using namespace std;

class Queen {
private:
	vector <vector<char>> board;
	bool backtrack_finish;
	int board_size;

public:
	//default constructor
	Queen(const int&, const int&);


	//mutator
	void solve_Queens(int row);

	//accessors
	bool is_Correct() const;
	int get_Size() const;
	char get_Char(const int&, const int&) const;
	bool queen_Check(const int&, const int&) const;

	//friend
	friend ostream& operator<<(ostream&, const Queen&);
};
