#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>

class Player: public QObject{
    Q_OBJECT
    int m_x;
    int m_y;

public:
    Player();
    Q_PROPERTY(int x READ getX NOTIFY playerMoved)
    Q_PROPERTY(int y READ getY NOTIFY playerMoved)

    int getX();
    int getY();
    Q_INVOKABLE void setPosition(int newX, int newY);

signals:
    void playerMoved();
};

#endif // PLAYER_H
