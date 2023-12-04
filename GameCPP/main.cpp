#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "game.h"
#include "player.h"
#include "mapgenerator.h"
#include "map.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MapGenerator* mapGenerator = new MapGenerator();
    Map map(mapGenerator->getMap()); //TO DO unique pointer or smt like that
    delete mapGenerator;
    Game game;
    Player player;
    QObject::connect(&player, &Player::playerMoved, &app, [&map, &player]() {
        map.selectDisplayedMap(player.getX(), player.getY()); //lambda function that changes displayed map when player moves
    });
    engine.rootContext()->setContextProperty("maper", &map);
    engine.rootContext()->setContextProperty("game", &game);
    engine.rootContext()->setContextProperty("player", &player);
    const QUrl url(QStringLiteral("qrc:/GameCPP/Main.qml"));
    engine.load(url);

    return app.exec();
}
