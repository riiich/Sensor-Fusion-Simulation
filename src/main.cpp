#include <iostream>

int main() {
    std::cout << "C++ version: ";

    #ifdef __cpp_lib_chrono
        std::cout << "C++20 or later\n";
    #elif __cplusplus >= 201703L
        std::cout << "C++17\n";
    #elif __cplusplus >= 201402L
        std::cout << "C++14\n";
    #elif __cplusplus >= 201103L
        std::cout << "C++11\n";
    #elif __cplusplus >= 199711L
        std::cout << "C++98/03\n";
    #else
        std::cout << "Pre-standard C++\n";
    #endif

    std::cout << "__cplusplus value: " << __cplusplus << std::endl;

    return 0;
}