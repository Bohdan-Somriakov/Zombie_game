#include <iostream>
#include<windows.h>
using namespace std;
///////////poisonDamageFactor = 0.1;
int findTheEnemy(int TheNumberOfEnemies, int level) {
	srand(time(NULL));
	int enemy = rand() % TheNumberOfEnemies;
	while ((enemy > level + 4) || (enemy < level)) {
		enemy = rand() % TheNumberOfEnemies;
	}
	return enemy;
}
string checkAction(string action) {
	while ((action != "a") && (action != "attack") && (action != "r") && (action != "run")) {
		cout << "Wrong action. You can only use either 'attack' (a) or 'run' (r)" <<endl;
		cin >> action;
	}
	return action;
}
int fightZombie(int HP, int AG, int attack) {
	srand(time(NULL));
	Sleep(1000);
	int randomNumber = (rand() % 100);
	int result = 0;
	if (randomNumber <= AG) {
		return HP;
	}
	else {
		result = HP - attack;
		return result;
	}
}
int fightHuman(int HP, int AG, int attack) {
	srand(time(NULL));
	Sleep(1000);
	int randomNumber = (rand() % 100);
	int result = 0;
	if (randomNumber <= AG) {
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
int curseDamage(bool curseZombie, int damage) {
	srand(time(NULL));
	if (((rand() % 5) == 0) && (curseZombie == true)) {
		damage = damage / 2;
		cout << "You was cursed! Your damage was divided by 2 and it is now equal to " << damage << endl;
		return damage;
	} 
	else {
		return damage;
	}
}
int curseAgility(bool curseZombie, int agility) {
	srand(time(NULL));
	if (((rand() % 5) == 1) && (curseZombie == true)) {
		agility = agility / 2;
		cout << "You was cursed! Your agility was divided by 2 and it is now equal to " << agility << endl;
		return agility;
	}
	else {
		return agility;
	}
}
int stunAttack(bool stunZombie, int health, int agility, int zombieDamage, string zombieName) {
	int oldHealth = health;
	srand(time(NULL));
	if (((rand() % 4) == 0) && (stunZombie == true)) {
		health = fightHuman(health, agility, zombieDamage);
		cout << "You was stuned! " << zombieName << " attacks you again! ";
		if (oldHealth == health) {
			cout << "Your health is " << health << "    MISS" << endl;
			return health;
		}
		else {
			cout << "Your health is " << health << "    HIT " << health - oldHealth << endl;
			return health;
		}
	}
	else {
		return health;
	}
}
int copyHealth(bool duplicationZombie, int health, int zombieHealth, string zombieName) {
	srand(time(NULL));
	if (((rand() % 4) == 0) && (duplicationZombie == true)) {
		zombieHealth = health;
		cout << zombieName << " copied your health! His health is now equal to " << health << endl;
		return zombieHealth;
	}
	else {
		return zombieHealth;
	}
}
int copyDamage(bool duplicationZombie, int damage, int zombieDamage, string zombieName) {
	srand(time(NULL));
	if (((rand() % 4) == 1) && (duplicationZombie == true)) {
		zombieDamage = damage;
		cout << zombieName << " copied your damage! His damage is now equal to " << damage << endl;
		return zombieDamage;
	}
	else {
		return zombieDamage;
	}
}
int copyAgility(bool duplicationZombie, int agility, int zombieAgility, string zombieName) {
	srand(time(NULL));
	if (((rand() % 4) == 2) && (duplicationZombie == true)) {
		zombieAgility = agility;
		cout << zombieName << " copied your agility! His agility is now equal to " << agility << endl;
		return zombieAgility;
	}
	else {
		return zombieAgility;
	}
}
int doubleTheDamage(bool doubleTheDamageZombie, int damage, string zombieName) {
	if (doubleTheDamageZombie == true) {
		cout << zombieName << " is becoming stronger! His damage was doubled and it is now equal to " << damage * 2 << endl;
		return damage * 2;
	}
	else {
		return damage;
	}
}
void displayInfoAfterAttackOnZombie(int oldHealth, int health, string name, int damage, int agility) {
	if (oldHealth == health) {
		cout << "Name: " << name << " HP: " << health << " DMG: " << damage << " AG: " << agility << "    MISS" << endl;
	}
	else {
		cout << "Name: " << name << " HP: " << health << " DMG: " << damage << " AG: " << agility << "    HIT " << health - oldHealth << endl;
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
				cout << " P -" << healthBeforeFight * 0.1 << endl;
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