#include "../src/include/parser.h"
#include "tests.h"

#include <iostream>
#include <sstream>

// TODO: test get_command
// TODO: test get_dimesions

void test_get_dimensions(std::string test_name, std::string input, int expected_width, int expected_height, int &test_count)
{
  std::stringstream ss;
  std::stringstream dummy_out;
  ss << input;

  int width;
  int height;

  get_dimensions(width, height, ss, dummy_out);
  bool result = width == expected_width && height == expected_height;
  ASSERT_TRUE(test_name, test_count, result);
}

void test_get_integer(std::string test_name, std::string input, int expected, int &test_count)
{
  std::stringstream ss;
  ss << input;

  int n;
  get_integer(n, ss);
  ASSERT_TRUE(test_name, test_count, n == expected);
}

int main()
{
  int test_count = 0;
  const int total_tests = 6;

  std::cout << "\n\n";

  test_get_dimensions("get_dimension: valid input", "5 3", 5, 3, test_count);
  test_get_dimensions("get_dimension: invalid then valid input", "-3 2 6 7", 6, 7, test_count);

  test_get_integer("get_integer: valid input", "52", 52, test_count);
  test_get_integer("get_integer: negative input", "-32", -32, test_count);
  test_get_integer("get_integer: ignore double", "42.5 17", 17, test_count);
  test_get_integer("get_integer: invalid then valid input", "apple $$ 42.5 -32", -32, test_count);

  TEST_COUNT(test_count, total_tests);

  std::cout << "\n\n";
  return 0;
}