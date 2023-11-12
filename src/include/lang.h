#ifndef LANG_H_
#define LANG_H_

#include <map>

namespace minesweeper
{
  const std::map<std::string, std::string> feedback = {
      {"bad move", "Sorry, you can't do that.\n\n"},
      {"win", "Congrats! You won!\n\n"},
      {"lose", "Better luck next time!\n\n"},
      {"bad command", "That is not a valid command!\n"}};
}

#endif