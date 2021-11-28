#include <sys/types.h>
#include <utmp.h>
#include <pwd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

   struct passwd *buffer;
   struct utmp *naveen;

   while((buffer=getpwent()!=NULL)){
      printf("%s", buffer->pw_gecos);
      printf("%s", naveen->ut_user);
   }
   return 0;
}
