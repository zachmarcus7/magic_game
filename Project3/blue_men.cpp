/****************************************************************
* File name:   blue_men.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Implementation file for Blue_Men class. It's derived
* from the Character class. Contains a default constructor setting 
* up the stats for Blue Men class, and also default name to Blue Men1.
* Also contains overrided functions for attack and defense.
*****************************************************************/

#include "blue_men.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Blue_Men::Blue_Men() : Character()
{
	armor = 3;
	strength_points = 12;
	name = "Blue Men1";
	type = "Blue Men";
}


/****************************************************************
* Constructor for Blue Men. Only argument accepted is name.
* So there can me multiple Blue Men classes.
*****************************************************************/

Blue_Men::Blue_Men(std::string name) : Character()
{
	armor = 3;
	strength_points = 12;
	this->name = name;
	type = "Blue Men";
}

/****************************************************************
* Destructor for Blue Men class.
*****************************************************************/

Blue_Men::~Blue_Men()
{
}


/****************************************************************
* Function for attack. Blue Men roll 2 10-sided dice. Total
* is summed and sent back out of the function as an attack.
*****************************************************************/

int Blue_Men::attack()
{
	//roll dice
	int attack_roll_one = 0;
	int attack_roll_two = 0;
	attack_roll_one += (rand() % 10 + 1);
	attack_roll_two += (rand() % 10 + 1);

	std::cout << get_name() << "'s roll: " << attack_roll_one <<
		" and a " << attack_roll_two << " on two 10-sided dice for attack." << std::endl;

	return (attack_roll_one + attack_roll_two);
}


/****************************************************************
* Function for defense. Accepts an int for the amount of attack
* that an enemy has rolled.
*****************************************************************/

void Blue_Men::defense(int opponent_attack)
{
	//roll dice
	int defense_roll_one = (rand() % 6 + 1);
	int defense_roll_two = (rand() % 6 + 1);
	int defense_roll_three = (rand() % 6 + 1);

	int defense_total = 0;

	//calculate Mob ability

	if (get_strength_points() > 8)
	{

		std::cout << get_name() << "'s roll: " << defense_roll_one <<
			", " << defense_roll_two << ", and a " << defense_roll_three <<
			" on three 6-sided dice for defense." << std::endl;
		defense_total = defense_roll_one + defense_roll_two + defense_roll_three;
	}
	else if (get_strength_points() > 4)
	{
		std::cout << get_name() << "'s roll: " << defense_roll_one <<
			" and a " << defense_roll_two << " on two 6-sided dice for defense." << std::endl;
		defense_total = defense_roll_one + defense_roll_two;
	}
	else
	{
		std::cout << get_name() << "'s roll: " << defense_roll_one <<
			" on one 6-sided dice for defense." << std::endl;
	}

	//calculate damage inflicted
	int damage_inflicted = (opponent_attack - defense_total - get_armor());


	if (damage_inflicted < 0)
		damage_inflicted = 0;


	strength_points -= damage_inflicted;

	if (strength_points < 0)
		strength_points = 0;

	std::cout << damage_inflicted << " damage inflicted to " << get_name() << std::endl;
	std::cout << get_name() << "'s remaining strength points: " << get_strength_points() << std::endl;


	if (strength_points <= 0)
	{
		strength_points = 0;
		std::cout << get_name() << " has died." << std::endl;
	}
}