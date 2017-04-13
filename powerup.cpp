#include "powerup.h"
//#include <QGlobal.h>
#include <QtGlobal>
#include <QTime>
#include <QDebug>
#include <QTimer>

PowerUp::PowerUp(QGraphicsItem *parent)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    //setting random coordinates for new power up
    int width = 600;
    int height = 400;

    int NX = width / 20;
    int NY = height / 20;

    int _rx = qrand() % (NX + 1) * 20;
    int _ry = qrand() % (NY + 1) * 20;

    restX = _rx;
    restY = _ry;


    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg1.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg2.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg3.png"));
    powerUpImageList.append(new QPixmap(":/images/resourses/images/glowing_green/gg4.png"));

    connect(pixMapTimer, SIGNAL(timeout()), this, SLOT(animationCounter()));
    pixMapTimer->start(250);


    powerUpPixMap = powerUpImageList[0];
    setPixmap(*powerUpPixMap);
    setPos(restX,restY);

}

bool PowerUp::getConsumed() const
{
    return consumed;
}

void PowerUp::setConsumed(bool value)
{
    consumed = value;
}

int PowerUp::getX()
{
    return restX;
}

int PowerUp::getY()
{
    return restY;
}

void PowerUp::animationCounter()
{

    if(animCounter>=3) increment = -1;
    if(animCounter ==0) increment = 1;
    qDebug()<<animCounter<<"is current counter";
    animCounter+=increment;
    powerUpPixMap = powerUpImageList[animCounter];
    setPixmap(*powerUpPixMap);
}


