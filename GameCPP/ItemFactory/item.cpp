// item.cpp
#include "item.h"
#include "damagepotion.h"
#include "healthpotion.h"
#include "platehelmet.h"
#include "sword.h"


Item::Item(int health, int damage) : m_health(health), m_damage(damage) {}


Item* Item::getItem(ItemType type) {
    switch (type) {
    case damagePotion:
        return new DamagePotion();
    case healthPotion:
        return new HealthPotion();
    case helmet:
        return new PlateHelmet();
    case sword:
        return new Sword();
    default:
        return nullptr; // or throw an exception for an unknown enemy type
    }
}

void Item::process() {
    // Implementation for picking the item in the inventory
    qDebug() << "Item picked in the inventory.";
    // Add your specific implementation here
}

Item::~Item()
{
    qDebug() << "Item destructor called.";
}
