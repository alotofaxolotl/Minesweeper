#include "parser.h"

bool get_command(UserCommand &user_command, int &x, int &y, std::istream &stream = std::cin)
{
  // TODO: make this function safe

  std::string c;
  stream >> c;
  std::transform(c.begin(), c.end(), c.begin(), tolower);

  if (minesweeper::commands.find(c) == minesweeper::commands.end())
    return false;

  user_command = static_cast<UserCommand>(minesweeper::commands.at(c));

  // maybe swap the order of these? row -> col feels more intuitive
  // TODO: make it clear to the user what cell they are targeting

  stream >> x;
  stream >> y;

  return true;
}

bool get_dimensions(int &x, int &y, std::istream &stream = std::cin)
{

  // TODO: add validation for x and y (eg negatives)
  // TODO: make this safe

  std::cout << "Width: ";
  stream >> x;

  std::cout << "Height: ";
  stream >> y;

  return true;
}