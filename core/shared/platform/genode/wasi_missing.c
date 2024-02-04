#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "wasi_missing.h"

/*

File operations with `at` suffix 

*/


int
linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags) {
    return -1;
  //return link(oldpath, newpath);
}

ssize_t
readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz) {
    return 0;
    //return readlink(pathname, buf, bufsiz);
}

int
symlinkat(const char *target, int newdirfd, const char *linkpath) {
    return -1;
    // return symlink(target, linkpath);
}

int
unlinkat(int dirfd, const char *pathname, int flags) {
  // The unlinkat() system call operates in exactly the same way  as  either  unlink()  or  rmdir(2)  (depending  on
  // whether or not flags includes the AT_REMOVEDIR flag) except for the differences described here.
  // XXX : Add AT_REMOVEDIR flag check

    // return unlink(pathname);
    return -1;
}

int
renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath) {
    //return rename(oldpath, newpath);
    return -1;
}

int
mkdirat(int dirfd, const char *pathname, mode_t mode) {
    //return mkdir(pathname, mode);
    return -1;
}

/*

Missing ones

*/

int posix_fallocate(int fd, off_t offset, off_t len){
  // Stub
  // TODO : Probably, requires native genode implementation
  return 0;
}

/*

Time related functions.
Stubbed for now (return 0 every time)

*/

// int utimensat(int dirfd, const char *pathname, const struct timespec times[2], int flags){
//   return 0;
// }
// 
// int futimens(int fd, const struct timespec times[2]){
//   return 0;
// }