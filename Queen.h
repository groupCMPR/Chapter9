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
	int board_size;
	int initial_column;

public:
	//default constructor
	Queen(const int&, const int&);

	//mutator
	void solve_Queen(int, int);

	//accessor
	bool is_Correct() const;
	int get_Size() const;
	char get_Char(const int&, const int&) const;

	//friend
	friend ostream& operator<<(ostream& out, const Queen& obj);
};
