#include <iostream>

int fight(int HP, int AG, int attack) {
	srand(time(NULL));
	int result = 0;
	if ((rand() % 100) <= AG) {
		return HP;
	}
	else {
		result = HP - attack;
		return result;
	}
}