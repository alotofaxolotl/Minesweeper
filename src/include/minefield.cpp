#include "minefield.h"

Minefield::Minefield(int width, int height)
{
  srand(time(NULL));

  Minefield::width = width;
  Minefield::height = height;

  for (int h = 0; h < height; h++)
    cells.push_back(std::vector<MinefieldCell>(width));
}

bool Minefield::flag_position(int x, int y)
{
  if (!is_valid_position(x, y))
    return false;

  cells[y][x].flag = !cells[y][x].flag;
  return true;
}

bool Minefield::clear_position(int x, int y)
{
  if (!is_valid_position(x, y))
    return false;

  if (cells[y][x].flag)
    return false;

  if (cells[y][x].revealed)
    return false;

  if (cells[y][x].mine)
  {
    detonate();
    return true;
  }

  cells[y][x].revealed = true;
  if (adjacent_mines(x, y) == 0)
  {
    clear_position(x - 1, y);
    clear_position(x + 1, y);
    clear_position(x, y - 1);
    clear_position(x, y + 1);
  }

  won = check_for_win();
  return true;
}

void Minefield::draw()
{
  int column, row;
  for (column = 0; column < height; column++)
  {
    for (row = 0; row < width; row++)
    {
      std::cout << cell_character(row, column) << "  ";
    }
    std::cout << "  " << column + 1 << "\n";
  }

  std::cout << "\n";
  std::string row_number;
  for (row = 0; row < width; row++)
  {
    row_number = std::to_string(row + 1);
    while (row_number.size() < 3)
      row_number += ' ';
    std::cout << row_number;
  }
  std::cout << "\n\n";
}

bool Minefield::is_valid_position(int &x, int &y)
{

  if (std::min(x, 0) < 0 || std::max(x, width - 1) >= width)
    return false;

  if (std::min(y, 0) < 0 || std::max(y, height - 1) >= height)
    return false;

  return true;
}

int Minefield::adjacent_mines(int &x, int &y)
{
  int h, w;
  int mines = 0;
  for (h = y - 1; h <= y + 1; h++)
  {
    if (h < 0 || h >= height)
      continue;
    for (w = x - 1; w <= x + 1; w++)
    {
      if (w < 0 || w >= width)
        continue;

      mines += cells[h][w].mine;
    }
  }

  return mines;
}

void Minefield::detonate()
{
  for (std::vector<MinefieldCell> &row : cells)
  {
    for (MinefieldCell &cell : row)
    {
      cell.flag = false;
      cell.revealed = true;
    }
  }

  game_over = true;
}

char Minefield::cell_character(int &x, int &y)
{
  MinefieldCell cell = cells[y][x];
  if (cell.flag)
    return '!';
  if (!cell.revealed)
    return '.';
  if (cell.mine)
    return '*';

  int mines = adjacent_mines(x, y);
  if (mines == 0)
    return ' ';

  return '0' + mines;
}

bool Minefield::check_for_win()
{
  for (auto &row : cells)
  {
    for (auto &cell : row)
    {
      if (!cell.revealed && !cell.mine)
        return false;
    }
  }
  return true;
}