#include "my_func.hpp"

void    compress_function(struct pollfd *fds, int nfds)
{
    for (int i = 0; i < nfds; i++)
    {
        if (fds[i].fd == -1)
        {
          for(int j = i; j < nfds; j++)
          {
            fds[j].fd = fds[j+1].fd;
          }
          i--;
          nfds--;
        }
    }
}