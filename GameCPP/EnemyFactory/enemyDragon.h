#ifndef ENEMYDRAGON_H
#define ENEMYDRAGON_H

#include "enemy.h"

class EnemyDragon : public Enemy
{
       Q_OBJECT
public:
       EnemyDragon(int health, int damage);
};

#endif // ENEMYDRAGON_H
