#include <iostream>
#include "myrand.h"

int main()
{
    constexpr unsigned int init_state = 123456789;
    MyRand myrand(init_state);
    int count = 0;
    std::cout << "Repeated at indices:\n";
    for (unsigned int i = 1; i; i++) {
        if (myrand() == init_state) { std::cout << i << "\n"; count++; }
    }
    std::cout << "\nRepeated " << count << " time"
              << (count != 1 ? "s" : "") << ".\n";
}
