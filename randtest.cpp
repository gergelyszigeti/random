// this is a little stupid histogram for testing uniformity of custom rand functions

#include <iostream>
#include <array>

#include "myrand.h"

int main()
{
   MyRand myrand;

   printf("RAND_MAX is %d\n", RAND_MAX); 
   
   auto rand_uniform = [&myrand]{
                   return static_cast<float>(myrand() & RAND_MAX)/RAND_MAX; };

   constexpr int dice_throw_count = 1e8;
   constexpr int lot_count = 80;
   auto lot = std::array<int, lot_count + 1>();
   
   // create and write out a histogram of millions of random throws with lot_count resolution
   for (int i = 0; i < dice_throw_count; ++i) {
       ++lot[static_cast<int>(rand_uniform()*lot_count)];
   }
   // write out the values
   for (int i = 0; i <= lot_count; ++i) {
       std::cout << lot[i] << ((i+1)%10? ", " : "\n");
   }
   // show bars
   std::cout << "\nBars:\n";
   constexpr int barheight = 10;
   float max_bar = *std::max_element(std::begin(lot), std::end(lot));
   float div = (max_bar+1) / (barheight+1);
   int y = barheight; while (y --> 0) {
       for(int x = 0; x < lot_count; x++) {
           std::cout << (lot[x] > static_cast<int>(y * div) ? "O" : " ");
       }
       std::cout << "\n";
   }
}
