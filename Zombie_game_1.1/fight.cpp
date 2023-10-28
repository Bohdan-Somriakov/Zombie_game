#include <iostream>
using namespace std;
//poisonDamageFactor = 0.1;

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
int poisoningDamageDuration(bool poisoningZombie, int healthBeforeFight) {
	srand(time(NULL));
	int duration = (rand() % 2) + 2;
	int damage = healthBeforeFight * 0.1;
	if (((rand() % 5) == 0) && (poisoningZombie == true)) {
		cout << "You was poisoned! You will take " << damage << " damage for the next " << duration << " turns." << endl;
		return duration; // poisoning for (rand() % 4)+1 turns;
	}
	else {
		return 0;
	}
}
int poisoningDamage(int duration, int health) {
	int damage = 0;
	if (duration > 0) {
		damage = health * 0.1;
		return damage;
	}
	else {
		return damage;
	}
}
void displayInfoAfterAttackOnZombie(int oldHealth, int health, string name , int damage, int agility) {
	if (oldHealth == health) {
		cout << "Name: " << name << " HP: " << health << " DMG: " << damage << " AG: " << agility << "    MISS" << endl;
	}
	else {
		cout << "Name: " << name << " HP: " << health << " DMG: " << damage << " AG: " << agility << "    HIT " << health-oldHealth << endl;
	}
}
void displayInfoAfterAttackOnPlayer(int healthBeforeFight, int oldHealth, int health, string name, int poisonDuration) {
	if (poisonDuration == 0) {
		if (oldHealth == health) {
			cout << name << " attacks you! Your health is " << health << "    MISS" << endl;
		}
		else {
			cout << name << " attacks you! Your health is " << health << "    HIT " << health - oldHealth << endl;
		}
	}
	else {
		if (oldHealth == health + healthBeforeFight * 0.1) {
			cout << name << " attacks you! Your health is " << health << "    MISS";
			if (poisonDuration > 0) {
				cout << " P  -" << healthBeforeFight * 0.1 << endl;
			} 
			else {
				cout << endl;
			}
		}
		else {
			cout << name << " attacks you! Your health is " << health << "    HIT " << health - oldHealth + healthBeforeFight * 0.1;
			if (poisonDuration > 0) {
				cout << " P -" << healthBeforeFight * 0.1 << endl;
			}
			else {
				cout << endl;
			}
		}
	}
}