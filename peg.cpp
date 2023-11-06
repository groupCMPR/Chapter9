//Alexis 
#include "peg.h"
//default
peg::peg() {};

//accepts an integer value
void peg::push(int ring) {
	rings.push(ring);
}
//pops the top of the stack
void peg::pop() {
	rings.pop();
}
//returns the top
int peg::top() {
	return rings.top();
}
//returns size of the stack
int peg::pegSize() const {
	return rings.size();
}
//checks if empty
bool peg::empty() {
	return rings.empty();
}
// returns the stack
stack<int> peg::getStack() const {
	return rings;
}