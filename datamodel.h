#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <iostream>
#include <memory>
#include <vector>

#include "node.h"
#include "world.h"

#define WORLD_PIC ":/imgs/gameimgs/worldmap20x20.png"

class DataModel
{
public:

    DataModel();
    //Declare a public static creation method for getting the singleton instance.
    static DataModel * getInstance();

    World *getWorld() const;
    void setWorld(World *value);

    int getNumOfHealthPacks() const;
    void setNumOfHealthPacks(int value);

    int getNumOfEnemies() const;
    void setNumOfEnemies(int value);

    std::shared_ptr<Protagonist> getProtagonist() const;
    void setProtagonist();

    std::vector<std::shared_ptr<Enemy> > getEnemies() const;
    void setEnemies();

    std::vector<std::shared_ptr<Enemy> > getPEnemies() const;
    void setPEnemies(const std::vector<std::shared_ptr<Enemy> > &pEnemies);

    std::vector<std::shared_ptr<Tile> > getHealthPacks() const;
    void setHealthPacks();

    std::vector<std::shared_ptr<Tile> > getTiles() const;
    void setTiles(const std::string &filePath);

    void loadGameWorld();
    void clearWorld();
    // Getting a particular tile
    std::shared_ptr<Tile> & getTileAt(int xPos, int yPos);
    void renderTiles(const QString filePath);
    std::vector<std::unique_ptr<Tile>> createWorld(QString filename);

private:

    std::shared_ptr<Protagonist> _protagonist;
    std::vector<std::shared_ptr<Enemy> > _enemies;
    std::vector<std::shared_ptr<Enemy> > _pEnemies;
    std::vector<std::shared_ptr<Tile> > _healthPacks;
    std::vector<std::shared_ptr<Tile> > _tiles;

    int numOfHealthPacks;
    int numOfEnemies;
    // Add a private static field to the class for storing the singleton instance.
    static DataModel * _dataModel;
    World*  _world;
};

#endif // DATAMODEL_H
