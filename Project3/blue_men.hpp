/****************************************************************
* File name:   blue_men.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Specification file for Blue_Men class. It's derived
* from the Character class. Contains overrided functions for
* attack and defense.
*****************************************************************/

#include "character.hpp"

#ifndef BLUE_MEN_H
#define BLUE_MEN_H

class Blue_Men : public Character
{

	public:
		Blue_Men();
		Blue_Men(std::string);
		~Blue_Men();
		virtual int attack();
		virtual void defense(int);
};
#endif