#include <iostream>
#include <locale> // tolower
#include "Header.h"
using namespace std;

int main()
{
    srand(time(NULL));
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
        bool poisonous;
    };
    const int numberOfZombies = 7; 
    int enemyIndex = 0;
    while (health > 0) {
        Characteristics zombies[numberOfZombies]{
     {"weak_zombie", 8, 2, 2, 10},
     {"regular_zombie", 10, 3, 4, 12},
     {"nimble_zombie", 10, 3, 10, 16},
     {"fat_zombie", 30, 3, 2, 20},
     {"very_fat_zombie", 80, 2, 1, 30},
     {"strong_zombie", 20, 10, 5, 40},
     {"radioactive_zombie", 70, 8, 5, 60, true}
        };
        int poisoningDuration = 0;
        if ((action == "attack") || (action == "a") || (action == "run") || (action == "r")) {
            health = levelUpHealth(level);
            success = false;
            enemyIndex = (rand() % (numberOfZombies));
            while (zombies[enemyIndex].damage >= health) { // enemy damage can not be equal to or greater than player's HP
                enemyIndex = (rand() % (numberOfZombies));
            }
            cout << "You stumbled across a " << zombies[enemyIndex].name << " HP: " << zombies[enemyIndex].health << " DMG: " << zombies[enemyIndex].damage << " AG: " << zombies[enemyIndex].agility << endl;
            int healthBeforeFight = health;
            while ((zombies[enemyIndex].health > 0) && (success != true)) {
                if ((health > 0) && (success != true)) {
                    cin >> action;
                    action = to_lower(action);
                    if ((action != "run") && (action != "r")) {
                        int healthBeforeHit = zombies[enemyIndex].health; //health before the hit
                        zombies[enemyIndex].health = fight(zombies[enemyIndex].health, zombies[enemyIndex].agility, damage);
                        displayInfoAfterAttackOnZombie(healthBeforeHit, zombies[enemyIndex].health, zombies[enemyIndex].name, zombies[enemyIndex].damage, zombies[enemyIndex].agility);
                        if (zombies[enemyIndex].health > 0) {
                            healthBeforeHit = health;
                            if (poisoningDuration < 1) {
                                poisoningDuration = poisoningDamageDuration(zombies[enemyIndex].poisonous, healthBeforeFight);
                            }
                            health -= poisoningDamage(poisoningDuration, healthBeforeFight);
                            health = fight(health, agility, zombies[enemyIndex].damage);
                            displayInfoAfterAttackOnPlayer(healthBeforeFight, healthBeforeHit, health, zombies[enemyIndex].name, poisoningDuration);
                            poisoningDuration--;
                        }
                        else {
                            int oldLevel = level;
                            TotalXP += zombies[enemyIndex].xp;
                            level = levelUp(TotalXP);
                            health = levelUpHealth(level);
                            damage = levelUpDamage(level);
                            agility = levelUpAgility(level);
                            cout << "You got " << zombies[enemyIndex].xp << " XP. Your total amount of XP is " << TotalXP << ". Your level is " << level << endl;
                            levelUpNotification(level, oldLevel, health, damage, agility);
                        }
                    }
                    else {
                        if ((rand() % 3) == 0) {
                            success = true;
                            cout << "Success!" << endl;
                            if (poisoningDuration >= 1) {
                                health -= poisoningDamage(poisoningDuration, healthBeforeFight);
                                poisoningDuration--;
                                cout << "You are still poisoned! P  -" << poisoningDamage(poisoningDuration, healthBeforeFight) << " Your health is " << health << endl;
                            }
                        }
                        else {
                            health = health - (zombies[enemyIndex].damage / 2);
                            cout << "You was hit while trying to escape! HIT -" << zombies[enemyIndex].damage / 2 << " Your health is " << health << endl;
                            if (poisoningDuration >= 1) {
                                health -= poisoningDamage(poisoningDuration, healthBeforeFight);
                                poisoningDuration--;
                                cout << "You are still poisoned! P -" << poisoningDamage(poisoningDuration, healthBeforeFight) << " Your health is " << health << endl;
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
