/****************************************************************
* File name:   vampire.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Implementation file for the Vampire class. 
* Contains a default constructor setting
* up the stats for class, and also default name to Vampire1.
* Also contains overrided functions for attack and defense.
*****************************************************************/

#include "vampire.hpp"


/****************************************************************
* Default constructor.
*****************************************************************/

Vampire::Vampire() : Character()
{
	armor = 1;
	strength_points = 18;
	name = "Vampire1";
	type = "Vampire";
}


/****************************************************************
* Constructor for Vampire. Only argument accepted is name, so
* there can be multiple Vampire classes.
*****************************************************************/

Vampire::Vampire(std::string name) : Character()
{
	armor = 1;
	strength_points = 18;
	this->name = name;
	type = "Vampire";
}


/****************************************************************
* Destructor for Vampire.
*****************************************************************/

Vampire::~Vampire()
{
}


/****************************************************************
* Function for attack. Vampire rolls 1 12-sided dice. Total
* is sent back out of the function as an attack.
*****************************************************************/

int Vampire::attack()
{
	int attack_total = 0;

	attack_total += (rand() % 12 + 1);

	std::cout << get_name() << "'s roll: " << attack_total <<
		" on a 12-sided dice for attack." << std::endl;

	return attack_total;
}


/****************************************************************
* Function for defense. Accepts an int for the amount of attack
* that an enemy has rolled.
*****************************************************************/

void Vampire::defense(int opponent_attack)
{
	//roll dice
	int defense_roll = 0;
	defense_roll += (rand() % 6 + 1);

	std::cout << get_name() << "'s roll: " << defense_roll <<
		" on one 6-sided dice for defense." << std::endl;

	//calculate damage inflicted
	int damage_inflicted = (opponent_attack - defense_roll - get_armor());

	if (damage_inflicted < 0)
		damage_inflicted = 0;

	//calculate charm chance
	int charm_chance = (rand() % 2 + 1);

	//if charm was successful
	if (charm_chance == 1)
	{
		std::cout << get_name() << " used charm. No damage inflicted." << std::endl;
		std::cout << get_name() << "'s remaining strength points: " << get_strength_points() << std::endl;
	}
	else //if charm was unsuccesful
	{

		strength_points -= damage_inflicted;

		if (strength_points < 0)
			strength_points = 0;

		std::cout << damage_inflicted << " damage inflicted to " << get_name() << std::endl;
		std::cout << get_name() << "'s remaining strength points: " << get_strength_points() << std::endl;

		//if vampire dies
		if (strength_points <= 0)
		{
			strength_points = 0;
			std::cout << get_name() << " has died." << std::endl;
		}
	}
}
