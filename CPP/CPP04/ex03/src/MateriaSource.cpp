#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor called on " << this << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiasource)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = materiasource._inventory[i];
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called on " << this << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

MateriaSource & MateriaSource::operator = (const MateriaSource &materiasource)
{
	std::cout << "Copy operator called on " << this << std::endl;
	if (this != &materiasource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (materiasource._inventory[i])
				_inventory[i] = materiasource._inventory[i];
		}
		
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i = 0;
	do
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
		i++;
	}	while (i < 4);
	if (i == 4)
	{
		std::cout << "This Materia source is full!" << std::endl;
		delete m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}

std::ostream &operator<<(std::ostream &out, const MateriaSource &materiasource)
{
	out << "MateriaSource [" << &materiasource << "]";
	return (out);
}