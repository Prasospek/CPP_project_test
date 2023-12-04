#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QMetaType>
#include "tile.h"

enum EnemyType {
    dragon,
    skeleton,
    knight
};

class Enemy : public Tile
{
    Q_OBJECT

private:
    int m_health;
    int m_damage;

public:
    static Enemy* getEnemy(EnemyType type); // factory

protected:
    Enemy(int health, int damage);
    virtual ~Enemy();



public slots:
    virtual void process(); //starts fight override
};
#endif // ENEMY_H
