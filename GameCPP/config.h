#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include "qguiapplication.h" // to get project folder, so we can read config :/

class Config: public QObject
{
    Q_OBJECT
public:
    Config();
    std::vector<QChar> getWallChars();
    std::vector<QChar> getEnemyChars();
    void setWallChars();
    void setEnemyChars();
    void loadConfig();

    bool isWall(QChar symbol);


private:
    std::vector<QChar> m_wallChars;
    std::vector<QChar> m_enemyChars;
    QJsonObject m_config;

};

#endif // CONFIG_H
