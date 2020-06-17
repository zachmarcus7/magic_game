/****************************************************************
* File name:   medusa.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Specification file for Medusa class. It's derived
* from the Character class. Contains overrided functions for
* attack and defense.
*****************************************************************/

#include "character.hpp"

#ifndef MEDUSA_H
#define MEDUSA_H

class Medusa : public Character
{

	public:
		Medusa();
		Medusa(std::string);
		~Medusa();
		virtual int attack();
		virtual void defense(int);
};
#endif