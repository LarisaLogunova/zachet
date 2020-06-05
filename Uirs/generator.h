#include <random>
#include <iostream>
#include <string>
#include <chrono>
#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

class generator
{
public:
    generator();
    ~generator();
    long double nu;
    long double t_corr;
    const long double w = 1000;
    long double white_noise_generator(long double m, long double d);
    long double nu_0 = 0;
    long double time_temp = 0;
    int temp = 0;
};
