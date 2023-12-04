#include "mapgenerator.h"

MapGenerator::MapGenerator(QObject *parent) : QObject(parent)
{
    createMap();
}

std::vector<std::vector<QChar>> MapGenerator::loadMapFromFile()
{
    QFile file(m_filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        std::vector<std::vector<QChar>> map;
        QString readRow;

        while (!(readRow = in.readLine()).isNull())
        {
            std::vector<QChar> row;
            for (QChar &character : readRow)
            {
                row.push_back(character);
            }
            map.push_back(row);
        }

        file.close();

        return map;
    }
    else{
        // Handle file open error
        return std::vector<std::vector<QChar>>();
    }
}


void MapGenerator::createMap()
{
    auto fff = loadMapFromFile();
    Config conf;

    for(auto it = fff.begin(); it != fff.end(); ++it){
        std::vector<Tile*> row;
        for(auto ti = it->begin(); ti != it->end(); ++ti){
            QChar symbol = *ti;
            bool isWall = conf.isWall(symbol);
            row.push_back(new Tile(nullptr, symbol, nullptr,isWall)); //TODO: set content based on symbol(enemy/item...).
            //To set content: Enemy* enemy = new Enemy(); row.push_back(new Tile(nullptr, symbol, enemy, false));*/
        }
        m_map.push_back(row);
    }
}

std::vector<std::vector<Tile*>> MapGenerator::getMap(){
    return m_map;
}




