#pragma once
#include <iostream>

#define MAX_ENEMIES 5
#define MAX_LIFE 200
#define MAX_NAMES 4

enum class EnemyType 
{
	ZOMBIE,
	VAMPIRE,
	GHOST,
	WITCH,
	COUNT
};

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;

	std::string	getEnemyTypeString() const {
		switch (type)
		{
		case EnemyType::ZOMBIE: return "zombie";
		case EnemyType::VAMPIRE: return "vampire";
		case EnemyType::GHOST: return "ghost";
		case EnemyType::WITCH: return "witch";
		default: return "";
		}
	}
};

Enemy createRandomEnemy() {
	const std::string NAMES[]{ "Anacleto", "Bonifacio", "Jordi", "Nahuel" };

	return Enemy{
		EnemyType(rand() % int(EnemyType::COUNT)),
		NAMES[rand() % MAX_ENEMIES],
		rand() % MAX_LIFE
	};
}

bool operator==(const Enemy& e1, const Enemy& e2) {
	return e1.name == e2.name && e1.type == e2.type;
}

