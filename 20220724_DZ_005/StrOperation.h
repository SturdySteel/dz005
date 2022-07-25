#ifndef STROPERATION_H
#define STROPERATION_H

#include <string>
#include <iostream>
#include "DynamicStack.h"

class StrOperation
{
private:
	string str;
	DynamicStack<char> stack;

public:
	StrOperation();
	void showStr(int count);
	bool chkStr();
	string inputStr();
};
#endif // !STROPERATION_H

