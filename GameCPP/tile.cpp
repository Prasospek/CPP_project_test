#include "tile.h"


Tile::Tile(QObject *parent, QChar symbol, QObject* content, bool isWall)
    : QObject(parent), m_symbol(symbol), m_content(content), m_IsWall(isWall)
{
    setTexturePath();
}

QString Tile::getSymbol() const {
    return m_symbol;
}

bool Tile::getIsWall() const
{
    return m_IsWall;
}
void Tile::setIsWall(bool isWall)
{
    m_IsWall = isWall;
}

void Tile::setTexturePath()
{
    switch (m_symbol.at(0).toLatin1()) { //QChar to char
    case '#':
        m_TexturePath = "images/background/water.png";
        break;
    case '.':
        m_TexturePath = "images/background/grass.png";
        break;

    case 'H':
        m_TexturePath = "images/background/rocks.png";
        break;

    case 'S':
        m_TexturePath = "images/background/sand.png";
        break;

    case 'P':
        m_TexturePath = "images/background/path.png";
        break;
    }
}

QString Tile::getTexturePath()
{
    return m_TexturePath;
}

void Tile::setContent(QObject* content)
{
    m_content = content;
}

QObject* Tile::getContent()
{
    return m_content;
}

void Tile::processContent()
{
    if (m_content) { //if content exists
        QMetaObject::invokeMethod(m_content, "process"); //call .process() of content
    }
}
