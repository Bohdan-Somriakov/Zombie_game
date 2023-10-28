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
		cout << "Wrong action. You can only use either 'attack' (a) or 'run' (r)" << endl;
		cin >> action;
	}
	return action;
}
int fightZombie(int HP, int AG, int attack) {
	srand(time(NULL));
	Sleep(1100);
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
	Sleep(1100);
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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int duration = (rand() % 2) + 2;
	int damage = healthBeforeFight * 0.1;
	if (((rand() % 5) == 0) && (poisoningZombie == true)) {
		SetConsoleTextAttribute(h, 2);
		cout << "You was poisoned! You will take " << damage << " damage for the next " << duration << " turns." << endl;
		SetConsoleTextAttribute(h, 15);
		return duration; 
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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (((rand() % 5) == 0) && (curseZombie == true)) {
		damage = damage / 2;
		SetConsoleTextAttribute(h, 8);
		cout << "You was cursed! Your damage was divided by 2 and it is now equal to " << damage << endl;
		SetConsoleTextAttribute(h, 15);
		return damage;
	}
	else {
		return damage;
	}
}
int curseAgility(bool curseZombie, int agility) {
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (((rand() % 5) == 1) && (curseZombie == true)) {
		agility = agility / 2;
		SetConsoleTextAttribute(h, 8);
		cout << "You was cursed! Your agility was divided by 2 and it is now equal to " << agility << endl;
		SetConsoleTextAttribute(h, 15);
		return agility;
	}
	else {
		return agility;
	}
}
int stunAttack(bool stunZombie, int health, int agility, int zombieDamage, string zombieName) {
	int oldHealth = health;
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (((rand() % 4) == 0) && (stunZombie == true)) {
		health = fightHuman(health, agility, zombieDamage);
		SetConsoleTextAttribute(h, 3);
		cout << "You was stuned! ";
		SetConsoleTextAttribute(h, 8);
		cout << zombieName;
		SetConsoleTextAttribute(h, 3);
		cout << " attacks you again! ";
		if (oldHealth == health) {
			cout << "Your health is " << health;
			SetConsoleTextAttribute(h, 7);
			cout << "    MISS" << endl;
			SetConsoleTextAttribute(h, 15);
			return health;
		}
		else {
			cout << "Your health is " << health;
			SetConsoleTextAttribute(h, 4);
			cout << "    HIT " << health - oldHealth << endl;
			SetConsoleTextAttribute(h, 15);
			return health;
		}
	}
	else {
		return health;
	}
}
int copyHealth(bool duplicationZombie, int health, int zombieHealth, string zombieName) {
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (((rand() % 4) == 0) && (duplicationZombie == true)) {
		zombieHealth = health;
		SetConsoleTextAttribute(h, 8);
		cout << zombieName;
		SetConsoleTextAttribute(h, 6);
		cout << " copied your health! His health is now equal to ";
		SetConsoleTextAttribute(h, 4);
		cout << health << endl;
		SetConsoleTextAttribute(h, 15);
		return zombieHealth;
	}
	else {
		return zombieHealth;
	}
}
int copyDamage(bool duplicationZombie, int damage, int zombieDamage, string zombieName) {
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (((rand() % 4) == 1) && (duplicationZombie == true)) {
		zombieDamage = damage;
		SetConsoleTextAttribute(h, 8);
		cout << zombieName;
		SetConsoleTextAttribute(h, 6);
		cout << " copied your damage! His damage is now equal to ";
		SetConsoleTextAttribute(h, 1);
		cout << damage << endl;
		SetConsoleTextAttribute(h, 15);
		return zombieDamage;
	}
	else {
		return zombieDamage;
	}
}
int copyAgility(bool duplicationZombie, int agility, int zombieAgility, string zombieName) {
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (((rand() % 4) == 2) && (duplicationZombie == true)) {
		zombieAgility = agility;
		SetConsoleTextAttribute(h, 8);
		cout << zombieName;
		SetConsoleTextAttribute(h, 6);
		cout << " copied your agility! His agility is now equal to ";
		SetConsoleTextAttribute(h, 5);
		cout << agility << endl;
		SetConsoleTextAttribute(h, 15);
		return zombieAgility;
	}
	else {
		return zombieAgility;
	}
}
int doubleTheDamage(bool doubleTheDamageZombie, int damage, string zombieName) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (doubleTheDamageZombie == true) {
		SetConsoleTextAttribute(h, 13);
		cout << zombieName << " is becoming stronger! His damage was doubled and it is now equal to ";
		SetConsoleTextAttribute(h, 1);
		cout << damage * 2 << endl;
		SetConsoleTextAttribute(h, 15);
		return damage * 2;
	}
	else {
		return damage;
	}
}
void displayInfoAfterAttackOnZombie(int oldHealth, int health, string name, int damage, int agility) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (oldHealth == health) {
		SetConsoleTextAttribute(h, 8);
		cout << name;
		SetConsoleTextAttribute(h, 4);
		cout << " HP: " << health;
		SetConsoleTextAttribute(h, 1);
		cout << " DMG: " << damage;
		SetConsoleTextAttribute(h, 5);
		cout << " AG: " << agility;
		SetConsoleTextAttribute(h, 7);
		cout <<"    MISS" << endl;
		SetConsoleTextAttribute(h, 15);
	}
	else {
		SetConsoleTextAttribute(h, 8);
		cout << name;
		SetConsoleTextAttribute(h, 4);
		cout << " HP: " << health;
		SetConsoleTextAttribute(h, 1);
		cout << " DMG: " << damage;
		SetConsoleTextAttribute(h, 5);
		cout << " AG: " << agility;
		SetConsoleTextAttribute(h, 4);
		cout << "    HIT " << health - oldHealth << endl;
		SetConsoleTextAttribute(h, 15);
	}
}
void displayInfoAfterAttackOnPlayer(int healthBeforeFight, int oldHealth, int health, string name, int poisonDuration) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (poisonDuration == 0) {
		if (oldHealth == health) {
			SetConsoleTextAttribute(h, 8);
			cout << name;
			SetConsoleTextAttribute(h, 15);
			cout << " attacks you! Your health is " << health;
			SetConsoleTextAttribute(h, 7);
			cout << "    MISS" << endl;
			SetConsoleTextAttribute(h, 15);
		}
		else {
			SetConsoleTextAttribute(h, 8);
			cout << name;
			SetConsoleTextAttribute(h, 15);
			cout << " attacks you! Your health is " << health;
			SetConsoleTextAttribute(h, 4);
			cout << "    HIT " << health - oldHealth << endl;
			SetConsoleTextAttribute(h, 15);
		}
	}
	else {
		if (oldHealth == health + healthBeforeFight * 0.1) {
			SetConsoleTextAttribute(h, 8);
			cout << name;
			SetConsoleTextAttribute(h, 15);
			cout << " attacks you! Your health is " << health;
			SetConsoleTextAttribute(h, 7);
			cout << "    MISS";
			SetConsoleTextAttribute(h, 15);
			if (poisonDuration > 0) {
				SetConsoleTextAttribute(h, 2);
				cout << " P -" << healthBeforeFight * 0.1 << endl;
				SetConsoleTextAttribute(h, 15);
			}
			else {
				cout << endl;
			}
		}
		else {
			SetConsoleTextAttribute(h, 8);
			cout << name;
			SetConsoleTextAttribute(h, 15);
			cout << " attacks you! Your health is " << health;
			SetConsoleTextAttribute(h, 4);
			cout << "    HIT " << health - oldHealth + healthBeforeFight * 0.1;
			SetConsoleTextAttribute(h, 15);
			if (poisonDuration > 0) {
				SetConsoleTextAttribute(h, 2);
				cout << " P -" << healthBeforeFight * 0.1 << endl;
				SetConsoleTextAttribute(h, 15);
			}
			else {
				cout << endl;
			}
		}
	}
}