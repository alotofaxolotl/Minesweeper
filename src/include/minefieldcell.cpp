#include "minefieldcell.h"

MinefieldCell::MinefieldCell()
{
  mine = static_cast<float>(rand()) / RAND_MAX <= minesweeper::MINE_CHANCE;
}