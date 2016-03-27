#ifndef THREAD_H
#define THREAD_H

#if defined(__linux__)
#include "LiThread.h"
#elif defined(_WIN64) || defined(_WIN632)
#include "WinThread.h"
#endif


#endif //THREAD_H
