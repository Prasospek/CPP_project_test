#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QMetaType>
#include "tile.h"

class Item : public Tile
{
    Q_OBJECT
public:
    static Item* getItem();

protected:
    Item(){};
    virtual ~Item();

public slots:
    virtual void process(); //picks item in inventory override
};


#endif // ITEM_H
