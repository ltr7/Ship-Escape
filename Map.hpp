/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Map class for a text based game about escaping a space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#ifndef MAP_HPP
#define MAP_HPP
#include "Space.hpp"

class Map
{
private:
	Space *center;
	Space *mostNorth;
	Space *mostSouth;
	Space *mostEast;
	Space *mostWest;


public:
	Map();
	~Map();
	void addNorth(Space*);
	void addSouth(Space*);
	void addEast(Space*);
	void addWest(Space*);


};

#endif //!MAP_HPP