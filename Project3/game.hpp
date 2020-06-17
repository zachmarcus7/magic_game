/****************************************************************
* File name:   game.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Specification file for Game class. Contains all the 
* function prototypes necessary for playing the game.
*****************************************************************/

#include <iostream>
#include <climits>
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blue_men.hpp"
#include "medusa.hpp"
#include "harry_potter.hpp"
#include "iomanip"

#ifndef GAME_H
#define GAME_H

class Game
{

	public:
		Game();
		~Game();
		void combat(Character*, Character*);
		int selection();
		int check_prompt(int, int);
		Character* create_character(int);
		bool check_name(std::string);

};
#endif