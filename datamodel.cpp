#include "datamodel.h"


DataModel * DataModel::_dataModel = nullptr;
DataModel::DataModel()
{
    numOfEnemies = 10;
    numOfHealthPacks = 10;
}

DataModel *DataModel::getInstance()
{
    if(_dataModel == nullptr)
         _dataModel = new DataModel();

    return  _dataModel;
}



int DataModel::getNumOfHealthPacks() const
{
    return numOfHealthPacks;
}

void DataModel::setNumOfHealthPacks(int value)
{
    numOfHealthPacks = value;
}

int DataModel::getNumOfEnemies() const
{
    return numOfEnemies;
}

void DataModel::setNumOfEnemies(int value)
{
    numOfEnemies = value;
}


void DataModel::setPEnemies(const std::vector<std::shared_ptr<Enemy> > &pEnemies)
{
    _pEnemies = pEnemies;
}


void DataModel::loadGameWorld()
{
    _world = new World();
    renderTiles(WORLD_PIC);
}

std::vector<std::shared_ptr<Enemy> > DataModel::getEnemies() const
{
    return _enemies;
}

void DataModel::setProtagonist()
{
    auto protagonist = _world->getProtagonist();
    _protagonist = std::move(protagonist);
}

void DataModel::setEnemies()
{
    auto enemies = _world->getEnemies(numOfEnemies);
    for(auto & enemy: _enemies)
        _enemies.push_back(std::move(enemy));
}

void DataModel::setHealthPacks()
{
    auto healthPacks = _world->getHealthPacks(numOfHealthPacks);
    for(auto & healthPack: healthPacks)
        _healthPacks.push_back(std::move(healthPack));
}

void DataModel::clearWorld()
{
    _tiles.clear();
    _enemies.clear();
    _healthPacks.clear();
    _protagonist = nullptr;
}

std::shared_ptr<Tile> &DataModel::getTileAt(int xPos, int yPos)
{
    return _tiles.at(_world->getCols() * yPos + xPos);
}

void DataModel::renderTiles(const QString filePath)
{
     auto tiles = _world->createWorld(filePath);
     for(auto & tile: _tiles)
         _tiles.push_back(std::move(tile));
}
void DataModel::setTiles(const std::string &filePath)
{
 // to be implemented
}

