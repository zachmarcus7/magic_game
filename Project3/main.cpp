/****************************************************************
* File name:   main.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Main file for fantasy combat game. The user is given
* the option to choose from 5 characters. Once they choose 2, the 
* characters fight, and the results of each round are shown.
* Once over, user given the choice to play again.
*****************************************************************/

#include <iostream>
#include <ctime>

#include "menu.hpp"
#include "game.hpp"
#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "harry_potter.hpp"
#include "medusa.hpp"
#include "blue_men.hpp"


int main()
{
	//start the srand seed for functions that return a random number
	srand(static_cast<unsigned int>(time(NULL)));


	//initiate game
	Menu menu1;

	//initiate pointers
	Character* c1 = NULL;
	Character* c2 = NULL;

	//variable for starting prompt
	bool selection = true;

	//starting prompt returns true if the user wants to start the simulation
	std::cout << "::: Fantasy Combat Game :::" << std::endl;
	selection = menu1.startingPrompt();

	//if user selected to start the program
	while (selection)
	{
		//initiate objects of all the required classes
		Game g1;

		//get user input for character selection
		int selection_one = g1.selection();
		c1 = g1.create_character(selection_one);
		
		int selection_two = g1.selection();
		c2 = g1.create_character(selection_two);

		std::cout << std::endl;

		g1.combat(c1, c2);


		//deallocate pointers
		delete c1;
		c1 = NULL;

		delete c2;
		c2 = NULL;

		std::cout << std::endl;

		//ask user of they want to restart or quit
		selection = menu1.endPrompt();
	}

	std::cout << "Exiting game...";

	return 0;
}