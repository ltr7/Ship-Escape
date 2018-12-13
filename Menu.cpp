/***********************************************************************************
** Program Name: Space Escape
** Author: Lee Rice
** Last Modified: 12/12/18
** Description: Main file for a text based game about escaping a space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "Map.hpp"
#include "Galley.hpp"
#include "DeadEnd.hpp"
#include "Dining.hpp"
#include "StoreRoom.hpp"
#include "ExerciseRoom.hpp"
#include "ControlRoom.hpp"
#include "EscapePods.hpp"
#include "InputValidation.hpp"

Menu::Menu()
{
	Map gameMap;

	for (int i = 0; i < 4; i++)
	{
		gameState[i] = 0;
	}

	std::vector<int> inventory(1,0); //Player's inventory is limited to one item

	startGalley = new Galley();
	deadEndNorthOfGalley = new DeadEnd();
	diningHall = new Dining();
	eastStoreRoom = new StoreRoom();
	exerciseRoom = new ExerciseRoom();
	controlRoom = new ControlRoom();
	escapePod = new EscapePods();

	gameMap.addNorth(startGalley);
	gameMap.addNorth(deadEndNorthOfGalley);
	gameMap.addSouth(diningHall);
	gameMap.addWest(eastStoreRoom);
	gameMap.addEast(exerciseRoom);
	gameMap.addSouth(controlRoom);
	gameMap.addWest(escapePod);

}

Menu::~Menu()
{
	delete startGalley;
	delete deadEndNorthOfGalley;
	delete diningHall;
	delete eastStoreRoom;
	delete exerciseRoom;
	delete controlRoom;
	delete escapePod;
}


void Menu::escapeMenu()
{
	Menu air;
	std::string menuSelection;
	std::cout << std::endl << std::endl;
	std::cout
		<< "***** Welcome to Space Escape *****\n"
		<< "*****     A Text Adventure    *****\n\n\n"
		<< "Would you like to start a new game ? \n"
		<< "1. Yes \n"
		<< "2. No \n"
		<< "Please enter your selection: ";
	std::cin >> menuSelection;
	std::cout << std::endl;

	InputValidation newValidation;
	switch (newValidation.oneToTwointegerValidation(menuSelection))
	{

	case 1:

		gameFlow();
		break;

	case 2:
		exitGame();
		break;

	default:
		std::cout << "There has been an error in the escapeMenu switch logic!";
		break;
	}

}

void Menu::gameFlow()
{

	std::cout
	<< "You wake from your daydream with a start. \n"
	<< "All around you alarm bells ring and red lights flash. \n"
	<< "Your immediate concern about the quiche in the oven "
	<< "is replaced with a sense of dread as you realize \n"
	<< "you need to get off this space station "
	<< "because something has gone very, very wrong. \n\n";
	int air = 10; 
	startGalley->locationDescription(gameState, inventory, air);

}

void Menu::exitGame()
{

}
