#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
public:
	/*** costructor ***/
	Brain();
	/*** copy costructor ***/
	Brain( const Brain& other );
	/*** assignment operator ***/
	Brain& operator=( const Brain& other );
	/*** destructor ***/
	virtual ~Brain();

	/*** getters ***/
	std::string*	getIdeas( void ) const;

private:
	std::string*	_ideas;
};

#endif
