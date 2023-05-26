#ifndef _UNISTD_H_
#define _UNISTD_H_

#include <stddef.h>

int brk(void *addr);
void *sbrk(ssize_t increment); 

#endif // _UNISTD_H_
