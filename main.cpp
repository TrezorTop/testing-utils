#include <vector>

#include "testing_tools/assert/assert.h"
#include "testing_tools/assert_equal/assert_equal.h"

int main() {
  std::vector container = {1, 0, 2, -3, 6, 2, 4, 3};
  std::vector expected = {1, 0, 2, -3, 6, 2, 4};

  ASSERT(container != expected);

  return 0;
}
