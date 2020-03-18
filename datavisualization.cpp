#include "datavisualization.h"

DataVisualization::DataVisualization(QWidget *parent)
{

}

void DataVisualization::initGameWorld()
{// _model->loadGameWorld();
    _world  = new QGraphicsPixmapItem();
    setWorldPic(WORLD_PIC);
    _world->setPixmap(*_worldPic);
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(_world);

}




void DataVisualization::setProtagonistPic(const QString& protagonistPic)
{

}

void DataVisualization::setEnemyPic(const QString& enemyPic)
{

}

void DataVisualization::setHealthPackPic(const QString &healthPackPic)
{

}

void DataVisualization::setDefetedEnemyPic(const QString& defetedEnemyPic)
{

}

void DataVisualization::setWorldPic(const QString &worldPic)
{
    _worldPic = std::make_shared<QPixmap>(worldPic);

}


