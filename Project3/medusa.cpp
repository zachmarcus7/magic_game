/****************************************************************
* File name:   medusa.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Implementation file for Medusa class. It's derived
* from the Character class. Contains a default constructor setting 
* up the stats for class, and also default name to Medusa1.
* Also contains overrided functions for attack and defense.
*****************************************************************/

#include "medusa.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Medusa::Medusa() : Character()
{
	armor = 3;
	strength_points = 8;
	name = "Medusa1";
	type = "Medusa";
}


/****************************************************************
* Constructor for Medusa. Only argument is for name, so there can
* be multipe Medusa classes.
*****************************************************************/

Medusa::Medusa(std::string name) : Character()
{
	armor = 3;
	strength_points = 8;
	this->name = name;
	type = "Medusa";
}


/****************************************************************
* Destructor for Medusa.
*****************************************************************/

Medusa::~Medusa()
{
}


/****************************************************************
* Function for attack. Medusa rolls 2 6-sided dice. Total
* is summed and sent back out of the function as an attack. If
* 12 is rolled, glare is activated - 100 is sent back out.
*****************************************************************/

int Medusa::attack()
{
	//roll dice
	int attack_roll_one = 0;
	int attack_roll_two = 0;
	attack_roll_one += (rand() % 6 + 1);
	attack_roll_two += (rand() % 6 + 1);

	//variable to test glare
	int attack_total = attack_roll_one + attack_roll_two;

	std::cout << get_name() << "'s roll: " << attack_roll_one <<
		" and a " << attack_roll_two << " on two 6-sided dice for attack." << std::endl;

	//check if 12 is rolled
	if (attack_total == 12)
	{
		std::cout << get_name() << " has activated the glare ability." << std::endl;
		return 100;
	}
	else
		return (attack_roll_one + attack_roll_two);
}


/****************************************************************
* Function for defense. Accepts an int for the amount of attack
* that an enemy has rolled.
*****************************************************************/

void Medusa::defense(int opponent_attack)
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


	strength_points -= damage_inflicted;

	if (strength_points < 0)
		strength_points = 0;

	std::cout << damage_inflicted << " damage inflicted to " << get_name() << std::endl;
	std::cout << get_name() << "'s remaining strength points: " << get_strength_points() << std::endl;

	//if medusa dies
	if (strength_points <= 0)
	{
		strength_points = 0;
		std::cout << get_name() << " has died." << std::endl;
	}
}