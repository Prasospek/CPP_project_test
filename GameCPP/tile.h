#ifndef TILE_H
#define TILE_H


#include <QObject>
#include <QString>
#include <iostream>
#include <QVariant>
#include "config.h"

class Tile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString symbol READ getSymbol CONSTANT)
    Q_PROPERTY(bool isWall READ getIsWall CONSTANT)
    Q_PROPERTY(QString texture READ getTexturePath CONSTANT)


public:
    explicit Tile(QObject *parent = nullptr, QChar symbol = '?', QObject* content = nullptr, bool isWall=false);


    QString getSymbol() const;
    bool getIsWall() const;
    void setIsWall(bool isWall);
    void setContent(QObject* content);
    QObject* getContent();
    void processContent();


private:
    QString m_symbol;
    QString m_TexturePath;
    void setTexturePath();
    QString getTexturePath();
    QObject* m_content;
    bool m_IsWall;


};

#endif // TILE_H
