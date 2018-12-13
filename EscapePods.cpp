/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Derived class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "EscapePods.hpp"
#include <iostream>
#include "InputValidation.hpp"

EscapePods::EscapePods()
{
	
}

EscapePods::~EscapePods()
{

}

//There is no way off the escape pod for the player.
//It wouldn't make sense for the player to go back into the airless ship
void EscapePods::locationDescription(int gameState[], std::vector<int> inventory, int air)
{
	if (gameState[5] != 1)
	{
		std::cout << "\n\nSafe in your escape pod with its own oxygen supply, you run through the ";
		std::cout << "startup list attached to the wall above the pod's control panel\n\n";

		std::cout << "Start-up: \n";
		std::cout << "A. Press red button to prime engines \n";
		std::cout << "B. Pull blue handle to ignite engines \n";
		std::cout << "C. Turn turquoise dial 90 degrees counter clockwise to disconnect clamps \n";
		std::cout << "C.a.1.1. Prior to turning turquoise dial, ensure flux capacitor is between 65% and 85% charge \n";
		std::cout << "C.a.2.2. If capacitor is... \n\n";

		std::cout << "Your eyes begin to glaze over as the list extends on and on... \n";
		std::cout << "At the very bottom of the three foot long list you see: \n";
		std::cout << "In case of actual emergency, press Emergency Launch button \n";
		gameState[5] = 1;
	}

	std::cout << " What do you do: \n";
	std::cout << "1. Press the red button \n";
	std::cout << "2. Pull blue handle: \n";
	std::cout << "3. Press the Emergency Launch button: \n";
	std::cout << "Your choice: ";

	InputValidation newValidation;
	std::string choice;
	std::cin >> choice;
	switch (newValidation.oneToThreeintegerValidation(choice))
	{
	case 1:
		std::cout << "\nYou hear a robotic voice say \" Low oxygen levels detected aboard space station. "
			<< "Please press emergency launch button \" \n";
		locationDescription(gameState, inventory, air);
		break;

	case 2:
		std::cout << "\nYou hear a robotic voice say \" Low oxygen levels detected aboard space station. "
			<< "Please press emergency launch button \" \n";
		locationDescription(gameState, inventory, air);
		break;

	case 3:
		std::cout << "\nThe emergency procedures power up the pod and you're blasted away from the oxygenless ship. \n"
		<< "After some time, the pod passes through Earth's atmosphere and you're deposited safely back on Earth. \n"
		<< "  **************************************  \n"
		<< "  ***  Congratulations! You escaped!  **  \n"
		<< "  **************************************  \n\n";
		break;
	default:
		std::cout << "\nThere was a problem with the escape method. \n";

		break;

	}
}

//Pure virtual function to satisfy project requirements
void EscapePods::locationDescription()
{
	
}
