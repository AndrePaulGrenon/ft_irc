#ifndef MYFUNC_HPP
#define MYFUNC_HPP

#include <poll.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include <string>

void    compress_function(struct pollfd *fds, int nfds);

#endif