/****************************************************************
* File name:   menu.hpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/8/2019
* Description: Specification file for the menu class. It contains
*              the declarations for the startingPrompt function
*              and the checker function checkStartingPrompt. Also
*              the endPrompt function, which displays at end of program.
*****************************************************************/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <climits>

class Menu
{
public:
	bool startingPrompt();
	int checkStartingPrompt();
	bool endPrompt();
};
#endif
