/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Polymorphic base class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <vector>

class Space
{

//Space pointers are protected and not private so the Map friend class can access them
protected:
	Space *top = nullptr;
	Space *left = nullptr;
	Space *right = nullptr;
	Space *bottom = nullptr;

public:
	Space();
	virtual ~Space();
	virtual void locationDescription() = 0; //Pure virtual function
	virtual void locationDescription(int gameState[], std::vector<int> inventory, int air);
	friend class Map;
};

#endif //!SPACE_HPP