#ifndef DATAVISUALIZATION_H
#define DATAVISUALIZATION_H

#include <iostream>
#include <memory>
#include <vector>

#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "datamodel.h"

class DataVisualization : public QGraphicsView
{
public:
    explicit DataVisualization(QWidget *parent);

    void initGameWorld();


    void setProtagonistPic(const QString& protagonistPic);
    void setEnemyPic(const QString& enemyPic);
    void setHealthPackPic(const QString& healthPackPic);
    void setDefetedEnemyPic(const QString& defetedEnemyPic);

    void setWorldPic(const QString &worldPic);

private:
    std::shared_ptr<QPixmap> _worldPic;

    std::shared_ptr<QPixmap> _protagonistPic;
    std::shared_ptr<QPixmap> _enemyPic;
    std::shared_ptr<QPixmap> _healthPackPic;
    std::shared_ptr<QPixmap> _defetedEnemyPic;
    //-------------------------------------------//
    QGraphicsPixmapItem * _protagonist;
    QGraphicsPixmapItem * _world;
    //-------------------------------------------//
    std::vector<QGraphicsPixmapItem *> _enemies;
    std::vector<QGraphicsPixmapItem *> _healthPacks;

    DataModel * _model;
};

#endif // DATAVISUALIZATION_H
