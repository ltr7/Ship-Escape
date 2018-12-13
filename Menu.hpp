/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Menu class for a text based game about escaping a space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "Space.hpp"
#include <vector>
class Menu
{
private:
	Space *startGalley;
	Space *deadEndNorthOfGalley;
	Space *diningHall;
	Space *eastStoreRoom;
	Space *exerciseRoom;
	Space *controlRoom;
	Space *escapePod;

	/******************************************************************************
	* gameState array locations:
	* gameState[0]: Indicates player has picked up either manual or crowbar in galley
	*	gameState[0] 1 indicates player has taken manual
	*	gameState[0] 2 indicates player has taken crowbar
	* gameState[1]: Player has put on the spacesuit
	* gameState[2]: Player has flipped switch/taken floating oxygen bottle
	* gameState[3]: Player has taken floating email
	* gameState[4]: Player has retrieved the oxygen tank from their footlocker
	* gameState[5]: Player has read pod briefing
	******************************************************************************/
	int gameState[5]; //Different locations in gameState change dialog for player

	std::vector<int> inventory; //Player's inventory stores crowbar or manual from beginning of the game


public:
	Menu();
	~Menu();
	void escapeMenu();
	void gameFlow();
	void exitGame();

};

#endif //!MENU_HPP