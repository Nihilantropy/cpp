#include <iostream>
#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
	std::cout << "Try to instantiate a AAnimal abstract class" << std::endl;

	//AAnimal*	errAnimal = new AAnimal(); // Remove this to make it work

	std::cout << "Basic Test: Creating and deleting individual animals" << std::endl;
	
	const AAnimal* j = new Dog(); // This is allowd because Dog and Cat implement makeSound method
	const AAnimal* i = new Cat();

	std::cout << "Deleting Dog and Cat" << std::endl;

	delete j;
	delete i;

	std::cout << "---------------------" << std::endl;

	std::cout << "Array Test: Creating an array of AAnimals" << std::endl;
	const int animalArraySize = 6;
	const AAnimal* animals[animalArraySize];

	for (int k = 0; k < animalArraySize / 2; ++k)
	{
		animals[k] = new Dog();
	}
	for (int k = animalArraySize / 2; k < animalArraySize; ++k)
	{
		animals[k] = new Cat();
	}

	std::cout << "Deleting the array of Animals" << std::endl;
	for (int k = 0; k < animalArraySize; ++k)
	{
		delete animals[k];
	}

	std::cout << "---------------------" << std::endl;

	std::cout << "Deep Copy Test: Testing deep copy of Dog and Cat" << std::endl;
	Dog originalDog;
	Dog copyDog(originalDog);

	Cat originalCat;
	Cat copyCat(originalCat);

	Dog assignedDog;
	assignedDog = originalDog;

	Cat assignedCat;
	assignedCat = originalCat;

	std::cout << "---------------------" << std::endl;

	return 0;
}