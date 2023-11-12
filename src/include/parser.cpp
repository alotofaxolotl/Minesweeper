#include "parser.h"

void get_integer(int &n, std::istream &stream)
{
  auto is_number = [](std::string s)
  {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](auto c)
                                      { return !std::isdigit(c); }) == s.end();
  };

  std::string raw_input;
  do
  {
    raw_input = "";
    stream >> raw_input;
  } while (!is_number(raw_input));

  n = std::stoi(raw_input);
}

bool get_command(UserCommand &user_command, int &x, int &y, std::istream &stream = std::cin)
{
  using namespace minesweeper;

  std::string c;
  do
  {
    c = "";
    stream >> c;
    std::transform(c.begin(), c.end(), c.begin(), tolower);
  } while (commands.find(c) == commands.end());

  user_command = static_cast<UserCommand>(commands.at(c));

  std::cout << "Row: ";
  get_integer(y, stream);

  std::cout << "Column: ";
  get_integer(x, stream);

  return true;
}

bool get_dimensions(int &x, int &y, std::istream &stream = std::cin)
{
  int _x, _y;

  do
  {
    std::cout << "Width: ";
    get_integer(_x, stream);

    std::cout << "Height: ";
    get_integer(_y, stream);
  } while (_x < 3 || _y < 3);

  x = _x;
  y = _y;

  return true;
}