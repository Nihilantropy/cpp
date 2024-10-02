#include "Brain.h"

/*** costructor ***/
Brain::Brain()
{
	std::cout << "Brain costructor called. Brain is filled with amazing ideas!" << std::endl;
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = "What an amazing idea!";
}

/*** Copy costructor with deep copy implementation ***/
Brain::Brain( const Brain& other )
{
	std::cout << "Brain copy costructor called. Ideas get multiplied!" << std::endl;
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

/*** assignment operator with deep copy implementation ***/
Brain& Brain::operator=( const Brain& other )
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		if (_ideas)
			delete [] _ideas;
		_ideas = new std::string[100];
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

/*** destructor ***/
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	delete [] _ideas;	
}

/*** getters ***/
std::string*	Brain::getIdeas( void ) const { return _ideas; }
