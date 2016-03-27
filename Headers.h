#ifndef HEADERS_H
#define HEADERS_H

#if defined(__linux__)

#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

#elif defined(_WIN64) || defined(_WIN632)

#include <Windows.h>

#endif

#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;



#endif //HEADERS_H

