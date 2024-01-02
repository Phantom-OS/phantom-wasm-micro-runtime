#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

/*

File operations with `at` suffix 

*/


int
linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags);

ssize_t
readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz);

int
symlinkat(const char *target, int newdirfd, const char *linkpath);

int
unlinkat(int dirfd, const char *pathname, int flags);

int
renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath);

int
mkdirat(int dirfd, const char *pathname, mode_t mode);

/*

Missing ones

*/

int 
posix_fallocate(int fd, off_t offset, off_t len);

/*

Time related functions.
Stubbed for now (return 0 every time)

*/

int 
utimensat(int dirfd, const char *pathname, const struct timespec times[2], int flags);
int 
futimens(int fd, const struct timespec times[2]);