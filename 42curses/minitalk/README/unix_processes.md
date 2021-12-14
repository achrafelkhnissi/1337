# Unix Processes

When you execute a program on your Unix system, the system creates a special environment for that program. This environment contains everything needed for the system to run the program as if no other programs were running on the system.

Whenever it is issued a command in Unix, it starts/creates a new process.
> Process: instance of a running program.

Each process has its own `PID` - Process ID \
It's prossible to see the current processes by running the `ps` command or `ps -f` for more info. \
For more information run `man ps`

## Parent and Child Process

Each Unix process has two ID numbers assigned to it: The Process ID (PID) and the Parent process ID (PPID). Each user process in the system has a parent process.

### In C
Running program is a process. From this process, another process can be created. There is a parent-child relationship between the two processes. This can be achieved using a library function called `fork()`. `fork()` function splits the running process into two processes, the existing one is known as parent and the new process is known as a child. Here is a program that demonstrates this:u
```c
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  fork();
  printf("Before\n");
  fork();
  printf("After\n");
  return (0);
}
```
Output:
```
Before
After
Before
After
After
After
```
__parent process__: Process that executes the `fork()` system call. A parent process may have multiple child processes, but a child process only have one parent process.
> fork() successful:
> - The process ID (PID) of the child process is returned to the parent process.
> - 0 is returned to the child process.

> Failure:
> - -1 is returned to the parent process.
> - A child process is not created.

__Child Process__: is created as a copy of its parent process, it inherits most of its attributes. if a child process has no parent process, then the child process is created directly by the kernel. If a child rocess exits or is interrupted, then a SIGCHLD signal is sent to the parent process to inform about the termination of exit of the child process.

-------------------
Sometimes there is a need for a program to perform more than one function simultaneously. Since these jobs may be interrelated two different programs cannot be created to perform them. Both jobs should be performed simultaneously.

# Links
[Unix processes](https://www.tutorialspoint.com/unix/unix-processes.htm)
