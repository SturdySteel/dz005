#include <iostream>
#include <string>
//#include "DynamicStack.h"
#include "StrOperation.h"

using namespace std;

int main()
{	
	//DynamicStack<char> stack;	
	StrOperation str;

	do{
		str.inputStr();		
	} while (str.chkStr());

	return 0;
}
