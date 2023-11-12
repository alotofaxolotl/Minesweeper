#ifndef MINEFIELD_H_
#define MINEFIELD_H_

#include "minefieldcell.h"

#include <iostream>
#include <vector>

struct Minefield
{
  bool game_over = false;

  Minefield(int, int);

  bool flag_position(int, int);
  bool clear_position(int, int);
  void draw();

private:
  int width;
  int height;
  std::vector<std::vector<MinefieldCell>> cells;
  bool is_valid_position(int &, int &);
  int adjacent_mines(int &, int &);
  void detonate();
  char cell_character(int &, int &);
};

#endif