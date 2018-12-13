/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Date: 11/28/17
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#ifndef LIVINGAREA_HPP
#define LIVINGAREA_HPP
#include "Space.hpp"

class LivingArea :
	public Space
{
public:
	LivingArea();
	~LivingArea();
	void locationDescription() override;
	void locationDescription(int gameState[], std::vector<int> inventory, int air) override;
};

#endif //!LIVINGAREA_HPP