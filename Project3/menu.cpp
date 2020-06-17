/****************************************************************
* File name:   menu.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/27/2019
* Description: Implementation file for the menu class. It contains
*              the defintion for startingPrompt() - which prompts the
*              user to start or quit the program. There's also a
*              definition for a checker function - which validates
*              the user's input from the starting prompt.
*****************************************************************/

#include "menu.hpp"

/****************************************************************
* Function that executes at start of program. It asks the user
* if they want to start, which returns true, or quit, which returns
* false.
*****************************************************************/

bool Menu::startingPrompt()
{
	std::cout << "(1) to start" << std::endl;
	std::cout << "(2) to quit" << std::endl;
	std::cout << "Enter option: " << std::endl;

	int answer = checkStartingPrompt();

	if (answer == 1)
	{
		return true;
	}
	else if (answer == 2)
	{
		return false;
	}
	else
		return false;
}


/****************************************************************
* Function that checks if the user entered a 1 or a 2 to start
* or quit the program, then returns their selection back to the program.
*****************************************************************/

int Menu::checkStartingPrompt()
{
	int answer = 0;

	std::cin >> std::setw(1) >> answer;

	while ((!std::cin.good()) || ((!(answer == 1)) && (!(answer == 2))))
	{
		std::cout << "Invalid value entered." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Enter correct value: ";
		//make sure only one integer is accepted
		std::cin >> std::setw(1) >> answer;
	}

	//clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	return answer;
}


/****************************************************************
* Function that executes at end of program. It asks the user
* if they want to restart, which returns true, or quit, which returns
* false.
*****************************************************************/

bool Menu::endPrompt()
{
	std::cout << "(1) to restart" << std::endl;
	std::cout << "(2) to quit" << std::endl;
	std::cout << "Enter option: " << std::endl;

	int answer = checkStartingPrompt();

	if (answer == 1)
	{
		return true;
	}
	else if (answer == 2)
	{
		return false;
	}
	else
		return false;
}