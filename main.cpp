#include <iostream>

int Add(int x, int y) {
    return x * y;
}

template<typename T1, typename T2>
void AssertEqual(const T1& value, const T2& expected, const std::string& hint) {
    if (value == expected) return;

    std::cout << "Assertion failed: " << value << " != " << expected << '\n';
    std::cout << "Hint: " << hint << '\n';
    abort();
}

int main() {
    AssertEqual(Add(2, 3), 5, "Add() must add its arguments");

    return 0;
}
