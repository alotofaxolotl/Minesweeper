#ifndef MINEFIELDCELL_H_
#define MINEFIELDCELL_H_

#include <random>

namespace minesweeper
{
  const float MINE_CHANCE = 0.1f;
};

struct MinefieldCell
{
  bool mine = false;
  bool flag = false;
  bool revealed = false;

  MinefieldCell();
};

#endif