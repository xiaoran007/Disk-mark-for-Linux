#define _GNU_SOURCE
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "util/utime.h"
#include "util/diskio.h"
#include <limits.h>
#include <fcntl.h>

int main() {
    printf("start\n");
    int fd = open("test.dat", O_WRONLY|O_CREAT|O_SYNC|O_TRUNC, 0666);
    DISABLE_BUFFER;
    int size_times = 128;
    char* buf;
    buf = (char*) malloc(sizeof(char) * DEFAULT_BLOCK_SIZE*size_times);
    prepare_buffer(buf, size_times);

    double time_w = dWrite(fd, buf, size_times);
    printf("speed: %lf\n", size_times/time_w);
    fsync(fd);


    close(fd);


    int fd2 = open("test.dat", O_RDONLY|O_SYNC, 0666);
    fsync(fd2);
    DISABLE_BUFFER;
    lseek(fd2, 0, SEEK_SET); // Seek to start to read
    char* buf_r;
    buf_r = (char*) malloc(sizeof(char) * DEFAULT_BLOCK_SIZE*size_times);
    double time_r = dRead(fd2, buf_r, size_times);
    printf("speed r: %lf\n", size_times/time_r);
    close(fd2);
    free(buf);
    free(buf_r);
    return 0;
}



