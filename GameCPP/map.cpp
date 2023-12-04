#include "map.h"

Map::Map(QObject *parent) : QObject(parent)
{

}

Map::Map(std::vector<std::vector<Tile*>> map)
{
    m_map = map;
    selectDisplayedMap(0,0);
}

QVariant Map::getDisplayedTiles() const
{
    return QVariant::fromValue(m_displayedTiles);
}

void Map::selectDisplayedMap(int playerPosX, int playerPosY)
{
    m_displayedTiles = std::vector<Tile*>();
    const int displayedMapSize = 10;
    int cornerMapBlockX = (playerPosX / displayedMapSize) * displayedMapSize;
    int cornerMapBlockY = (playerPosY / displayedMapSize) * displayedMapSize;

    auto rowIt = m_map.begin() + cornerMapBlockY;
    auto rowEnd = rowIt + displayedMapSize;

    for (; rowIt != rowEnd; ++rowIt) {
        auto colmIt = rowIt->begin() + cornerMapBlockX;
        auto colmEnd = colmIt + displayedMapSize;

        for (; colmIt != colmEnd; ++colmIt) {
            m_displayedTiles.push_back(*colmIt);
        }
    }
    emit displayedTilesChanged();
}


