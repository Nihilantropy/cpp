#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	std::cout << "Animal type is " << j->getType() << std::endl;
	std::cout << "Animal type is " << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	/* testing virtual method vs non-virtual method makeSound() */
	const Cat*		s = new Cat();
	const Animal*	u = s;
	std::cout << "expected 2 sounds: first should be \"Miao\", second should also be \"Miao\"" << std::endl; 
	s->makeSound(); // should print cat sound
	u->makeSound(); // should print cat sound

	/* only type class WrongCat can use WrongCat makesound
	**	If we instantiate the k to type WrongAnimal, we would here
	**	a generic "..."
	*/
	const WrongCat*		k = new WrongCat();
	const WrongAnimal*	h = k;
	std::cout << "expected 2 sounds: first should be \"Muao\", second should be \"...\"" << std::endl; 
	k->makeSound(); // should print cat sound
	h->makeSound(); // should print generic animal sound "..." sound


	delete i;
	delete j;
	delete meta;
	delete s;
	delete k;
	return 0;
}
