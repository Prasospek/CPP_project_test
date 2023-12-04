#ifndef TILECONTENT_H
#define TILECONTENT_H
#include <QObject>

class TileContent: public QObject{
public:
    virtual void process() = 0;
};



#endif // TILECONTENT_H
