#include "rang.hpp"
#include <iostream>

int main() {
    // Test basic colors
    std::cout << rang::fg::blue << "Blue text" << rang::fg::reset << std::endl;
    std::cout << rang::fg::green << "Green text" << rang::fg::reset << std::endl;
    std::cout << rang::fg::red << "Red text" << rang::fg::reset << std::endl;

    // Test style
    std::cout << rang::style::bold << "Bold text" << rang::style::reset << std::endl;

    // Test background
    std::cout << rang::bg::yellow << "Yellow background" << rang::bg::reset << std::endl;

    return 0;
}
