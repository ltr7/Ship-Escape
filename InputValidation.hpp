/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Input validation class for a text based game about escaping a
** space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP
#include <string>

class InputValidation
{
public:
	int oneintegerValidation(std::string incInteger);
	int oneToTwointegerValidation(std::string incInteger);
	int oneToThreeintegerValidation(std::string incInteger);

};
#endif //!INPUT_VALIDATION_HPP