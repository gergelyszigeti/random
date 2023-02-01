// this is a little stupid histogram for testing uniformity of custom rand functions

#include <iostream>
#include <iomanip>
#include <array>

#include "myrand.h"

int main()
{
   MyRand myrand;

   auto rand_uniform = [&myrand]{
                   return static_cast<float>(myrand() & RAND_MAX)/RAND_MAX; };

   constexpr int bucket_target = 100;
   constexpr int bucket_count = 80;
   constexpr int dice_throw_count = bucket_target * bucket_count;
   auto buckets = std::array<int, bucket_count + 1>();

   std::cout << "Target quantity in each bucket: " << bucket_target << "\n";

   // create and write out a histogram of random throws with bucket_count resolution
   for (int i = 0; i < dice_throw_count; ++i) {
       ++buckets[static_cast<int>(rand_uniform()*bucket_count)];
   }
   // write out the values
   for (int i = 0; i <= bucket_count; ++i) {
       std::cout << std::setw(6) << buckets[i]
                 << (((i+1)%10 && i != bucket_count) ? ", " : "\n");
   }
   // show bars
   std::cout << "\nBars:\n";
   constexpr int barheight = 10;
   float max_bar = *std::max_element(std::begin(buckets), std::end(buckets));
   float div = (max_bar+1) / (barheight+1);
   int y = barheight; while (y --> 0) {
       for(int x = 0; x < bucket_count; x++) {
           std::cout << (buckets[x] > static_cast<int>(y * div) ? "O" : " ");
       }
       std::cout << "\n";
   }
}
