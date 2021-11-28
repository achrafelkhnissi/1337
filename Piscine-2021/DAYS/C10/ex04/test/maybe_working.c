#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <utmp.h>
#include <utmpx.h>
#include <sys/time.h>

//open the Utmp file
// mine is different because I have mac so it is utmpx

void utmpprint(struct utmpx *log);
int openUtmpFile();

int main()
{
    struct utmpx buffer[100];
    int tmpfile = open("/var/run/utmpx", O_RDONLY);

    if (tmpfile < 0)
    {
        printf("Error opening utmpx file");
        return -1;
    }
    read(tmpfile, &buffer, sizeof(struct utmpx) * 100);
    for (int i = 0; i < 5; i++)
        printf("ut_user = %s\n", buffer[i].ut_user);

    return 0;
}
int openUtmpFile()
{
    int tmp = open("/var/run/utmpx", O_RDONLY);
    printf("%i", tmp);
    return tmp;
}

/* From:
 * 	https://stackoverflow.com/questions/64394182/reading-utmpx-without-file-in-c
 * 	https://opensource.apple.com/source/Libc/Libc-583/include/utmpx.h.auto.html
 */

