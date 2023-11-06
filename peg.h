//Alexis and Angie
#pragma once
#include <iostream>
#include <stack>
using namespace std;

class peg
{
private:
	stack<int> rings;


public:
	peg();
	//checks if empty
	bool empty();
	//accepts an integer value
	void push(int);
	//pops the top of the stack
	void pop();
	//returns the top
	int top();
	//returns size of the stack
	int pegSize() const;
	// returns the stack
	stack<int> getStack() const;


};

