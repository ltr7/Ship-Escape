/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "Galley.hpp"
#include <iostream>
#include "InputValidation.hpp"


Galley::Galley()
{

	top = nullptr;
	left = nullptr;
	right = nullptr;
	bottom = nullptr;
}


Galley::~Galley()
{
}


void Galley::locationDescription(int gameState[], std::vector<int> inventory, int air)
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

	//Runs if player does not have the space suit
	else if (gameState[0] == 0)
	{ 
		std::cout << "Around you is the space station's galley \n"
			<< "that has been your place of work for the previous three months. \n"
			<< "No time to think about that though, as you quickly recall from your \n"
			<< "training that getting to an escape pod is all that matters now. \n\n";

		std::cout << "Next to the oven sits the station operation manual that you had been reading "
			<< "and a crowbar. \n"
			<< "You'll need a free hand to pull yourself along the zero gravity environment and can only carry one.\n"
			<< "Which do you take: \n"
			<< "1. Take the manual \n"
			<< "2. Take the crowbar \n"
			<< "Your choice: ";

		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneToTwointegerValidation(choice))
		{
		case 1:
			std::cout
				<< "You pick up the manual \n\n";
			gameState[0] = 1; //gamestate[0] to 1 indicates which item player has taken from the galley
			inventory.push_back(1); //1 indicates player took manual
			break;

		case 2:
			std::cout
				<< "You grab the crowbar \n\n";
			gameState[0] = 2; //gamestate[0] to 1 indicates which item player has taken from the galley
			inventory.push_back(2); //2 indicates player took the crowbar
			break;

		default:
			std::cout << "There has been an error in the DeadEnd switch logic! \n";
			break;
		}

		std::cout << "A gauge you'd really never given much thought to before catches your eye. \n"
			<< "It's the oxygen gauge for the dining hall to the south, and it's dropping rapidly. \n"
			<< "Your space suit is in the storage room to the north, and it wouldn't be wise to venture south without it.\n\n";

		std::cout << "You decide to : \n"
			<< "1. Go north and get your space suit \n"
			<< "2. Brave the low oxygen environment to the south \n"
			<< "Your choice: ";

		std::cin >> choice;
		switch (newValidation.oneToTwointegerValidation(choice))
		{
		case 1:
			std::cout
				<< "You head north into the storage room \n";
			top->locationDescription(gameState, inventory, air);
			break;

		case 2:

			std::cout
				<< "You head south into the dining hall. \n\n"
				<< "You open the airlock to the dining hall, and hear a deafening WOOSH \n"
				<< "as the oxygen is sucked from the galley into the dining hall.  You think to \n"
				<< "yell for someone to tell you what's going on, but no sound comes out. \n"
				<< "A million thoughts race through your head as you realize you can no longer breath, \n"
				<< "but two blazing words pierce the fog of your mind. \n\n"
				<< "  ***************  \n"
				<< "  ***GAME OVER***  \n"
				<< "  ***************  \n\n";

			break;
		default:
			std::cout << "There has been an error in the DeadEnd switch logic! \n";
			break;
			
		}
	}

	//Runs if player has the space suit
	else
	{
		std::cout << "\nAround you is the space station's galley \n"
			<< "that has been your place of work for the previous three months \n"
			<< "Now that you're in your space suit, it's time to get on with getting \n"
			<< "off this ship. \n\n"
			<< "A glance at the suit's oxygen gauge shows you have " << air << " units of oxygen remaining. \n";


		std::cout << "You decide to : \n"
			<< "1. Go back north into the storage room \n"
			<< "2. Head into the low oxygen environment to the south \n"
			<< "Your choice: "; 

		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneToTwointegerValidation(choice))
	{
	case 1:
		air -= 1;
		std::cout << "\nYou head north into the storage room \n";
		top->locationDescription(gameState, inventory, air);
		break;

	case 2:
		air -= 1;
		std::cout << "\nYou open the airlock and step into the station's dining hall \n";
		bottom->locationDescription(gameState, inventory, air);
		break;

	default:
		std::cout << "There has been an error in the DeadEnd switch logic! \n";
		break;

	}
}

}

//Pure virtual function to satisfy project requirements
void Galley::locationDescription()
{

}
