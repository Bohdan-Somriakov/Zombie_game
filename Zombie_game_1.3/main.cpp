#include <iostream>
#include<windows.h>
#include <locale> // tolower
#include "Header.h"
using namespace std;

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    SetConsoleTextAttribute(h, 15);
    string name; //name of the user
    int health = 10;
    int damage = 3;
    int agility = 5; //chance of dodge
    int TotalXP = 0;
    int level = 0;
    string action = "attack";
    bool success = false;
    cout << "What is your name? \n"; cin >> name;
    struct Characteristics {
        string name;
        int health;
        int damage;
        int agility;
        int xp; //xp when killed
        // special abilities
        bool poisonous;
        bool curse;
        bool stun;
        bool duplication;
        bool doubleTheDamage;
    };
    const int numberOfZombies = 13;
    int enemyIndex = 0;
    while (health > 0) {
        Characteristics zombies[numberOfZombies]{
     {"weak_zombie", 8, 2, 3, 10, false, false, false, false, false},
     {"regular_zombie", 10, 3, 4, 12, false, false, false, false, false},
     {"nimble_zombie", 10, 3, 10, 16, false, false, false, false, false},
     {"fat_zombie", 30, 3, 2, 20, false, false, false, false, false},
     {"very_fat_zombie", 80, 2, 1, 30, false, false, false, false, false},
     {"strong_zombie", 20, 9, 5, 40, false, false, false, false, false},
     {"radioactive_zombie", 70, 8, 5, 60, true, false, false, false, false},
     {"wicked_zombie", 80, 7, 5, 80, false, true, false, false, false},
     {"wicked_radioactive_zombie", 80, 8, 5, 120, true, true, false, false, false},
     {"giant_zombie", 150, 15, 2, 180, false, false, true, false, false},
     {"bizarre_zombie", 50, 50, 50, 200, false, false, false, true, false},
     {"growning_abomination", 150, 8, 10, 250, false, false, false, false, true},
     {"giant_toxic_monster", 300, 30, 5, 400, true, false, true, false, false}
        };
        int poisoningDuration = 0;
        if ((action == "attack") || (action == "a") || (action == "run") || (action == "r")) {
            health = levelUpHealth(level);
            damage = levelUpDamage(level);
            agility = levelUpAgility(level);
            success = false;
            enemyIndex = findTheEnemy(numberOfZombies, level);
            cout << "You stumbled across a ";
            SetConsoleTextAttribute(h, 8);
            cout << zombies[enemyIndex].name;
            SetConsoleTextAttribute(h, 4);
            cout << " HP: " << zombies[enemyIndex].health;
            SetConsoleTextAttribute(h, 1);
            cout << " DMG: " << zombies[enemyIndex].damage;
            SetConsoleTextAttribute(h, 5);
            cout << " AG: " << zombies[enemyIndex].agility << endl;
            SetConsoleTextAttribute(h, 15);
            int healthBeforeFight = health;
            while ((zombies[enemyIndex].health > 0) && (success != true)) {
                if ((health > 0) && (success != true)) {
                    cin >> action;
                    action = to_lower(action);
                    action = checkAction(action);
                    if ((action == "attack") || (action == "a")) {
                        int healthBeforeHit = zombies[enemyIndex].health; //health before the hit
                        zombies[enemyIndex].health = fightZombie(zombies[enemyIndex].health, zombies[enemyIndex].agility, damage);
                        displayInfoAfterAttackOnZombie(healthBeforeHit, zombies[enemyIndex].health, zombies[enemyIndex].name, zombies[enemyIndex].damage, zombies[enemyIndex].agility);
                        if (zombies[enemyIndex].health > 0) {
                            healthBeforeHit = health;
                            zombies[enemyIndex].health = copyHealth(zombies[enemyIndex].duplication, health, zombies[enemyIndex].health, zombies[enemyIndex].name); // only works for duplication == true
                            zombies[enemyIndex].damage = copyDamage(zombies[enemyIndex].duplication, damage, zombies[enemyIndex].damage, zombies[enemyIndex].name); // only works for duplication == true
                            zombies[enemyIndex].agility = copyAgility(zombies[enemyIndex].duplication, agility, zombies[enemyIndex].agility, zombies[enemyIndex].name); // only works for duplication == true
                            //
                            zombies[enemyIndex].damage = doubleTheDamage(zombies[enemyIndex].doubleTheDamage, zombies[enemyIndex].damage, zombies[enemyIndex].name); // only works for doubleTheDamage == true
                            if (poisoningDuration < 1) {
                                poisoningDuration = poisoningDamageDuration(zombies[enemyIndex].poisonous, healthBeforeFight);
                            }
                            if (damage == levelUpDamage(level)) {
                                damage = curseDamage(zombies[enemyIndex].curse, damage);
                            }
                            if (agility == levelUpAgility(level)) {
                                agility = curseAgility(zombies[enemyIndex].curse, agility);
                            }
                            health -= poisoningDamage(poisoningDuration, healthBeforeFight);
                            health = fightHuman(health, agility, zombies[enemyIndex].damage);
                            displayInfoAfterAttackOnPlayer(healthBeforeFight, healthBeforeHit, health, zombies[enemyIndex].name, poisoningDuration);
                            health = stunAttack(zombies[enemyIndex].stun, health, agility, zombies[enemyIndex].damage, zombies[enemyIndex].name);
                            poisoningDuration--;
                        }
                        else {
                            int oldLevel = level;
                            TotalXP += zombies[enemyIndex].xp;
                            level = levelUp(TotalXP);
                            health = levelUpHealth(level);
                            damage = levelUpDamage(level);
                            agility = levelUpAgility(level);
                            SetConsoleTextAttribute(h, 3);
                            cout << "You got " << zombies[enemyIndex].xp << " XP. Your total amount of XP is " << TotalXP << ". Your level is " << level << endl;
                            SetConsoleTextAttribute(h, 15);
                            levelUpNotification(level, oldLevel, health, damage, agility);
                        }
                    }
                    else {
                        Sleep(1100);
                        if ((rand() % 3) == 0) {
                            success = true;
                            SetConsoleTextAttribute(h, 10);
                            cout << "Success!" << endl;
                            SetConsoleTextAttribute(h, 15);
                            if (poisoningDuration >= 1) {
                                health -= poisoningDamage(poisoningDuration, healthBeforeFight);
                                cout << "You are still poisoned! Your health is " << health << endl;
                                SetConsoleTextAttribute(h, 2);
                                cout << "P -" << poisoningDamage(poisoningDuration, healthBeforeFight) << endl;
                                SetConsoleTextAttribute(h, 15);
                                poisoningDuration--;
                            }
                        }
                        else {
                            health = health - (zombies[enemyIndex].damage / 2);
                            zombies[enemyIndex].health = copyHealth(zombies[enemyIndex].duplication, health, zombies[enemyIndex].health, zombies[enemyIndex].name); // only works for duplication == true
                            zombies[enemyIndex].damage = copyDamage(zombies[enemyIndex].duplication, damage, zombies[enemyIndex].damage, zombies[enemyIndex].name); // only works for duplication == true
                            zombies[enemyIndex].agility = copyAgility(zombies[enemyIndex].duplication, agility, zombies[enemyIndex].agility, zombies[enemyIndex].name); // only works for duplication == true
                            //
                            zombies[enemyIndex].damage = doubleTheDamage(zombies[enemyIndex].doubleTheDamage, zombies[enemyIndex].damage, zombies[enemyIndex].name); // only works for doubleTheDamage == true
                            if (poisoningDuration < 1) {
                                poisoningDuration = poisoningDamageDuration(zombies[enemyIndex].poisonous, healthBeforeFight);
                            }
                            if (damage == levelUpDamage(level)) {
                                damage = curseDamage(zombies[enemyIndex].curse, damage);
                            }
                            if (agility == levelUpAgility(level)) {
                                agility = curseAgility(zombies[enemyIndex].curse, agility);
                            }
                            cout << "You was hit while trying to escape! " << "Your health is " << health;
                            SetConsoleTextAttribute(h, 4);
                            cout << "    HIT -" << zombies[enemyIndex].damage / 2 << endl;
                            SetConsoleTextAttribute(h, 15);
                            if (poisoningDuration >= 1) {
                                health -= poisoningDamage(poisoningDuration, healthBeforeFight);
                                cout << "You are still poisoned! Your health is " << health;
                                SetConsoleTextAttribute(h, 2);
                                cout << "    P -" << poisoningDamage(poisoningDuration, healthBeforeFight) << endl;
                                SetConsoleTextAttribute(h, 15);
                                poisoningDuration--;
                            }
                        }
                    }
                }
                if (health <= 0) {
                    system("Color 0C"); //make everything red
                    cout << "You died." << endl;
                    zombies[enemyIndex].health = 0; //to quit the while loop
                }
            }
        }
    }
}
