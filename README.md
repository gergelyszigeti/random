Two tiny test programs to check custom random functions.
You can replace the example simple random function in `myrand.cpp`.
I implemented the random function as a functor, as it has its own state.
See `myrand.h` for deatils.


The two programs are:

`randtest`: test for uniformity, how uniform the distribution is

`randrepeat`: how often the generated "random" sequence is repeated


Please note, the sequence of random numbers are always the same and repeats after a while. However, if their distribution is uniform and the unique sequence is long enough before it repeats, we can live with it.
Even more sophisticated random generators work like this. Using some real random thing can be cumbersome (ground vibration, the pitch of birds' singing around, the age of the train driver in picoseconds, but even to catch the mouse movements can take a long time)   
