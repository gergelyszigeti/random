#include <iostream>
#include "myrand.h"
#include "humanreadable.h"

int main()
{
    constexpr unsigned int init_state = 123456789;
    MyRand myrand(init_state);
    int count = 0;
    auto max_index = static_cast<unsigned int>(-1);
    std::cout << "Initial number repeated at indices (between 1 and "
              << humanReadable(max_index) << "):\n";
    for (unsigned int i = 1; i; i++) {
        if (myrand() == init_state) {
            std::cout << humanReadable(i) << " ("
                      << static_cast<float>(i)/max_index*100 << "%)";
            count++;
            if (count == 1)
               { std::cout << " <-- also the length of unique sequence"; }
            std::cout << "\n";
        }
    }
    std::cout << "\nRepeated " << count << " time"
              << (count != 1 ? "s" : "") << ".\n";
}
