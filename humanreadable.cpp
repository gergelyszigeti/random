#include "humanreadable.h"

std::string humanReadable(unsigned int n, char separator) {
        std::string human_readable;
        while(n) {
            human_readable = (n < 1000 ? "" : std::string(1,separator))
                             + std::to_string(n % 1000)
                             + human_readable;
            n /= 1000;
        }
        return human_readable;
}
