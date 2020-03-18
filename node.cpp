#include "node.h"


Node::Node(std::shared_ptr<Tile> aTile): tile{aTile}, parent{nullptr}, hCost {std::numeric_limits<double>::max()}, gCost{0}
{
    std::cout << " Ctor Node with 1 para called. " << std::endl;
}


Node::~Node(){
    std::cout << "Dtor Node called. " << std::endl;
}


Node::Node(std::shared_ptr<Tile> aTile, std::shared_ptr<Node> aParent, double anHCost, double aGCost):
    tile{aTile}, parent{aParent}, hCost {anHCost}, gCost{aGCost}
{
    fCost = hCost + gCost;
    std::cout << " Ctor Node with 4 para called. " << std::endl;
}

void Node::computeHCost(std::shared_ptr<Tile> &goal)
{
    hCost = std::sqrt( (goal->getXPos() - tile->getXPos()) *
                       (goal->getXPos() - tile->getXPos()) +
                       (goal->getYPos() - tile->getYPos()) *
                       (goal->getYPos() - tile->getYPos()) );
}

