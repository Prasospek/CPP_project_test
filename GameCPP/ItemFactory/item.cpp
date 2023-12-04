// item.cpp
#include "item.h"

Item* Item::getItem() {
    return new Item();
}

void Item::process() {
    // Implementation for picking the item in the inventory
    qDebug() << "Item picked in the inventory.";
    // Add your specific implementation here
}

Item::~Item()
{
    // zzz
}
