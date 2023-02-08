#pragma once
#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void voice() = 0;
};

class Dog : public Animal
{
public:
	void voice() override
	{
		cout << "Gav Gav\n";
	}
};

class Cat : public Animal
{
public:
	void voice() override
	{
		cout << "Mya Mya\n";
	}
};

class Cow : public Animal
{
public:
	void voice() override
	{
		cout << "Myy Myy\n";
	}
};
 
class Queue
{
private:
	int maxsize;
	Animal** arr;
	int inqueue;
public:
	Queue(int lens) :maxsize{ lens }, arr{ new Animal*[maxsize] }, inqueue{ 0 } {}

	~Queue()
	{
		for (int i = 0; i < inqueue; i++)
		{
			delete arr[i];
		}
		delete[] arr;
	}
	
	void add(Animal* nex)
	{
		if (!isFull())
		{
			arr[inqueue++] = nex;
		}
	}
	
	Animal* remove()
	{
		if (!isEmpty())
		{
			Animal* first = arr[0];
			for (int i = 1; i < inqueue; i++)
			{
				arr[i - 1] = arr[i];
			}
			inqueue--;
			return first;
		}
	}
	
	void clear()
	{
		inqueue = 0;
	}
	
	bool isEmpty()
	{
		return inqueue == 0;
	}
	
	bool isFull()
	{
		return inqueue == maxsize;
	}

	int getSize()
	{
		return inqueue;
	}
	
	void print()
	{
		for (int i = 0; i < inqueue; i++)
		{
			arr[i]->voice();
		}
	}
};