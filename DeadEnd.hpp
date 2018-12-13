/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#ifndef DEADEND_HPP
#define DEADEND_HPP
#include "Space.hpp"

class DeadEnd :
	public Space
{
public:
	DeadEnd();
	~DeadEnd();
	void locationDescription() override;
	void locationDescription(int gameState[], std::vector<int> inventory, int air) override;
};

#endif //!DEADEND_HPP