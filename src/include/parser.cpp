#include "parser.h"

bool get_command(UserCommand &user_command, int &x, int &y, std::istream &stream = std::cin)
{
  using namespace minesweeper;
  // TODO: make this function safe

  std::string c;
  do
  {
    c = "";
    stream >> c;
    std::transform(c.begin(), c.end(), c.begin(), tolower);
  } while (commands.find(c) == commands.end());

  user_command = static_cast<UserCommand>(commands.at(c));

  std::cout << "Row: ";
  stream >> y;

  std::cout << "Column: ";
  stream >> x;

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