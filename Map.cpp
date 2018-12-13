/***********************************************************************************
** Program Name: Space Cook
** Author: Lee Rice
** Last modified: 12/13/18
** Description: Map class for a text based game about escaping a space station
**
** To run this program, simply run the SpaceEscape file after compiling
***********************************************************************************/
#include "Map.hpp"

Map::Map()
{
	mostNorth = nullptr;
	mostSouth = nullptr;
	mostEast = nullptr;
	mostWest = nullptr;
	center = nullptr;
}

Map::~Map()
{
	
}

void Map::addNorth(Space *incSpace)
{
	//Creates center of the map
	if (center == nullptr)
	{
		center = incSpace;
		center->top = nullptr;
		center->left = nullptr;
		center->right = nullptr;

	}
	//Adds dead end to map
	else if (center->top == nullptr)
	{
		center->top = incSpace;
		Space *nodePtr = center->top;
		nodePtr->bottom = center;
		nodePtr->left = nullptr;
		nodePtr->right = nullptr;

	}

}

void Map::addSouth(Space *incSpace)
{

	//Adds dining hall node to map
	if (center->bottom == nullptr)
	{
		center->bottom = incSpace;
		Space *nodePtr = center->bottom;
		nodePtr->top = center;
		mostSouth = center->bottom;

	}

	else if (mostEast != nullptr)
	{

		mostEast->bottom = incSpace;
		Space *nodePtr = mostEast->bottom;
		nodePtr->top = mostEast;
		nodePtr->right = nullptr;
		nodePtr->left = nullptr;
		mostSouth = mostEast->bottom;

	}

	else
	{
		//Adds control room node to map
		mostSouth->bottom = incSpace;
		Space *nodePtr = mostSouth->bottom;
		nodePtr->top = mostSouth;
		nodePtr->right = nullptr;
		nodePtr->bottom = nullptr;
		mostSouth = nodePtr;

	}
	
}

void Map::addEast(Space *incSpace)
{
	//Adds exercise room node to map
	if (mostSouth->right == nullptr)
	{
		mostSouth->right = incSpace;
		Space *nodePtr = mostSouth->right;
		nodePtr->top = nullptr;
		nodePtr->bottom = nullptr;
		mostEast = nodePtr;
		mostEast->left = mostSouth;

	}

}

void Map::addWest(Space *incSpace)
{
	//Add store room node to map
	if (mostWest == nullptr)
	{
		mostSouth->left = incSpace;
		Space *nodePtr = mostSouth->left;
		nodePtr->top = nullptr;
		nodePtr->left = nullptr;
		nodePtr->right = mostSouth;
		mostWest = nodePtr;
	} 

	//Adds escape pod node to map
	else
	{
		mostSouth->left = incSpace;
		Space *nodePtr = mostSouth->left;
		nodePtr->top = nullptr;
		nodePtr->bottom = nullptr;
		nodePtr->left = nullptr;

	}
}
