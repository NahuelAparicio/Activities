#pragma once
#include <iostream>
#include <time.h>
#define MAX_ENEMIES 5

enum class EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH };
EnemyType arrayTypes[4] = { EnemyType::ZOMBIE, EnemyType::VAMPIRE, EnemyType::GHOST , EnemyType::WITCH };
std::string enemyNames[4] = { "Anacleto", "Bonifacio", "Jordi", "Nahuel" };

std::string getEnemyTypeString(EnemyType type) {
	std::string tempstring;
	switch (type)
	{
	case EnemyType::ZOMBIE:
		tempstring = "ZOMBIE";
		break;
	case EnemyType::VAMPIRE:
		tempstring = "VAMPIRE";
		break;
	case EnemyType::GHOST:
		tempstring = "GHOST";
		break;
	case EnemyType::WITCH:
		tempstring = "WITCH";
		break;
	default:
		break;
	}

	return tempstring;
}

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

//check if the enemies are the same
bool equalEnemies(Enemy enemy1, Enemy enemy2) {

	if (enemy1.name == enemy2.name && enemy1.type == enemy2.type)
		return true;
	else
		return false;
}

Enemy createRandomEnemy() {

	int randNumName = rand() % (3 - 0 + 1) + 0; //Generate a random number between 2 numbers
	int randNumType = rand() % (3 - 0 + 1) + 0;
	Enemy randEnemy;

	//Get a random name
	for (int i = 0; i < sizeof(enemyNames); i++)
	{
		if (i == randNumName)
			randEnemy.name = enemyNames[i];
	}

	//Get a random type
	for (int i = 0; i < sizeof(arrayTypes); i++)
	{
		if (i == randNumType) {
			randEnemy.type = arrayTypes[i];
		}
	}

	randEnemy.health = rand() % (200 - 10 + 1) + 10; //Get random health

	return randEnemy;
}

int main() {

	Enemy enemies[MAX_ENEMIES];
	srand(time(NULL));

	//error 
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		enemies[i] = createRandomEnemy();
	}

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		for (int j = 0; j < MAX_ENEMIES; j++)
		{
			if (equalEnemies(enemies[i], enemies[j]) == true && i != j) {
				enemies[i] = createRandomEnemy();
			}
		}
	}


	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		std::cout << enemies[i].name << " is a " << getEnemyTypeString(enemies[i].type) << " whose life is " << enemies[i].health << std::endl;
	}

	/*for (int i = 0; i < MAX_ENEMIES; i++)
	{
		for (int j = 0; j < MAX_ENEMIES; j++)
		{
			if ((enemies[i].name == "Jordi" || enemies[i].name == "Nahuel") && (enemies[j].name == "Nahuel" || enemies[j].name == "Jordi"))
				if (enemies[i].name != enemies[j].name) {
					if (enemies[i].health > enemies[j].health)
						std::cout << "The best one is " << enemies[i].name << std::endl;
					else
						std::cout << "The best one is " << enemies[j].name << std::endl;
				}
		}
	}*/

	return 0;
}
