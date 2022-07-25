#include "StrOperation.h"

using namespace std;

StrOperation::StrOperation() :
	str{},
	stack{}
{}

void StrOperation::showStr(int count)
{
	for (int i{}; i < count; ++i)
		cout << str[i];
	cout << "\n";
}

bool StrOperation::chkStr()
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ';' || i + 1 == str.length())
		{
			showStr(str.length());
			return false;
		}
		switch (str[i])
		{
		case('('):
		case ('['):
		case ('{'):
			stack.push(str[i]);
			continue;
		case(')'):
			if (stack.peek() == '(')
			{
				stack.pop();
				continue;
			}
			break;
		case (']'):
			if (stack.peek() == '[')
			{
				stack.pop();
				continue;
			}
			break;
		case ('}'):
			if (stack.peek() == '{')
			{
				stack.pop();
				continue;
			}
			break;
		default:
			continue;
		}
		showStr(i + 1);
		return true;
	}
}

string StrOperation::inputStr()
{
	do {
		cout << "Input math expression (close string \";\"): \n";
		cin >> str;
		cin.ignore(32768, '\n');
	} while (str.back() != ';');
	return str;
}