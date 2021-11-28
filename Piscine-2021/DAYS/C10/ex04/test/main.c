#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<utmp.h>

int main()
{
      int fd;
      struct utmp cr;
      int reclen = sizeof(struct utmp);

      fd = open(_PATH_UTMP, O_RDONLY);
      if (fd == -1){
        perror("oops");
        return(1);
      }
      while (read(fd, &cr, reclen) == reclen)
        printf("-- %s\n", cr.ut_host);

      close (fd);
      return 0;
}
