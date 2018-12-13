/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "ControlRoom.hpp"
#include <iostream>
#include <vector>
#include "InputValidation.hpp"

ControlRoom::ControlRoom()
{
	
}

ControlRoom::~ControlRoom()
{
	
}

void ControlRoom::locationDescription(int gameState[], std::vector<int> inventory, int air)
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

	else 
	{
		std::cout << "You look around the control room. \n"
			<< "Screens and consoles fill the room. \n"
			<< "This normally chaotic room is eerily quiet and bathed in flashing red lights. \n"
			<< "To the left you rows of red lights indicating launched escape pods. \n"
			<< "It appears though that your presonal escape pod is still in place to the left. \n"
			<< "You could also try fixing the recirculator yourself, but realize you only have " << air << " units of oxygen remaining. \n\n";

		std::cout << "What do you do now? \n";
		std::cout << "1. Go back to the to exercise area \n";
		std::cout << "2. Punch the button and escape to freedom \n";
		std::cout << "3. Take a shot at saving the space station by reprogramming the air recirculation computer \n";
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
			std::cout << "You press the button next to the hatch and nothing happens \n";

			if (inventory.at(0) == 1) //If player picked up manual earlier
			{
				std::cout << "You leaf through the operations manual from earlier looking for any information that could help. \n"
					<< "The manual unhelpfully offers:  If your escape pod door does not open, please contact maintenance. \n"
					<< "You slam your hand into the button in frustration, and suprisingly, the hatch opens \n";
			}

			else //If player picked up crowbar
			{
				std::cout << "With only " << air << " units of oxygen left, you're out of options. \n"
					<< "You say out loud \"If only I'd brought the manual and not this useless crowbar\""
					<< " and slam the crowbar into the hatch.  Much to your suprise, the hatch pops open. \n";
			}
			std::cout << "As you slide into the escape pod, you think to yourself \"Maybe sometimes violence is the answer!\"";

			left->locationDescription(gameState, inventory, air);
			break;

		case 3:
			air -= 1;

			if (inventory[0] == 1) //If player picked up manual earlier
			{
				std::cout << "You leaf through the operations manual from earlier looking for any information that could help. \n"
					<< "The part of the manual dealing with air recirculation is way above your head, besides you're not even \n "
					<< "sure where the oxygen went.\n"
					<< "It's probably best to just get in the escape pod because you're making no headway\n\n";
			}

			else //If player picked up crowbar
			{
				std::cout << "Maybe the ship's manual from earlier would have helped. \n";
				std::cout << "Because repeatedly hitting the main control panel with this crowbar has not. \n\n";
				std::cout << "It's probably best to just get in the escape pod because you're making no headway\n";
			}

			locationDescription(gameState, inventory, air);
			break;
		default:
			break;

		}
	}

}

//Pure virtual function
void ControlRoom::locationDescription()
{
	
}
