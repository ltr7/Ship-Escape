r/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Input validation class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#include "InputValidation.hpp"
#include <iostream>


int InputValidation::oneintegerValidation(std::string incInteger)
{

	for (size_t i = 0; i < incInteger.size(); i++)
	{
		//casts char to an ascii value
		while (incInteger[i] != static_cast<int>(49))
		{
			std::cout << "Please select one. It's the only option: ";
			std::cin.ignore(10000, '\n'); //Ignores 10000 characters up to the next newline symbol
			std::cin.clear();
			std::cin >> incInteger;
		}
	}
	return std::stoi(incInteger); //Converts string to integer if validation passes
}


int InputValidation::oneToTwointegerValidation(std::string incInteger)
{

	for (size_t i = 0; i < incInteger.size(); i++)
	{
		//casts char to an ascii value
		while ((incInteger[i] < static_cast<int>(49)) || (incInteger[i] > static_cast<int>(50)))
		{
			std::cout << "Please select between one and two: ";
			std::cin.ignore(10000, '\n'); //Ignores 10000 characters up to the next newline symbol
			std::cin.clear();
			std::cin >> incInteger;
		}
	}
	return std::stoi(incInteger); //Converts string to integer if validation passes
}


int InputValidation::oneToThreeintegerValidation(std::string incInteger)
{

	for (size_t i = 0; i < incInteger.size(); i++)
	{
		//casts char to an ascii value
		while ((incInteger[i] < static_cast<int>(49)) || (incInteger[i] > static_cast<int>(51)))
		{
			std::cout << "Please choose between one, two and three: ";
			std::cin.ignore(10000, '\n'); //Ignores 10000 characters up to the next newline symbol
			std::cin.clear();
			std::cin >> incInteger;
		}
	}
	return std::stoi(incInteger); //Converts string to integer if validation passes
}