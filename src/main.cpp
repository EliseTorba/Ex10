// copyright 2021 Elizaveta D.
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
    std::string test_1 = "3 + 7";
    std::cout << infix2postfix(test_1) << std::endl;
    std::string test_2 = "3 + 5 * 7";
    std::cout << infix2postfix(test_2) << std::endl;
    std::string test_3 = "2 + 6 * 3 / (4 - 2)";
    std::cout << infix2postfix(test_3) << std::endl;
    std::string test_4 = "(5.5 + 6) * (3 + 5)";
    std::cout << infix2postfix(test_4) << std::endl;

    return 0;
}
