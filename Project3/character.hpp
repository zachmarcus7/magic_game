/****************************************************************
* File name:   character.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Specification file for abstract character class.
* It's the main class that all the different character types are
* derived from.
*****************************************************************/

#include <cstdlib>
#include <string>
#include <iostream>

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
	protected:
		int armor;
		int strength_points;
		std::string name;
		std::string type;

	public:
		Character();
		~Character();
		virtual int attack() = 0;
		virtual void defense(int) = 0;
		int get_armor() const;
		int get_strength_points() const;
		std::string get_name();
		std::string get_type();
		void set_armor(int);
		void set_strength_points(int);
};
#endif