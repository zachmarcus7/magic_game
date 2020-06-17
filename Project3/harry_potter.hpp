/****************************************************************
* File name:   harry_potter.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Specification file for Harry_Potter class. It's derived
* from the Character class. Contains overrided functions for
* attack and defense.
*****************************************************************/

#include "character.hpp"

#ifndef HARRY_POTTER_H
#define HARRY_POTTER_H

class Harry_Potter : public Character
{
	private:
		//bool to check if harry potter has used his hogwards ability or not
		bool hogwarts;

	public:
		Harry_Potter();
		Harry_Potter(std::string);
		~Harry_Potter();
		virtual int attack();
		virtual void defense(int);
};
#endif