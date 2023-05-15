#ifndef TESTINGFRAMEWORK_ASSERT_H
#define TESTINGFRAMEWORK_ASSERT_H

#include <iostream>

#include "../../utils/container_operators.h"

void AssertImpl(
    const bool& value,
    const std::string& valueString,
    const std::string& file,
    const std::string& function,
    const unsigned& line,
    const std::string& hint = ""
) {
  if (value) return;

  std::cerr << std::boolalpha;
  std::cerr << file << '(' << line << "): " << function << "()" << '\n';
  std::cerr << "ASSERT(" << valueString << ") failed: " << valueString << " is not " << true << '\n';
  if (!hint.empty()) std::cerr << "Hint: " << hint;

  std::cerr << '\n';
  abort();
}

#define ASSERT(value) AssertImpl((value), #value, __FILE__, __FUNCTION__, __LINE__)

#define ASSERT_HINT(value, hint) AssertImpl((value), #value, __FILE__, __FUNCTION__, __LINE__, hint)

#endif  // TESTINGFRAMEWORK_ASSERT_H
