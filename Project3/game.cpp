/****************************************************************
* File name:   game.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Implementation file for the game class. It's the 
* class that goes through the steps of the game: getting user input,
* having characters fight, and displaying stats.
*****************************************************************/

#include "game.hpp"


/****************************************************************
* Constructor for Game class.
*****************************************************************/

Game::Game()
{
}


/****************************************************************
* Destructor for Game class.
*****************************************************************/

Game::~Game()
{
}


/****************************************************************
* Function for combat between two characters. Accepts two 
* pointer to Characters and goes through combat until one
* Character dies.
*****************************************************************/

void Game::combat(Character* c1, Character* c2)
{
	std::cout << "::: Combat :::" << std::endl;
	std::cout << c1->get_name() << " vs. " << c2->get_name();
	std::cout << std::endl;

	int round = 1;

	//go through the rounds of combat
	while ((c1->get_strength_points()) > 0 && (c2->get_strength_points() > 0))
	{
		std::cout << "::: Round " << round << " :::" << std::endl;

		//attacker's type
		std::cout << "Attacker's info:" << std::endl;
		std::cout << "Name: " << c1->get_name() << std::endl;
		std::cout << "Type: " << c1->get_type() << std::endl;

		//defender's type
		std::cout << "Defender's info:" << std::endl;
		std::cout << "Name: " << c2->get_name() << std::endl;
		std::cout << "Type: " << c2->get_type() << std::endl;
		std::cout << "Armor: " << c2->get_armor() << std::endl;
		std::cout << "Strength points: " << c2->get_strength_points() << std::endl << std::endl;

		//character 1 attacks character 2
		int first_attack = c1->attack();
		c2->defense(first_attack);


		if (c2->get_strength_points() > 0)
		{
			std::cout << std::endl;

			//attacker's type
			std::cout << "Attacker's info:" << std::endl;
			std::cout << "Name: " << c2->get_name() << std::endl;
			std::cout << "Type: " << c2->get_type() << std::endl;

			//defender's type
			std::cout << "Defender's info:" << std::endl;
			std::cout << "Name: " << c1->get_name() << std::endl;
			std::cout << "Type: " << c1->get_type() << std::endl;
			std::cout << "Armor: " << c1->get_armor() << std::endl;
			std::cout << "Strength points: " << c1->get_strength_points() << std::endl << std::endl;

			//character 2 attacks character 1
			int second_attack = c2->attack();
			c1->defense(second_attack);
		}

		std::cout << std::endl;

		round++;
	}

	if (c1->get_strength_points() == 0)
	{
		if (c2->get_name() == "Blue Men")
			std::cout << c2->get_name() << " have won." << std::endl;
		else
			std::cout << c2->get_name() << " has won." << std::endl;
	}
	else
	{
		if (c1->get_name() == "Blue Men")
			std::cout << c1->get_name() << " have won." << std::endl;
		else
			std::cout << c1->get_name() << " has won." << std::endl;
	}
}


/****************************************************************
* Function that returns an integer depending on which character
* type the user chooses.
*****************************************************************/

int Game::selection()
{
	std::cout << "::: Character Selection :::" << std::endl;
	std::cout << "(1) - for Vampire" << std::endl;
	std::cout << "(2) - for Barbarian" << std::endl;
	std::cout << "(3) - for Blue Men" << std::endl;
	std::cout << "(4) - for Medusa" << std::endl;
	std::cout << "(5) - for Harry Potter" << std::endl;
	std::cout << "Enter selection:" << std::endl;

	int answer = check_prompt(1, 5);

	return answer;
}


/****************************************************************
* Function that checks if the user entered a number between min and max.
*****************************************************************/

int Game::check_prompt(int min, int max)
{
	int answer = 0;

	std::cin >> std::setw(1) >> answer;

	while ((!std::cin.good()) || (!(answer >= min)) || (!(answer <= max)))
	{
		std::cout << "Invalid value entered." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Enter correct value:" << std::endl;
		//make sure only one integer is accepted
		std::cin >> std::setw(1) >> answer;
	}

	//clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	return answer;
}


/****************************************************************
* Function that creates a pointer to a new character type depending
* on the int that's sent to it. User is prompted to enter a name
* for the character.
*****************************************************************/

Character* Game::create_character(int answer)
{
	//make sure user only enters characters for name
	bool name_check = false;
	std::string temp_name = " ";
	while (name_check == false)
	{
		std::cout << "Enter name of character:" << std::endl;
		std::cout << "Please enter only characters." << std::endl;
		std::getline(std::cin, temp_name);
		name_check = check_name(temp_name);
	}
	
	//create character pointer to return
	Character* ptr = NULL;

	if (answer == 1)
		ptr = new Vampire(temp_name);
	else if (answer == 2)
		ptr = new Barbarian(temp_name);
	else if (answer == 3)
		ptr = new Blue_Men(temp_name);
	else if (answer == 4)
		ptr = new Medusa(temp_name);
	else
		ptr = new Harry_Potter(temp_name);

	return ptr;
}


/****************************************************************
* Function that checks if a user entered a name correctly. Argument
* passed is a string to be checcked. Returns true if there are only 
* characters in string.
*****************************************************************/

bool Game::check_name(std::string name)
{
	//variable to check if one of the letters in the name isn't a character
	bool flag;

	for (unsigned i = 0; i < name.size(); i++)
	{
		if ( ((name[i] >= 'a') && (name[i] <= 'z')) || ((name[i] >= 'A') && (name[i] <= 'Z')) )
			flag = true;
		else
			return false;
	}

	return flag;
}