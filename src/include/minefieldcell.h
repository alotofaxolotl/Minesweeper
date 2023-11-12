#ifndef MINEFIELDCELL_H_
#define MINEFIELDCELL_H_

#include <random>

namespace minesweeper
{
  const float MINE_CHANCE = 0.1f;
};

// TODO: move functionality to .cpp file

struct MinefieldCell
{
  bool mine = false;
  bool flag = false;
  bool revealed = false;

  MinefieldCell();
};

MinefieldCell::MinefieldCell()
{
  mine = static_cast<float>(rand()) / RAND_MAX <= minesweeper::MINE_CHANCE;
}

#endif