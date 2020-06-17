/****************************************************************
* File name:   vampire.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Specification file for Vampire class. It's derived
* from the Character class. Contains overrided functions for
* attack and defense.
*****************************************************************/

#include "character.hpp"

#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire : public Character
{

	public:
		Vampire();
		Vampire(std::string);
		~Vampire();
		virtual void defense(int);
		virtual int attack();
};
#endif