#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include<iostream>
#include<initializer_list>
#include<cassert>

using namespace std;

template<class T>
class DynamicStack
{
	T* data = nullptr;
	size_t top = 0;	

public:
	DynamicStack() {}
	~DynamicStack();
	DynamicStack(initializer_list<T> list);
	DynamicStack(const DynamicStack& s);
	DynamicStack& operator=(const DynamicStack& s);	
	void push(const T& value);
	void pop();
	T peek() const;
	size_t length() const;
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	void print() const;

};
#endif // !DYNAMICSTACK_H


template<class T>
DynamicStack<T>::~DynamicStack()
{
	delete[] data;
}

template<class T>
DynamicStack<T>::DynamicStack(initializer_list<T> list)
{	
	data = new T[ list.size() ];
	for (T l : list)
		data[top++] = l;	
}

template<class T>
DynamicStack<T>::DynamicStack(const DynamicStack& s)
{	
	top = s.top;
	data = new T[top];
	for (int i{}; i < top; ++i)
		data[i] = s.data[i];
}

template<class T>
DynamicStack<T>& DynamicStack<T>::operator=(const DynamicStack<T>& s)
{	
	
	if (top != s.top)
	{
		delete[] this->data;		
		data = new T[s.top];
	}
	top = s.top;
	for (int i{}; i < top; ++i)
		data[i] = s.data[i];
	
	return *this;
}

template<class T>
void DynamicStack<T>::push(const T& value)
{
	T* temp = new T[top + 1]{};

	for (int i{}; i < top; ++i)
		temp[i] = data[i];

	delete[] data;
	data = temp;
	data[top++] = value;
}


template<class T>
void DynamicStack<T>::pop()
{
	if (top > 0)
	{	
		--top;
		T* temp = new T[top]{};

		for (int i{}; i < top; ++i)
			temp[i] = data[i];

		delete[] data;
		data = temp;
	}
}

template<class T>
T DynamicStack<T>::peek() const
{
	assert(top > 0);
	return data[top - 1];	
}

template<class T>
size_t DynamicStack<T>::length() const
{
	return top;
}

template<class T>
bool DynamicStack<T>::isEmpty() const
{
	return top == 0;
}

template<class T>
void DynamicStack<T>::clear()
{
	delete[] data;
	top = 0;
	data = nullptr;
}

template<class T>
void DynamicStack<T>::print() const
{
	if (!isEmpty())
	{
		for (int i{}; i < top; ++i)
			cout << data[i] << (i+1==top ? "\n":" ");
	}
	else
		cout << "Stack is EMPTY!!!" << "\n";
	
}
