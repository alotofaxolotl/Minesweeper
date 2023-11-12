#include <iostream>
#include <random>
#include <map>

#include "include/minefield.h"
#include "include/minefieldcell.h"
#include "include/parser.h"
#include "include/lang.h"

int main()
{
  using namespace minesweeper;

  int width, height;
  get_dimensions(width, height, std::cin, std::cout);

  Minefield minefield(width, height);
  UserCommand user_command;
  int x, y;

  while (!minefield.game_over)
  {

    minefield.draw();

    if (!get_command(user_command, x, y, std::cin))
      std::cout << feedback.at("bad command");

    x -= 1;
    y -= 1;

    if (user_command == UserCommand::CLEAR)
      if (!minefield.clear_position(x, y))
        std::cout << feedback.at("bad move");

    if (user_command == UserCommand::FLAG)
      if (!minefield.flag_position(x, y))
        std::cout << feedback.at("bad move");

    if (minefield.won)
    {
      std::cout << feedback.at("win");
      break;
    }
  }

  if (!minefield.won)
  {
    std::cout << feedback.at("lose");
  }
  minefield.draw();

  return 0;
}