// enemy.cpp
#include "enemy.h"

Enemy* Enemy::getEnemy() {
    return new Enemy();
}

void Enemy::process() {
    // Implementation for starting a fight
    qDebug() << "Enemy is starting a fight!";
    // Add your specific implementation here
}
