#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <vector>
#include <QVariant>

#include "tile.h"

class Map: public QObject {
    Q_OBJECT
    Q_PROPERTY(QVariant tiles READ getDisplayedTiles NOTIFY displayedTilesChanged) //in future will not be a constant

private:
    std::vector<std::vector<Tile*>> m_map;
    std::vector<Tile*> m_displayedTiles;

public:
    Map(QObject *parent = nullptr);
    Map(std::vector<std::vector<Tile*>> map);
    QVariant getDisplayedTiles() const;
    void selectDisplayedMap(int playerPosX, int playerPosY);

signals:
    void displayedTilesChanged();


};

#endif // MAP_H
