#ifndef NODE_H
#define NODE_H

#include <memory>
#include <iostream>
#include <cmath>

#include "world.h"

class Node
{
public:
  Node(std::shared_ptr<Tile> aTile = nullptr);

  Node(std::shared_ptr<Tile> aTile, std::shared_ptr<Node> aParent, double anHCost, double aGCost);
  ~Node();

  std::shared_ptr<Tile> tile;
  std::shared_ptr<Node> parent;
  double hCost, gCost,  fCost;



  int operator < (const std::shared_ptr<Node> right)
  {
    if(fCost < right->fCost)
      {
        return -1;
      }
    else if (fCost > right->fCost) {
        return 1;
      }else{
        return 0;
      }
  }

  void computeHCost(std::shared_ptr<Tile> &goal);
};

#endif // NODE_H
