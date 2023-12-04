#include "config.h"


Config::Config()
{
    loadConfig();
    setWallChars();
    setEnemyChars();
}

std::vector<QChar> Config::getWallChars()
{
    return m_wallChars;
}

std::vector<QChar> Config::getEnemyChars()
{
    return m_enemyChars;
}

void Config::setWallChars()
{
    std::vector<QChar> walls;
    QJsonArray wallsArray = m_config["walls"].toArray();

    for (auto it = wallsArray.begin(); it != wallsArray.end(); ++it) {
        walls.push_back((*it).toString().at(0));
    }

    m_wallChars = walls;
}

void Config::setEnemyChars()
{
    std::vector<QChar> enemies;
    QJsonObject enemiesObject = m_config["enemies"].toObject();
    for (auto it = enemiesObject.begin(); it != enemiesObject.end(); ++it) {
        QJsonObject enemy = it.value().toObject();
        enemies.push_back(it.key().at(0));
    }
    m_enemyChars = enemies;
}

void Config::loadConfig()
{
    QFile file(qApp->applicationDirPath() + "/../GameCPP/config.json"); //TODO: find a better way to load the config file.
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //TODO: handle file opening error
    }
    auto content = file.readAll();
    QJsonParseError json_error;
    QJsonDocument json_doc = QJsonDocument::fromJson(content, &json_error);
    if (!json_doc.isNull() && (json_error.error == QJsonParseError::ParseError::NoError) &&
        json_doc.isObject()) {
        m_config = json_doc.object();
    }
    else{
        //TODO: handle parsing error
    }
}

bool Config::isWall(QChar symbol)
{
    bool isWall;
    auto walls = getWallChars();
    auto wallFind = std::find(walls.begin(), walls.end(), symbol);
    return (wallFind != walls.end()) ? true : false; // if symbol is found in vector of wall characters, return true
}

