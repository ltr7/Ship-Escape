/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "DeadEnd.hpp"
#include "Menu.hpp"
#include <iostream>
#include "InputValidation.hpp"

DeadEnd::DeadEnd()
{
	
}

DeadEnd::~DeadEnd()
{
	
}

void DeadEnd::locationDescription(int gameState[], std::vector<int> inventory, int air)
{
	if (air <= 0)
	{
		std::cout
			<< "You peek down at the oxygen indicator on your wrist and see you have 0 units of air left. \n"
			<< "A million thoughts race through your head as you realize you have ran out of air and can no longer breath, \n"
			<< "but two blazing words pierce the fog of your mind. \n\n"
			<< "  ***************  \n"
			<< "  ***GAME OVER***  \n"
			<< "  ***************  \n\n";
	}

	//This block runs if the player 
	else if (gameState[1] == 1)
	{

		std::cout << "Nothing else here seems useful. \n"
			<< "What will you do now? \n"
			<< "1. Head south \n"
			<< "Your choice: ";

		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneintegerValidation(choice))
		{
		case 1:
			bottom->locationDescription(gameState, inventory, air);
			break;

		default:
			std::cout << "There has been an error in the DeadEnd switch logic! \n";
			break;

		}
	}

	//Runs if player is not yet wearing the spacesuit
	else
	{
		
		std::cout << "\nYou find yourself in the storage closet north of the ship's galley \n";
		std::cout << "Hanging on the wall, you see your space suit. \n";
		std::cout << "You see nothing else in the room that could help your current situation. \n";
		std::cout << "What will you do now? \n";
		std::cout << "1. Put on the space suit \n";
		std::cout << "2. Go back to the dining room \n";
		std::cout << "Your choice: ";


		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneToTwointegerValidation(choice))
		{
		case 1:
			std::cout << "\nYou don the suit as quickly as possible. \n"
			<< "A glance at the suits oxygen gauge shows you have " << air << " units of oxygen remaining. \n"
			<< "You know it takes one unit to perform an action such as flipping a switch or moving between rooms on the station. \n\n";
			gameState[1] = 1; //Indicates player is wearing the spacesuit
			air = 10; //Initial air supply reassigned to ensure player starts with correct amount of oxygen
			locationDescription(gameState, inventory, air); //Sends player back into the location loop
			break;

		case 2:
			bottom->locationDescription(gameState, inventory, air);
			break;

		default:
			std::cout << "There has been an error in the DeadEnd switch logic! \n";
			break;

		}
	}
}

//Pure virtual function to satisfy project requirements
void DeadEnd::locationDescription()
{

}