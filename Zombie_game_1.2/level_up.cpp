#include <string>
#include <iostream>
//#include <cstdlib>
//#include <ctime>
using namespace std;
struct Player {
    int xp;
    int health;
    int damage;
    int agility;
};
Player levels[11]{
    {0, 10, 3, 1},  
    {10, 20, 4, 2},
    {20, 30, 6, 4},
    {40, 40, 10, 8},
    {80, 60, 16, 12},
    {160, 90, 24, 16},
    {320, 120, 30, 22},
    {640, 150, 42, 34},
    {1280, 190, 58, 40},
    {2560, 250, 70, 44},
    {5120, 300, 100, 50}
};
int levelUp(int xp) {
    int level = 0;
    for (int i = 0; i <= 10; i++) {
        if ((xp >= levels[i].xp) && (xp < levels[i + 1].xp)) {
            level = i;
        }
    }
    if (xp >= 5120) {
        level = 10; //maxLevel
    }
    return level;
}
int levelUpHealth(int level) {
    int health = 10;
    for (int i = 0; i <= 10; i++) {
        if (level == (i)) {
            health = levels[i].health;
        }
    }
    return health;
}
int levelUpDamage(int level) {
    int damage = 2;
    for (int i = 0; i <= 10; i++) {
        if (level == (i)) {
            damage = levels[i].damage;
        }
    }
    return damage;
}
int levelUpAgility(int level) {
    int agility = 1;
    for (int i = 0; i <= 10; i++) {
        if (level == (i)) {
            agility = levels[i].agility;
        }
    }
    return agility;
}
void levelUpNotification(int level, int oldLevel, int HP, int DMG, int AG) {
    if (level > oldLevel) {
        cout << "LEVEL UP. Your new level is " << level << ". Your new stats: HP " << HP << " DMG " << DMG << " AG " << AG << endl;
    }
}