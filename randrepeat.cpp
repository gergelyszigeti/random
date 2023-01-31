#include <iostream>
#include "myrand.h"

int main()
{
    constexpr unsigned int init_state = 123456789;
    MyRand myrand(init_state);
    int count = 0;
    auto max_index = static_cast<unsigned int>(-1);
    std::cout << "Repeated at indices (between 1 and "
              << max_index << "):\n";
    for (unsigned int i = 1; i; i++) {
        if (myrand() == init_state) {
            std::cout << i << " ("
                      << static_cast<float>(i)/max_index*100 << "%)\n";
            count++;
        }
    }
    std::cout << "\nRepeated " << count << " time"
              << (count != 1 ? "s" : "") << ".\n";
}
