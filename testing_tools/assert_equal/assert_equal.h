#ifndef TESTINGFRAMEWORK_ASSERT_EQUAL_H
#define TESTINGFRAMEWORK_ASSERT_EQUAL_H

#include <iostream>
#include <string>

#include "../../utils/container_operators.h"

template <typename T1, typename T2>
void AssertEqualImpl(
    const T1& value,
    const T2& expected,
    const std::string& valueString,
    const std::string& expectedString,
    const std::string& file,
    const std::string& function,
    unsigned line,
    const std::string& hint = ""
) {
  if (value == expected) return;

  std::cerr << std::boolalpha;
  std::cerr << file << '(' << line << "): " << function << "()" << '\n';
  std::cerr << "ASSERT_EQUAL(" << valueString << ", " << expectedString << ") failed: " << value << " != " << expected
            << '\n';
  if (!hint.empty()) std::cerr << "Hint: " << hint;

  std::cerr << '\n';
  abort();
}

#define ASSERT_EQUAL(value, expected) \
  AssertEqualImpl((value), (expected), #value, #expected, __FILE__, __FUNCTION__, __LINE__)

#define ASSERT_EQUAL_HINT(value, expected, hint) \
  AssertEqualImpl((value), (expected), #value, #expected, __FILE__, __FUNCTION__, __LINE__, hint)

#endif  // TESTINGFRAMEWORK_ASSERT_EQUAL_H
