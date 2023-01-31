class MyRand {
public:
    MyRand(int init_state = 19790327) : rand_state(init_state) {}
    unsigned int myrand();
    unsigned int operator()() { return myrand(); }

private:
    unsigned int rand_state;
};
