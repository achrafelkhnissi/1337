#include <utmp.h>
#include <paths.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
        struct utmp data;
        FILE *log_file = fopen(_PATH_UTMP, "r");
        memset(&amp;data, 0, sizeof(struct utmp));

        while(fread(&amp;data, sizeof(struct utmpx), 1, log_file) == 1){
                printf("Read a record , User : %s\n", data.ut_user);
        }
        fclose(log_file);
        return EXIT_SUCCESS;
}

