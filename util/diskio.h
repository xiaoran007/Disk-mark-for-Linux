#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/time.h>
#include "utime.h"

#define DEFAULT_BLOCK_SIZE 1024 * 1024 // 1MiB (not MB)
#define DIR "./" // define default dir

#if __linux__
#define DISABLE_BUFFER posix_fadvise(fd, 0, 0, POSIX_FADV_DONTNEED)
#endif
#if __APPLE__
#define DISABLE_BUFFER fcntl(fd, F_NOCACHE, 1)
#endif

void prepare_buffer(char *buffer, int size);
double dWrite(int fd, const char* buf, int size_times);   // write 1MB to disk
double dRead(int fd, char* buf, int size_times);    // read 1MB from disk
