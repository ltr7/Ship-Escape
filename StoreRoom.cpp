/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "StoreRoom.hpp"
#include <iostream>
#include "InputValidation.hpp"

StoreRoom::StoreRoom()
{
	
}

StoreRoom::~StoreRoom()
{
	
}

void StoreRoom::locationDescription(int gameState[], std::vector<int> inventory, int air)
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

	else if (gameState[2] !=2)
	{
		std::cout << "\nYou enter the storeroom.  It's full of mops, extra dishes and boxes of food. \n";
		std::cout << "On the far wall you see a circuit breaker. \n";
		std::cout << "The only exit is back east through the door you came through. \n\n";
		std::cout << "You have " << air << " units of oxygen remaining. \n";

		std::cout << "What will you do now? \n";
		std::cout << "1. Pull the circuit breaker \n";
		std::cout << "2. Go back to the dining room \n";
		std::cout << "Your choice: ";

		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneToTwointegerValidation(choice))
		{
		case 1:
			std::cout << "\nYou pull the circuit breaker and hope that powered on the east dining room door \n\n";
			gameState[2] = 2; //Indicates that player has flipped the breaker
			air -= 1;
			this->locationDescription(gameState, inventory, air);
			break;

		case 2:
			air -= 1;
			right->locationDescription(gameState, inventory, air);
			break;

		default:
			std::cout << "There has been an error in the DeadEnd switch logic! \n";
			break;

		}
	}
	else
	{
		{
			std::cout << "Having pulled the breaker, your only real option is to ";
			std::cout << "go see if the east door in the dining room opened. \n";
			std::cout << "You notice you have just " << air << " units of oxygen left. \n\n";

			std::cout << "What will you do now? \n";
			std::cout << "1. Head back to the dining room.\n";
			std::cout << "Your choice: ";

			std::string choice;
			std::cin >> choice;
			InputValidation newValidation;
			switch (newValidation.oneintegerValidation(choice))
			{
			case 1:
				air -= 1;
				right->locationDescription(gameState, inventory, air);
				break;

			default:
				std::cout << "There has been an error in the DeadEnd switch logic! \n";
				break;

			}
		}
	}
}

//Pure virtual function to satisfy project requirements
void StoreRoom::locationDescription()
{
	
}
