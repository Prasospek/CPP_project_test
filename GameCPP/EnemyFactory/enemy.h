#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QMetaType>
#include "tile.h"

class Enemy : public Tile
{
    Q_OBJECT
public:
    static Enemy* getEnemy(); //factory method

protected:
    Enemy(){};
    virtual ~Enemy();

public slots:
    virtual void process(); //starts fight override
};
#endif // ENEMY_H
