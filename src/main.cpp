#include <iostream>
#include <random>
#include <map>

#include "include/minefield.h"
#include "include/minefieldcell.h"
#include "include/parser.h"

// could this be moved to the Minefield constructor?
void initialize()
{
  srand(time(NULL));
}

const std::map<std::string, std::string> feedback = {
    {"bad move", "Sorry, you can't do that.\n\n"},
    {"win", "Congrats! You won!\n\n"},
    {"lose", "Better luck next time!\n\n"}};

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
      if (!minefield.clear_position(x, y))
        std::cout << feedback.at("bad move");

    if (user_command == UserCommand::FLAG)
      if (!minefield.flag_position(x, y))
        std::cout << feedback.at("bad move");

    // TODO: there should be some feedback if the input coord isn't valid
    // eg: "That cell is out of bounds!"

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