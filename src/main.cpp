#include <iostream>
#include <random>

#include "include/minefield.h"
#include "include/minefieldcell.h"
#include "include/parser.h"

void initialize()
{
  srand(time(NULL));
}

int main()
{
  initialize();

  // TODO: this should be handled by a dedicated function
  // consider moving to UserInput

  int width, height;
  std::cout << "Enter a width and a height!\n";

  std::cin >> width;
  std::cin >> height;

  Minefield minefield(width, height);
  UserCommand user_command;
  int x, y;

  while (!minefield.game_over)
  {

    minefield.draw();

    // TODO: input validation should be done inside parse()
    while (!get_command(user_command, x, y))
      std::cout << "That's not a valid command!\n";

    x -= 1;
    y -= 1;

    if (user_command == UserCommand::CLEAR)
    {
      minefield.clear_position(x, y);
      continue;
    }

    if (user_command == UserCommand::FLAG)
      minefield.flag_position(x, y);

    // TODO: there should be some feedback if the input coord isn't valid
    // eg: "That cell is out of bounds!"

    // TODO: check for a win! let the user know they won
  }

  minefield.draw();

  return 0;
}