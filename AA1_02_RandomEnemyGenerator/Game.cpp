#include <iostream>
#include <time.h>
#include "Header.h"

int main() {
	srand(time(NULL));

	Enemy enemies[MAX_ENEMIES];

	int i = 0;
	while (i < MAX_ENEMIES)
	{
		enemies[i] = createRandomEnemy();
		int j = i - 1;
		while (j >= 0) {
			if (enemies[i] == enemies[j]) { --i; break; };
			--j;
		};
		i++;
	};

	std::cout << "List of enemies: \n";

	for (const Enemy& e : enemies) {
		std::cout << e.name << " is a " << e.getEnemyTypeString() << " whose life is " << e.health << std::endl;
	}

}