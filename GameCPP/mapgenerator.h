#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H


#include <QObject>
#include <vector>
#include <iostream>
#include <QVariant>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "config.h"

#include "tile.h"

class MapGenerator: public QObject
{
    Q_OBJECT

private:
    QString m_filePath = "GameCPP/mapFile.txt";
    std::vector<std::vector<Tile*>> m_map;

public:
    MapGenerator(QObject *parent = nullptr);
    std::vector<std::vector<Tile*>> getMap();

private:
    std::vector<std::vector<QChar>> loadMapFromFile();
    void createMap();

};

#endif // MAPGENERATOR_H
