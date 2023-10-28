#include <iostream>
#include <locale> // tolower
#include "Header.h"
using namespace std;

int main()
{
    srand(time(NULL));
    string name; //name of the user
    int health = 10;
    int damage = 2;
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
    };
    const int numberOfZombies = 6; //zero based
    int enemyIndex = 0;
    while (health > 0) {
        Characteristics zombies[numberOfZombies]{
     {"weak_zombie", 8, 1, 1, 10},
     {"regular_zombie", 10, 2, 1, 12},
     {"nimble_zombie", 10, 2, 10, 16},
     {"fat_zombie", 30, 2, 0, 20},
     {"very_fat_zombie", 80, 2, 0, 30},
     {"strong_zombie", 20, 10, 5, 40},
        };
        if ((action == "attack") || (action == "a") || (action == "run") || (action == "r")) {
            health = levelUpHealth(level);
            success = false;
            enemyIndex = (rand() % (numberOfZombies));
            while (zombies[enemyIndex].damage >= health) { // enemy damage can not be equal to or greater than player's HP
                enemyIndex = (rand() % (numberOfZombies));
            }
            cout << "You stumbled across a " << zombies[enemyIndex].name << " HP: " << zombies[enemyIndex].health << " DMG: " << zombies[enemyIndex].damage << " AG: " << zombies[enemyIndex].agility << endl;
            while ((zombies[enemyIndex].health > 0) && (success != true)) {
                if ((health > 0) && (success != true)) {
                    cin >> action;
                    action = to_lower(action);
                    if ((action != "run") && (action != "r")) {
                        zombies[enemyIndex].health = fight(zombies[enemyIndex].health, zombies[enemyIndex].agility, damage);
                        cout << "Name: " << zombies[enemyIndex].name << " HP: " << zombies[enemyIndex].health << " DMG: " << zombies[enemyIndex].damage << " AG: " << zombies[enemyIndex].agility << endl;
                        if (zombies[enemyIndex].health > 0) {
                            health = fight(health, agility, zombies[enemyIndex].damage);
                            cout << zombies[enemyIndex].name << " attacks you! Your HP is " << health << endl;
                        }
                        else {
                            TotalXP += zombies[enemyIndex].xp;
                            level = levelUp(TotalXP);
                            health = levelUpHealth(level);
                            damage = levelUpDamage(level);
                            agility = levelUpAgility(level);
                            cout << "You got " << zombies[enemyIndex].xp << " XP. Your total amount of XP is " << TotalXP << ". Your level is " << level << endl;
                        }
                    } 
                    else {
                        if ((rand() % 3) == 0) {
                            success = true;
                            cout << "Success!" << endl;
                        }
                        else {
                            health = health - (zombies[enemyIndex].damage/2);
                            cout << "You was hit! Your health is " << health << endl;
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
