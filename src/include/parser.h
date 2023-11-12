#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

enum UserCommand
{
  CLEAR = 1,
  FLAG = 2
};

namespace minesweeper
{
  std::map<std::string, int> commands = {
      {"clear", 1},
      {"flag", 2}};
}

// TODO: move functionality to a .cpp file

bool get_command(UserCommand &user_command, int &x, int &y)
{
  using namespace minesweeper;

  // TODO: make this function safe

  std::string c;
  std::cin >> c;
  std::transform(c.begin(), c.end(), c.begin(), tolower);

  if (commands.find(c) == commands.end())
    return false;

  user_command = static_cast<UserCommand>(commands[c]);

  // maybe swap the order of these? row -> col feels more intuitive
  // TODO: make it clear to the user what cell they are targeting

  std::cin >> x;
  std::cin >> y;

  return true;
}

#endif