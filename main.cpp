#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Animal* animal;
	animal = new Cat();

	Queue beast(10);
	beast.add(animal);
	animal = new Cow();
	beast.add(animal);
	animal = new Dog();
	beast.add(animal);
	beast.print();
	beast.remove();
	cout << "\n\n";
	beast.print();
	beast.clear();


	return 0;
}