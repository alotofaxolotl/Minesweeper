#ifndef TESTS_H_
#define TESTS_H_

#include <iostream>

void ASSERT_TRUE(std::string test_name, int &test_count, bool b)
{
  if (!b)
  {
    std::cout << __FUNCTION__ << " failed on line " << __LINE__ << "\n";
    return;
  }

  std::cout << test_name << " ~ PASSED!\n";
  test_count++;
}

void TEST_COUNT(const int &count, const int &total)
{
  std::cout << count << " out of " << total << " tests passed.\n";
}

#endif