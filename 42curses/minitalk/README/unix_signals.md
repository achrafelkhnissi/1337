# Unix Signals

> Signals: various notifications sent to a __process__ in order to notify it of various "improtant" events. By nature they interrupt whatever the process is doing and force it to handle them immediately.

Each signal has an integer that represents it, as well as a symbolic name. By using te command `kill -l` it's possible to list signals supported by the system.

|     name     |       default action      |    description                                       |   
|--------------|---------------------------|------------------------------------------------------|
|     SIGHUP   |       terminate process   |    terminal line hangup                              |     	
|     SIGINT   |       terminate process   |    interrupt program (Ctrl + C)                      |     	
|     SIGQUIT  |       create core image   |    quit program (Ctrl + D                            |  	
|     SIGILL   |       create core image   |    illegal instruction                               |      	
|     SIGABRT  |       create core image   |    abort(3) call (formerly sigiot)                   |          
|     SIGEMT   |       create core image   |    emulate instruction executed                      |        
|     SIGFPE   |       create core image   |    floating-point exception                          |              
|     SIGKILL  |       terminate process   |    kill program                                      |         
|     SIGBUS   |       create core image   |    bus error                                         |         
|     SIGSEGV  |       create core image   |    segmentation violation                            |             
|     SIGSYS   |       create core image   |    non-existent system call invoked                  |          
|     SIGPIPE  |       terminate process   |    write on a pipe with no reader                    |        
|     SIGALRM  |       terminate process   |    real-time timer expired                           |             
|     SIGTERM  |       terminate process   |    software termination signal                       |       
|     SIGURG   |       discard signal      |    urgent condition present on socket                |           
|     SIGSTOP  |       stop process        |    stop (cannot be caught or ignored)                |          
|     SIGTSTP  |       stop process        |    stop signal generated from keyboard               | 
|     SIGCONT  |       discard signal      |    continue after stop                               |   
|     SIGCHLD  |       discard signal      |    child status has changed                          |
|     SIGTTIN  |       stop process        |    background read attempted from control terminal   |         
|     SIGTTOU  |       stop process        |    background write attempted to control terminal    |       
|     SIGIO    |       discard signal      |    I/O is possible on a descriptor (see fcntl(2))    |         
|     SIGXCPU  |       terminate process   |    cpu time limit exceeded (see setrlimit(2))        |         
|     SIGXFSZ  |       terminate process   |    file size limit exceeded (see setrlimit(2))       |            
|     SIGVTALRM|       terminate process   |    virtual time alarm (see setitimer(2))             |          
|     SIGPROF  |       terminate process   |    profiling timer alarm (see setitimer(2))          |               
|     SIGWINCH |       discard signal      |    Window size change                                |     
|     SIGINFO  |       discard signal      |    status request from keyboard                      |      
|     SIGUSR1  |       terminate process   |    User defined signal 1                             |      
|     SIGUSR2  |       terminate process   |    User defined signal 2                             |              

## Sending Signals to Processes


The most common way of sending signals to processes is using the keyboard. There are certain key presses that are interpreted by the system as requests to send signals to the process with which we are interacting: Ctrl-C, Ctrl-D, Ctrl-Z.

Another way of sending signals to processes is done using various commands, usually internal to the shell: `kill`, `fg`.

A third way of sending signals to processes is by using the kill system call. This is the normal way of sending a signal from one process to another. This system call is also used by the `kill` command or by the `fg` command.

```c
 #include <unistd.h>    
 #include <sys/types.h>
 #include <signal.h>

 int main(void)
 {
     pid_t my_pid;
     
     my_pid = getpid();
     kill(my_pid, SIGSTOP);
     return (0);
 }
```
This example program causes a process to suspend its own execution by sending itself the STOP signal.

## Links
- [Introduction to Unix Signals Programming](http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html)
- [Unix / Linux - Signals and Traps](https://www.tutorialspoint.com/unix/unix-signals-traps.htm)
- [sginal(7) - Linux manual page](https://www.man7.org/linux/man-pages/man7/signal.7.html)
