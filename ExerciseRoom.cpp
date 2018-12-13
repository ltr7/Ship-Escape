/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "ExerciseRoom.hpp"
#include <iostream>
#include <vector>
#include "InputValidation.hpp"

ExerciseRoom::ExerciseRoom()
{
	
}

ExerciseRoom::~ExerciseRoom()
{
	
}

void ExerciseRoom::locationDescription(int gameState[], std::vector<int> inventory, int air)
{
	if (air <= 0)
	{
		std::cout
			<< "You peek down at the oxygen indicator on your wrist and see you have 0 units of air left. \n"
			<< "A million thoughts race through your head as you realize you can no longer breath, \n"
			<< "but two blazing words pierce the fog of your mind. \n\n"
			<< "  ***************  \n"
			<< "  ***GAME OVER***  \n"
			<< "  ***************  \n\n";
	}

	else if (gameState[3] != 1)
	{
		if (gameState[3] != 1)
		{

			std::cout << "You enter the exercise room \n";
			std::cout << "Rows of exercise bikes line the the walls. \n";
			std::cout << "Weight machines sit empty, like the rest of the space station. \n";
			std::cout << "You see a slip of paper float among the myriad of waterbottles and towels. \n";
			std::cout << "To the south is the living area \n";
			std::cout << "You have " << air << " units of oxygen left. \n\n";

			std::cout << "Which way will you go now? \n";
			std::cout << "1. Go back to the dining hall \n";
			std::cout << "2. Take the slip of paper \n";
			std::cout << "3. Examine the control pad \n";
			std::cout << "Your choice: ";

			std::string choice;
			std::cin >> choice;
			InputValidation newValidation;
			switch (newValidation.oneToThreeintegerValidation(choice))
			{
			case 1:
				air -= 1;
				left->locationDescription(gameState, inventory, air);
				break;

			case 2:
				air -= 1;
				std::cout << "You grab the slip of paper and read it. \n";
				std::cout << "It's an email that says: \n\n";
				std::cout
					<< "Mike, \n"
					<< "The new passcode for the control room is 8675309.\n"
					<< "Be sure to destroy this note after reading.\n"
					<< "-Stan \n\n";
				std::cout << "\"How convenient\", you think to yourself. \n";
				gameState[3] = 1;
				locationDescription(gameState, inventory, air);
				break;

			case 3:
				air -= 1;
				if (gameState[0] == 1) //If player has taken the ship's manual
				{
					std::cout << "You consult the ships manual which tells you the code is 8675309. \n";
					std::cout << "You punch in the code and the door pops open. \n\n";
					bottom->locationDescription(gameState, inventory, air);
				}
				else //If player has took the crowbar earlier
				{
					std::cout << "You see the door has a code, but as the ship's cook, you're unaware of what to punch in. \n";
					std::cout << "This door is supposed to open automatically in the event of an emergency. \n";
					std::cout << "Apparently the door is malfunctioning. \n\n";
					locationDescription(gameState, inventory, air);
				}

			default:
				break;

			}
		}
	}

	else
	{
		std::cout << "Weight machines and exercise bikes sit empty, like the rest of the space station. \n";
		std::cout << "You now have " << air << " units of oxygen left. \n\n";

		std::cout << "What do you do now? \n";
		std::cout << "1. Go back west to the dining hall \n";
		std::cout << "2. Punch the code into the keypad and continue on south to the control room \n";
		std::cout << "Your choice: ";


		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneToTwointegerValidation(choice))
		{
		case 1:
			air -= 1;
			left->locationDescription(gameState, inventory, air);
			break;

		case 2:
			air -= 1;
			bottom->locationDescription(gameState, inventory, air);
			break;

		default:
			break;

		}
	}
}

//Pure virtual function to satisfy project requirements
void ExerciseRoom::locationDescription()
{
	
}
