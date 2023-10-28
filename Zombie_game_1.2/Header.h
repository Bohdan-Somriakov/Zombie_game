#include <string>
using namespace std;
#pragma once
string to_lower(string);
int findTheEnemy(int, int);
string checkAction(string);
int fightHuman(int, int, int);
int fightZombie(int, int, int);
int poisoningDamageDuration(bool, int);
int poisoningDamage(int, int);
int curseDamage(bool, int);
int curseAgility(bool, int);
int stunAttack(bool, int, int, int, string);
int copyHealth(bool, int, int, string);
int copyDamage(bool, int, int, string);
int copyAgility(bool, int, int, string);
int doubleTheDamage(bool, int, string);
void displayInfoAfterAttackOnZombie(int, int, string, int, int);
void displayInfoAfterAttackOnPlayer(int, int, int, string, int);
int levelUp(int);
int levelUpHealth(int);
int levelUpDamage(int);
int levelUpAgility(int);
void levelUpNotification(int, int, int, int, int);
