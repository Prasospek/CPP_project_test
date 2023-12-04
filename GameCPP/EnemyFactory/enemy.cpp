// enemy.cpp
#include "enemy.h"
#include "enemySkeleton.h"
#include "enemyDragon.h"
#include "enemyKnight.h"

Enemy::Enemy(int health, int damage) : m_health(health), m_damage(damage) {}

void Enemy::process() {
    // Implementation for starting a fight
    qDebug() << "Enemy is starting a fight!";
    // Add your specific implementation here
}

Enemy* Enemy::getEnemy(EnemyType type)
{
    switch (type) {
    case dragon:
        return new EnemyDragon();
    case skeleton:
        return new EnemySkeleton();
    case knight:
        return new EnemyKnight();
    default:
        return nullptr; // or throw an exception for an unknown enemy type
    }
}


Enemy::~Enemy()
{
    qDebug() << "Enemy destructor called.";
}
