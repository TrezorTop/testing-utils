#ifndef TESTINGFRAMEWORK_CONTAINER_OPERATORS_H
#define TESTINGFRAMEWORK_CONTAINER_OPERATORS_H

#include <map>
#include <ostream>
#include <set>
#include <vector>

template <typename T>
void Print(std::ostream& ostream, T& container) {
  for (const auto& item : container) {
    if (item != *container.begin()) ostream << ", ";
    ostream << item;
  }
}

template <typename T>
std::ostream& operator<<(std::ostream& ostream, const std::vector<T>& container) {
  ostream << '{';
  Print(ostream, container);
  ostream << '}';

  return ostream;
}

template <typename T>
std::ostream& operator<<(std::ostream& ostream, const std::set<T>& container) {
  ostream << '[';
  Print(ostream, container);
  ostream << ']';

  return ostream;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& ostream, const std::map<T1, T2>& container) {
  ostream << '<';
  Print(ostream, container);
  ostream << '>';

  return ostream;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& ostream, const std::pair<const T1, T2>& pair) {
  ostream << '(' << pair.first << ", " << pair.second << ')';

  return ostream;
}

#endif  // TESTINGFRAMEWORK_CONTAINER_OPERATORS_H
