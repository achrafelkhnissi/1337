## Exercise 04: last

- Create a "program" called `ft_last` and that does the same thing as the system's command-line: `last`, without options.
- The submission directory should have a `Makefile` with the following rules: `all`, `clean`, `fclean`
- You're only allowed to `include` `<utmp.h>`, `<errno.h>` and `<sys/types.h>`
- You cannot use functions such as `ctime()`, `asctime`, `stat()`, etc.

## Notes.

- man last, utmp, wtmp, lastlog.
- .asl files = apple system log.
- [Ep.6 System Programming: who command](https://www.youtube.com/watch?v=JMcgrq173Ow)
- [how to open .asl files](https://www.google.com/search?client=safari&rls=en&q=how+to+open+apple+system+logs+files&ie=UTF-8&oe=UTF-8)
- http://macadmins.psu.edu/wp-content/uploads/sites/24696/2016/06/psumac2016-19-osxlogs_macadmins_2016.pdf
- [OSX: “last” command and utmpx](https://stackoverflow.com/questions/33417520/osx-last-command-and-utmpx)
- [last login](https://superuser.com/questions/128705/ssh-last-login-last-and-os-x)
- [piscine](https://github.com/amalliar/piscine-C/blob/master/d12/ex04/src/ft_wtmp_load.c)
- [how to use utmp.h header](https://www.google.com/search?q=how+to+use+utmp.h+header&client=safari&rls=en&sxsrf=ALeKk005-HDzoAVEIZRW2yD4AeCYyoyMlA%3A1622942923568&ei=yyS8YP-TIpLlgwfxiovABA&oq=how+to+use+utmp.h+header&gs_lcp=Cgdnd3Mtd2l6EAM6BwgAEEcQsANQ8SxY7y5gqTNoAXACeACAAc0BiAHxA5IBBTEuMS4xmAEAoAEBqgEHZ3dzLXdpesgBCMABAQ&sclient=gws-wiz&ved=0ahUKEwi_pczD7YHxAhWS8uAKHXHFAkgQ4dUDCA0&uact=5)
- [utmp](https://www.ibm.com/docs/fi/aix/7.2?topic=files-utmph-file)
- [wiki - utmp](https://en.wikipedia.org/wiki/Utmp)
- [How to read wtmp file?](https://stackoverflow.com/questions/10324144/how-to-read-wtmp-file)
- [man utmp](https://man7.org/linux/man-pages/man5/utmp.5.html)
- [utmp.h file](https://www.ibm.com/docs/fi/aix/7.2?topic=files-utmph-file)
- [Manipulating the database](https://www.gnu.org/software/libc/manual/html_node/Manipulating-the-Database.html)
- [Chapter 1: Intro to System Programming](http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/unix_lecture_notes/chapter_01.pdf)
- [Chapter 2: Login Records, File i/o, and Performance](http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/unix_lecture_notes/chapter_02.pdf)
- [reading utmp](https://stackoverflow.com/questions/26333279/reading-the-linux-utmp-file-without-using-fopen-and-fread)
- [System Programming](http://eng.harran.edu.tr/~msuzer/files/sysprog18/ch2.pdf)
- [Parsing wtmp logs](https://stackoverflow.com/questions/11093218/parsing-wtmp-logs-with-c)
- [Code impolements ac command](https://www.programmersought.com/article/74154021610/)

