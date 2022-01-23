```
				███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗			
				██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝			 
				██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗			 
				██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗			
				╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝			

					PID: 0000			By: ael-khni
				⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰	
```

<h1 align="center">
	42cursus' minitalk 
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' ft_printf project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/achrafelkhnissi/1337/42curses"><b>42cursus repo</b></a>.
</p>


<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#intro-to-signals">Signals</a>
	<span> · </span>
	<a href="#resources">Resources</a>
</h3>

---

## Table of content

> The purpose of this project is to code a small data exchange program using Unix signals.

Create a communication program - in C - in the form of a client and server. The server is the first one to be launched, having to display its PID after. The client will take as parameters the server PID and the string to be sent. Once the string has been received by the server, this one should display it.

This communication should only be done using Unix signals. Only two signals can be used SIGUSR1 and SIGUSR2. The executable files are named client and server.

1. [Unix Processes](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/unix_processes.md)
2. [Unix Signals](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/unix_signals.md)
3. [Used Function & their brief explaination!](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md)
	- [`signal()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#signal)
	- [`sigaction()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#sigaction)
	- [`struct sigaction`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#struct-sigaction)
	- [`sigemptyset()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#sigemptyset)
	- [`sigaddset()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#sigaddset)
	- [`getpid()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#getpid)
	- [`kill()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#kill)
	- [`pause()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#pause)
	- [`sleep()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#sleep)
	- [`usleep()`](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/used_funcitons.md#usleep)
4. [minitalk explained!](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/minitalk.md)
	- [STEP 1: Make server receive a signal from client](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/minitalk.md#step-1-make-server-receive-a-signal-from-client)
	- [STEP 2: Convert ASCII character to Binary character](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/minitalk.md#step-2-convert-ascii-character-to-binary-character)
	- [STEP 3: Convert Binary character to ASCII character](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/minitalk.md#step-3-convert-binary-character-to-ascii-character)
	- [STEP 4: Sending a string from client to server](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/minitalk.md#step-4-sending-a-string-from-client-to-server)
	- [LINKS](https://github.com/achrafelkhnissi/1337/blob/master/42curses/minitalk/README/minitalk.md#links)
## Project Information

### About

The purpose of this project is to code a small data exchange program using *UNIX signals*. \
Keep in mind:
- You have to handle errors sensitively. In no way can your program quit unexpectedly (Segmentation fault, bus error, double free, etc).
- Your program cannot have memory leaks.
- You can use one global variable but it must be justified.

### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters

### Allowed Functions (manual)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`ft_printf`](https://github.com/achrafelkhnissi/1337/tree/master/42curses/ft_printf) and any equivalent YOU coded
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

## Intro to signals

Signals are standardized messages sent to a running program to trigger specific behavior, such as quitting or error handling. They are a limited form of inter-process communication (IPC), typically used in POSIX-compliant operating systems. \
When a signal is sent. the operating system interrupts the target process normal flow of executing to deliver the signal. Execution can be interrupted during any non-atomic instruction. If the process has previously registered a signal handler,  that routine is executed. Otherwise, the default signal handler is executed. \
A signal is an event generated by the UNIX and Linux systems in response to some condition. Upon receipt of a signal, a process may take action. \
A signal is just like an interrupt; when it is generated at the user level, a call is made to the kernel of the OS, which then acts accordingly. \
There are two types of signals:
- __Maskable__: signals which can be changed or ignored by the user (e.g., Ctrl+C)
- __None-Maskable__: Signals which cannot be changed or ignored by the user. These typically occurs when the user is signaled for non-recoverable hardware errors.

#### Handling signals
Signal handlers can be installed with the [`signal(2)`](https://man7.org/linux/man-pages/man7/signal.7.html) or [`sigaction(2)`](https://man7.org/linux/man-pages/man2/sigaction.2.html) system calls. If a signal handler is not installer for a particular signal, the fefault handler is user. Otherwise the signal is intercepted and the signal handler is invoked. \
The signals are defined in the header file signal.h as a macro constant. Signal name has started with a “SIG” and followed by a short description of the signal. So, every signal has a unique numeric value. Your program should always use the name of the signals, not the signals number. The reason is signal number can differ according to system but meaning of names will be standard. \
The macro NSIG is the total number of signal defined. The value of NSIG is one greater than the total number of signal defined (All signal numbers are allocated consecutively).

The following is a list of all signals with names as in the include file `<signal.h>`:

```
    No    Name         Default Action       Description
     1     SIGHUP       terminate process    terminal line hangup
     2     SIGINT       terminate process    interrupt program
     3     SIGQUIT      create core image    quit program
     4     SIGILL       create core image    illegal instruction
     5     SIGTRAP      create core image    trace trap
     6     SIGABRT      create core image    abort program (formerly SIGIOT)
     7     SIGEMT       create core image    emulate instruction executed
     8     SIGFPE       create core image    floating-point exception
     9     SIGKILL      terminate process    kill program
     10    SIGBUS       create core image    bus error
     11    SIGSEGV      create core image    segmentation violation
     12    SIGSYS       create core image    non-existent system call invoked
     13    SIGPIPE      terminate process    write on a pipe with no reader
     14    SIGALRM      terminate process    real-time timer expired
     15    SIGTERM      terminate process    software termination signal
     16    SIGURG       discard signal       urgent condition present on socket
     17    SIGSTOP      stop process         stop (cannot be caught or ignored)
     18    SIGTSTP      stop process         stop signal generated from keyboard
     19    SIGCONT      discard signal       continue after stop
     20    SIGCHLD      discard signal       child status has changed
     21    SIGTTIN      stop process         background read attempted from control terminal
     22    SIGTTOU      stop process         background write attempted to control terminal
     23    SIGIO        discard signal       I/O is possible on a descriptor (see fcntl(2))
     24    SIGXCPU      terminate process    cpu time limit exceeded (see setrlimit(2))
     25    SIGXFSZ      terminate process    file size limit exceeded (see setrlimit(2))
     26    SIGVTALRM    terminate process    virtual time alarm (see setitimer(2))
     27    SIGPROF      terminate process    profiling timer alarm (see setitimer(2))
     28    SIGWINCH     discard signal       Window size change
     29    SIGINFO      discard signal       status request from keyboard
     30    SIGUSR1      terminate process    User defined signal 1
     31    SIGUSR2      terminate process    User defined signal 2
```


## Resources
- [Signal (IPC)](https://en.wikipedia.org/wiki/Signal_(IPC))
- [Process (computing)](https://en.wikipedia.org/wiki/Process_(computing))
- [Thread (computing)](https://en.wikipedia.org/wiki/Thread_(computing))
- [How to use signal handlers in C](https://linuxhint.com/signal_handlers_c_programming_language/)
- [signals](https://people.kth.se/~johanmon/ose/assignments/signals.pdf)
- [How to Write Advanced Signal Handlers in UNIX](https://www.oracle.com/technical-resources/articles/it-infrastructure/dev-signal-handlers-studio.html)
- [sigaction() - IBM docs](https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigactn.htm)
- [What is the difference between sigaction and signal?](https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal)
- [What is sigaction in C?](https://jameshfisher.com/2017/01/13/c-sigaction/)
