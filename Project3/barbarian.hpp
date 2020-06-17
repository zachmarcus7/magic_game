/****************************************************************
* File name:   barbarian.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Specification file for Barbarian class. It's derived
* from the Character class. Contains overrided functions for
* attack and defense.
*****************************************************************/

#include "character.hpp"

#ifndef BARBARIAN_H
#define BARBARIAN_H

class Barbarian : public Character
{

	public:
		Barbarian();
		Barbarian(std::string);
		~Barbarian();
		virtual int attack();
		virtual void defense(int);
};
#endif