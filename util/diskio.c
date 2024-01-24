#include "diskio.h"


// block size 1MB
double dWrite(int fd, const char* buf_w, int size_times){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    write(fd, buf_w, sizeof(char)*DEFAULT_BLOCK_SIZE*size_times);
    gettimeofday(&end, NULL);
    return time_diff(start, end);
}

double dRead(int fd, char* buf_r, int size_times){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    read(fd, buf_r, sizeof(char)*DEFAULT_BLOCK_SIZE*size_times);
    gettimeofday(&end, NULL);
    return time_diff(start, end);
}

void prepare_buffer(char *buffer, int size){
    for(int i=0; i<size; i++)
        buffer[i] = 'a';
}


