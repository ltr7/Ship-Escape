/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Date: 11/28/17
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "LivingArea.hpp"
#include <iostream>
#include "InputValidation.hpp"

LivingArea::LivingArea()
{
	
}

LivingArea::~LivingArea()
{
	
}

void LivingArea::locationDescription(int gameState[], std::vector<int> inventory, int air)
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

	if (gameState[4] != 1)
	{
		
		std::cout << "You enter the crew quarters \n";
		std::cout << "Rows of three high bunk beds sit along the walls \n";
		std::cout << "You notice you have just " << air << " units of oxygen left. \n";
		std::cout << "You recall that there's a spare oxygen tank in your footlocker by your bed\n";

		std::cout << "Which way will you go now? \n";
		std::cout << "1. Go back to the exercise room \n";
		std::cout << "2. Go south to the control Room \n";
		std::cout << "3. Get the oxygen tank from your footlocker \n";
		std::cout << "Your choice: ";


		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneToThreeintegerValidation(choice))
		{
		case 1:
			air -= 1;
			top->locationDescription(gameState, inventory, air);
			break;

		case 2:
			air -= 1;
			bottom->locationDescription(gameState, inventory, air);
			break;

		case 3:
			std::cout << "You float over to your bed and retrieve the oxygen tank";
			air += 3; //Adds three oxygen units to user's air supply
			std::cout << "You now have " << air << " units of oxygen left. \n";
			gameState[4] = 1;
			locationDescription(gameState, inventory, air);
			break;

		default:
			std::cout << "There has been an error in the Exercise Room switch logic! \n";
			break;

		}
	}
	else
	{
		std::cout << "Now that you have the air canister, it's time to move on to the control room \n";

 
	}
}

//Pure virtual function to satisfy project requirements
void LivingArea::locationDescription()
{
	
}
