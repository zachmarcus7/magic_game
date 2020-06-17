/****************************************************************
* File name:   character.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Implementation file for the base Character class.
* Contains constructor, destructor, getters, and setters. Also
* a function definition for attack.
*****************************************************************/

#include "character.hpp"


/****************************************************************
* Constructor for character class. Everything initialized to blank.
*****************************************************************/

Character::Character()
{
	armor = 0;
	strength_points = 0;
	name = " ";
	type = " ";
}


/****************************************************************
* Destructor for character class.
*****************************************************************/

Character::~Character()
{
}


/****************************************************************
* Getter for armor.
*****************************************************************/

int Character::get_armor() const
{
	return armor;
}


/****************************************************************
* Getter for name.
*****************************************************************/

std::string Character::get_name()
{
	return name;
}


/****************************************************************
* Getter for type.
*****************************************************************/

std::string Character::get_type()
{
	return type;
}


/****************************************************************
* Getter for strength points.
*****************************************************************/

int Character::get_strength_points() const
{
	return strength_points;
}


/****************************************************************
* Setter for armor.
*****************************************************************/

void Character::set_armor(int armor)
{
	this->armor = armor;
}


/****************************************************************
* Setter for strength points.
*****************************************************************/

void Character::set_strength_points(int strength_points)
{
	this->strength_points = strength_points;
}


