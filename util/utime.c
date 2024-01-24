#include "utime.h"

double time_diff(struct timeval start, struct timeval end){
    long seconds = end.tv_sec - start.tv_sec;
    long useconds = end.tv_usec - start.tv_usec;
    double time_use = (double) seconds + (double) useconds / 1000000;
    return time_use;
}

long time_diff_us(struct timeval start, struct timeval end){
    long seconds = end.tv_sec - start.tv_sec;
    long useconds = end.tv_usec - start.tv_usec;
    long time_use_us = seconds * 1000000 + useconds;
    return time_use_us;
}
