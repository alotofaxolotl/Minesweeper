#include "../src/include/parser.h"
#include "tests.h"

#include <iostream>
#include <sstream>

// TODO: update tests to suit new get_command function
// TODO: test get_dimesions

void test_get_command(std::string test_name, std::string input, int &test_count, UserCommand expected_command, int expected_x, int expected_y)
{
  UserCommand command;
  int x;
  int y;

  std::stringstream ss;
  ss << input;
  get_command(command, x, y, ss);
  ASSERT_TRUE(test_name, test_count, command == expected_command && x == expected_x && y == expected_y);
}

void test_bad_get_command(std::string test_name, std::string input, int &test_count)
{
  UserCommand command;
  int x;
  int y;

  std::stringstream ss;
  ss << input;
  ASSERT_TRUE(test_name, test_count, !get_command(command, x, y, ss));
}

int main()
{
  int test_count = 0;
  const int total_tests = 3;

  test_get_command("valid clear command", "clear 3 5", test_count, UserCommand::CLEAR, 3, 5);
  test_get_command("valid flag command", "flag 4 7", test_count, UserCommand::FLAG, 4, 7);
  test_bad_get_command("invalid command", "save 1 2", test_count);

  TEST_COUNT(test_count, total_tests);
}