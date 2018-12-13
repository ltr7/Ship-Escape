/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "Dining.hpp"
#include <iostream>
#include "InputValidation.hpp"

Dining::Dining()
{
}

Dining::~Dining()
{
	
}

//Gamestate 2 controls this location
void Dining::locationDescription(int gameState[], std::vector<int> inventory, int air)
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

	//Runs if the player hasn't taken the oxygen bottle yet
	else if (gameState[2] == 0)
	{

	std::cout
		<< "You enter the dining hall.  Chairs and tables are floating about haphazardly \n"
		<< "An oxygen bottle floats by, which reminds you that you have " << air << " units of oxygen remaining.\n\n"
		<< "To the left, is a door that leads to a storage room. \n"
		<< "There is a door to the right that you know leads to an exercise room, but the door open button isn't illuminiated \n";

		//Runs if player took the manual in the last room
		if (inventory[0] == 1)
		{
			std::cout << "You quickly consult the ship manual you took which informs you the circuit breaker for exercise room door are in the \n";
			std::cout << "storage room to the left \n";
		}
		
		std::cout
		<< "What do you do now? \n"
		<< "1. Go back to the galley \n"
		<< "2. Go check the storage room to the left \n"
		<< "3. Grab the oxygen bottle and add it to your suits reserves \n"
		<< "Your choice: ";

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
		left->locationDescription(gameState, inventory, air);
		break;
	case 3:
		gameState[2] = 1;
		air += 3; //Adds three units of air to the available supply
		this->locationDescription(gameState, inventory, air); //Reruns location after player gets oxygen bottle
		break;

	default:
		std::cout << "There has been an error in the DeadEnd switch logic! \n";
		break;
	}
	
	}

	//Runs if player has taken the oxygen bottle, but not flipped the breaker in the storage room
	else if (gameState[2] == 1)
	{
		
		std::cout
			<< "\nAfter adding the bottle to your suit, you have " << air << " units of oxygen remaining. \n"
			<< "You are in the dining hall.  Chairs and tables are floating about haphazardly \n"
			<< "To the left, is a door that leads to a storage room. \n"
			<< "There is a door to the right that you know leads to an exercise room, but the door open button isn't illuminiated \n\n";


		std::cout
			<< "What do you do now? \n"
			<< "1. Go back to the galley \n"
			<< "2. Go check the storage room to the left \n"
			<< "Your choice: ";

		std::string choice;
		std::cin >> choice;
		InputValidation newValidation;
		switch (newValidation.oneToTwointegerValidation(choice))

		{
		case 1:
			air -= 1;
			top->locationDescription(gameState, inventory, air);
			break;

		case 2:
			air -= 1;
			left->locationDescription(gameState, inventory, air);
			break;

		default:
			std::cout << "There has been an error in the DeadEnd switch logic! \n";
			break;
		}
	}

	//Runs if flipped the breaker in the adjacent storage room
	//The oxygen bottle from earlier can not be retrieved at this point
	else if (gameState[2] == 2)
	{
		
		std::cout
			<< "\nYou are back the dining hall.  Chairs and tables are still floating about haphazardly \n"
			<< "You don't see any errant oxygen bottles this time"
			<< "To the left, is a door that leads to a storage room. \n"
			<< "The exercise room door open button is illuminated now on the right"
			<< "You have " << air << " units of oxygen remaining. \n";



		std::cout
			<< "What do you do now? \n"
			<< "1. Go back to the galley. \n"
			<< "2. Go back into the storage room to the left. \n"
			<< "3. Press the door button for the exercise room. \n"
			<< "Your choice: ";

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
			left->locationDescription(gameState, inventory, air);
			break;
		case 3:
			air -= 1;
			std::cout << "You press the button for the exercise room and thankfully the door opens. \n\n";
			right->locationDescription(gameState, inventory, air);
			break;

		default:
			std::cout << "There has been an error in the DeadEnd switch logic! \n";
			break;
		}

	}
}

//Pure virtual function to satisfy project requirements
void Dining::locationDescription()
{
	
}

