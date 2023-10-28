#include <string>
using namespace std;
#pragma once
string to_lower(string);
int fight(int, int, int);
int poisoningDamageDuration(bool, int);
int poisoningDamage(int, int);
void displayInfoAfterAttackOnZombie(int, int, string , int, int );
void displayInfoAfterAttackOnPlayer(int, int, int, string, int);
int levelUp(int);
int levelUpHealth(int);
int levelUpDamage(int);
int levelUpAgility(int);
void levelUpNotification(int, int, int, int ,int);