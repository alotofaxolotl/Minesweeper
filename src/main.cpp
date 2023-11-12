#include <iostream>
#include <random>

#include "include/minefield.h"
#include "include/minefieldcell.h"
#include "include/parser.h"

// could this be moved to the Minefield constructor?
void initialize()
{
  srand(time(NULL));
}

int main()
{
  initialize();

  int width, height;
  get_dimensions(width, height, std::cin);

  Minefield minefield(width, height);
  UserCommand user_command;
  int x, y;

  while (!minefield.game_over)
  {

    minefield.draw();

    // TODO: input validation should be done inside parse()
    while (!get_command(user_command, x, y, std::cin))
      std::cout << "That's not a valid command!\n";

    x -= 1;
    y -= 1;

    if (user_command == UserCommand::CLEAR)
    {
      minefield.clear_position(x, y);
    }

    if (user_command == UserCommand::FLAG)
      minefield.flag_position(x, y);

    // TODO: there should be some feedback if the input coord isn't valid
    // eg: "That cell is out of bounds!"

    if (minefield.won)
    {
      std::cout << "Congrats! You won!\n\n";
      break;
    }
  }

  if (!minefield.won)
  {
    std::cout << "Better luck next time!\n\n";
  }
  minefield.draw();

  return 0;
}