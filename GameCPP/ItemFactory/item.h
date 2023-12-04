#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QMetaType>
#include "tile.h"

enum ItemType {
    healthPotion,
    damagePotion,
    sword,
    helmet
};

class Item : public Tile
{
    Q_OBJECT

private:
    int m_health;
    int m_damage;

//factory
public:
    static Item* getItem(ItemType type);

protected:
    Item(int health, int damage);
    virtual ~Item();

public slots:
    virtual void process(); //picks item in inventory override
};


#endif // ITEM_H
