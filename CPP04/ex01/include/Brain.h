#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

/*** Brain class with virtual Destructor ***/
class Brain
{
public:
	Brain();
	Brain( const Brain& other );
	Brain& operator=( const Brain& other );
	virtual ~Brain();

	/*** Getters  ***/
	std::string*	getIdeas( void ) const;

private:
	std::string*	_ideas;
};

#endif
