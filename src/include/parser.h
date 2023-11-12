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
  const std::map<std::string, int> commands = {
      {"clear", 1},
      {"flag", 2}};
}

bool get_command(UserCommand &, int &, int &, std::istream &);
bool get_dimensions(int &, int &, std::istream &);

#endif