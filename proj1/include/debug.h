#include <cstdio>
#include <assert.h>
#ifdef DEBUG
#define Log(format, ...)\
    printf("\33[1;35m[%s,%d,%s] " format "\33[0m\n",\
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#else
#define Log(format, ...) 
#endif