# Used Functions

## signal()
```c
int signal(int signum, void (*funct)(int));
```
> [`signal()`](https://man7.org/linux/man-pages/man7/signal.7.html): function will call the function funct if the process receives the signal signum.
> It will return a pointer to the funct function if successful or -1 in case of error.

## sigaction()
```c
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
```
> [`sigaction()`](https://man7.org/linux/man-pages/man2/sigaction.2.html): allows the calling process to examine or specify the action to be taken on delivery of a specific signal \
> The __sig__ argument specifies the signal and can be assigned any of the signals specified in [signal.h](https://docs.oracle.com/cd/E88353_01/html/E37842/signal.h-3head.html#REFMAN3Fsignal.h-3head) except `SIGKILL` and `SIGSTOP` \
> If the argument __act__ is not __NULL__, it points to a structure specifying the new action to be taken when delivering __sig__. \
> If the argument __oact__ is not __NULL__. it points to a structure where the action reviously associated with __sig__ is to be stored on return from `sigaction()`

To be able to me `client` recieve a confirmation from `server` that it recieved the string, the program uses `sigaction()`. \
This makes it possible to the `PID` of the sender using `info->si_pid`

### struct sigaction
```c
struct sigaction
{
    void       (*sa_handler)(int);
    sigset_t   sa_mask;
    int        sa_flags;
    void       (*sa_sigaction)(int, siginfo_t *, void *);
};
```
- __sa_handler__: pointer to the function assigned to handle the signal. The value of this member can also be `SIG_DFL` (indicating the default action) or `SIG_IGN` (indicating that the signal is to be ignored).
- __sigset_t__ data type: used to represent a signal set.
- __sa_mask__: A signal set identifies a set of signals that are to be added to the signal mask of the calling process before the signal-handling function `sa_handler` or `sa_sigaction` (in XPG4.2) is invoked. For more on signal sets, see `sigemptyset()` — Initialize a signal mask to exclude all signals. You cannot use this mechanism to block `SIGKILL`, `SIGSTOP`, or `SIGTRACE`. If `sa_mask` includes these signals, they will simply be ignored; `sigaction()` will not return an error. `sa_mask` must be set by using one or more of the signal set manipulation functions: `sigemptyset()`, `sigaddset()` for example.
- __sa_flag__: specifies a set of flags used to modify the delivery of the signal.
- __sa_sigaction__: a pointer to the function assigned to handle the signal, or `SIG_DFL`, or `SIG_IGN`. This function will be invoked passing three parameters.
  - __int__: signal type for which this function is being invoked.
  - __siginfo_t__: contains additional information about the source of the signal.
  - __void pointer__: pointer to a ucontect_t containing the context information at the time. of the signal interrupt.

## sigemptyset()
```c
```
> __sigemptyset()__: initializes the signal set given bye __set__ to empty, with all signals excluded from the set.
## sigaddset()
```c
int sigaddset(sigset_t *set, int signo);
```
> __sigaddset()__: adds the individual signal specified by the value of __signo__ to the set pointed to by __set__.
## getpid()
```c
pid_t getpid(void);
```
> __getpid()__: returns process ID (PID) of the calling process.

This function is used in the project since the `server` needs to show its PID first thing when executed.
## kill()
```c
int kill(pid_t pid, int sig);
```
> __kill()__: used to send any signal to any process group or process.
> - If pid is positive, then signal sig is sent to pid.
> - If pid is equal to 0, then sig is sent to every process in the process group of the current process.
> - If pid is equal to -1, then sig is sent to every process for which the calling process has permission to send signals, except for process 1 (init), but see below.
> - If pid is less than -1, then sig is sent to every process in the process group -pid.
> - If sig is 0, then no signal is sent, but error checking is still performed.
> (For a process to have permission to send a signal it must either be privileged (under linux: have the CAP_KILL capabilit), or the real or effective user ID of the sending process must equal to real or saved set-user-ID of the target process. In the case of SIGCONT it suffices when the sending and receiving processes belong to the same session)

Both `client` and `server` use `kill()` system call to sent `SIGUSR1` and `SIGUSR2` signals. `client` sends signals to server representing the bits of the string. `server` sends signals to client confirming it reveived the bits.
## pause()
```c
int pause(void);
```
> __pause()__: causes the calling process (or thread) to sleep untill a signal is delivered that either terminates the process or causes the invocation of a signal-catching function.

## sleep()
```c
unsigned int sleep(unsigned int seconds);
```
> __sleep()__: causes the calling thread to sleep either until the number of real-time seconds specified in seconds have elapsed or until a signal arrives which is not ignored.

## usleep()
```c
int usleep(useconds_t usec);
```
> __usleep()__: suspends execution of the calling thread for (at least) usec miscroseconds. The sleep may be lengthened slightly by any sysytem activity or by the time spent processing the call or by the granularity of the system timers.

# Links
- [How to use signal handlers in C language?](https://linuxhint.com/signal_handlers_c_programming_language/)
- [IBM docs - sigaction()](https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-sigaction-examine-change-signal-action)

