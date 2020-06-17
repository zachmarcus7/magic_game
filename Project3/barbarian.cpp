/****************************************************************
* File name:   barbarian.cpp
* Assignment:  Project 3
* Author:      Zach Marcus
* Date:        7/24/2019
* Description: Implementation file for the barbarian class.
* Contains a default constructor setting 
* up the stats for class, and also default name to Barbarian1.
* Also contains overrided functions for attack and defense.
*****************************************************************/

#include "barbarian.hpp"


/****************************************************************
* Default constructor for Barbarian class.
*****************************************************************/

Barbarian::Barbarian() : Character()
{
	armor = 0;
	strength_points = 12;
	name = "Barbarian1";
	type = "Barbarian";
}


/****************************************************************
* Constructor for Barbarian class. Only argument accepted is name.
* So there can be multiple Barbarians.
*****************************************************************/

Barbarian::Barbarian(std::string name) : Character()
{
	armor = 0;
	strength_points = 12;
	this->name = name;
	type = "Barbarian";
}



/****************************************************************
* Destructor for Barbarian class.
*****************************************************************/

Barbarian::~Barbarian()
{
}


/****************************************************************
* Function for attack. Barbarian rolls 2 6-sided dice. Total
* is summed and sent back out of the function as an attack.
*****************************************************************/

int Barbarian::attack()
{
	//roll dice
	int attack_roll_one = 0;
	int attack_roll_two = 0;
	attack_roll_one += (rand() % 6 + 1);
	attack_roll_two += (rand() % 6 + 1);

	std::cout << get_name() << "'s roll:  " << attack_roll_one <<
		" and a " << attack_roll_two << " on two 6-sided dice for attack." << std::endl;

	return (attack_roll_one + attack_roll_two);
}


/****************************************************************
* Function for defense. Accepts an int for the amount of attack
* that an enemy has rolled.
*****************************************************************/

void Barbarian::defense(int opponent_attack)
{
	//roll dice
	int defense_roll_one = 0;
	int defense_roll_two = 0;
	defense_roll_one += (rand() % 6 + 1);
	defense_roll_two += (rand() % 6 + 1);

	std::cout << get_name() << "'s roll: " << defense_roll_one <<
		" and a " << defense_roll_two << " on two 6-sided dice for defense." << std::endl;

	//calculate damage inflicted
	int damage_inflicted = (opponent_attack - (defense_roll_one + defense_roll_two) - get_armor());

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