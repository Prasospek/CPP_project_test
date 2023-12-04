#ifndef GAME_H
#define GAME_H
#include <QObject>
#include "mapgenerator.h"

class Game: public QObject {
    Q_OBJECT

private:
    MapGenerator* m_mapGenerator;

public:
    Game();
};

#endif // GAME_H
