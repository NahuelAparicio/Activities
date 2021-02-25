#pragma once
#include <iostream>
#define MAX_ENEMIES 4

enum class EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH };
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

//chech if the enemies are the same
bool equalEnemies(Enemy enemy1, Enemy enemy2) {

	if (enemy1.name == enemy2.name && enemy1.type == enemy2.type)
		return true;
	else
		return false;
}

Enemy createRandomEnemy() {

	int randNum = rand() % (3 - 0 + 1) + 0; //Generate a random number between 2 numbers
	Enemy randEnemy;

	for (int i = 0; i < sizeof(enemyNames); i++)
	{
		if (i == randNum)
			randEnemy.name = enemyNames[i];
	}

	randEnemy.health = rand() % (200 - 10 + 1) + 1;

	return randEnemy;
}

int main() {

	Enemy enemies[MAX_ENEMIES];

	for (int i = 0; i < sizeof(enemies); i++)
	{
		enemies[i] = createRandomEnemy();
	}

	return 0;
}
