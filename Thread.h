#ifndef THREAD_H
#define THREAD_H

#if defined(__linux__)
#include "LiThread.h"
#elif defined(_WIN64) || defined(_WIN32) || defined(__WIN32__) || defined(__WIN64__) || defined(__CYGWIN__)
#include "WinThread.h"
#endif

#endif //THREAD_H
