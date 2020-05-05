#ifndef UTILS_INCLUDED
#define UTILS_INCLUDED

#include <stdlib.h>
#include <time.h>
#include <iostream>

double rand_0_1()
{  return rand()/static_cast<double>(RAND_MAX); }

double rand_m1_1()
{  return rand_0_1()*2-1; };

#endif
