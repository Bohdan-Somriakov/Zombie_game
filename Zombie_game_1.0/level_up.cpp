#include <string>
using namespace std;
struct Player {
    int xp;
    int health;
    int damage;
    int agility;
};
Player levels[10]{
    {0, 10, 2, 1},
    {10, 15, 3, 2},
    {20, 20, 6, 4},
    {80, 40, 10, 8},
    {200, 65, 16, 12},
    {500, 90, 24, 16},
    {1000, 120, 30, 22},
    {2000, 150, 42, 34},
    {5000, 170, 58, 42},
    {10000, 200, 70, 50},
};
int levelUp(int xp) {
    int level = 0;
    for (int i = 0; i < 10; i++) {
        if ((xp >= levels[i].xp) && (xp < levels[i+1].xp)) {
            level = i;
        }
    }
    return level;
}
int levelUpHealth(int level) {
    int health = 10;
    for (int i = 0; i < 9; i++) {
        if (level == (i)) {
            health = levels[i].health;
        }
    }
    return health;
}
int levelUpDamage(int level) {
    int damage = 2;
    for (int i = 0; i < 9; i++) {
        if (level == (i)) {
            damage = levels[i].damage;
        }
    }
    return damage;
}
int levelUpAgility(int level) {
    int agility = 1;
    for (int i = 0; i < 9; i++) {
        if (level == (i)) {
            agility = levels[i].agility;
        }
    }
    return agility;
}