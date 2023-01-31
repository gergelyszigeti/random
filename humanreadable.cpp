#include "humanreadable.h"

std::string humanReadable(unsigned int n, char separator) {
        std::string human_readable;
        while(n) {
            size_t leading_zeros =   static_cast<size_t>(n % 1000 < 100)
                                   + static_cast<size_t>(n % 1000 <  10);
            human_readable = (n < 1000 ? ""
                               : std::string(1,separator)
                                 + std::string(leading_zeros,'0')
                             )
                             + std::to_string(n % 1000)
                             + human_readable;
            n /= 1000;
        }
        return human_readable;
}
