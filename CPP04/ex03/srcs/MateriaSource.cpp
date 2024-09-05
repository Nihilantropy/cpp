#include "../include/MateriaSource.h"

/*** Costructor ***/
MateriaSource::MateriaSource()
{
	for (int i = 0; i < SLOT_CAP; i++)
		_slot[i] = NULL; 
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	for (int i = 0; i < SLOT_CAP; i++)
	{
		if (other._slot[i])
			this->_slot[i] = other._slot[i]->clone(); 
		else
			this->_slot[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	if (this != &other)
	{
		clearSlots();

		for (int i = 0; i < SLOT_CAP; i++)
		{
			if (other._slot[i])
				this->_slot[i] = other._slot[i]->clone(); 
			else
				this->_slot[i] = NULL;
		}
	}
	return *this;
}

/*** Destructor ***/
MateriaSource::~MateriaSource()
{
	clearSlots();
}

/*** Private methods ***/
void MateriaSource::clearSlots( void )
{
	for (int i = 0; i < SLOT_CAP; i++)
	{
		if (_slot[i])
		{
			delete _slot[i];
			_slot[i] = NULL;
		}
	}
}

/*** Pure override public methods ***/

void	MateriaSource::learnMateria( AMateria* m )
{
	if (!m)
	{
		std::cerr << "Materia passed to learnMateria does not exist" << std::endl;
		return ;
	}
	for (int i = 0; i < SLOT_CAP; i++)
	{
		if (_slot[i] == NULL)
		{
			_slot[i] = m;
			std::cout << "Materia " << m->getType() << " added to learning slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Learning slots are full. Materia " << m->getType() << " couldn't be added" << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < SLOT_CAP; i++)
	{
		if (_slot[i] && _slot[i]->getType() == type)
		{
			std::cout << "Creating Materia of type: " << type << std::endl;
			return _slot[i]->clone();
		}
	}
	std::cout << "Unknown Materia type: " << type << std::endl;
	return NULL;
}


