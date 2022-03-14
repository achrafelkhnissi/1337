# BONUS PART

## TODO :

- [ ]  Read about fork and multiprocessing
    - [ ]  Check the use of the following functions:
        - `fork()`
        - `kill()`
        - `waitpid()`
    - [ ]  Create a process for each philosopher.
    
- [ ]  Read about Semaphores
    - [ ]  Check the use of the following functions:
        - `sem_open()`
        - `sem_close()`
        - `sem_post()`
        - `sem_wait()`
        - `sem_unlink()`
    - [ ]  Create a semaphore that represents the number of available forks, decrement when a Philo takes a fork, and increment when a Philo puts down a fork.
    
- [ ]  Combine the two and try to create a 3 Philos and 3 forks with only the following actions:
    - [ ]  Grab a fork with the right hand
    - [ ]  Grab a fork with the left hand
    - [ ]  Start eating
    - [ ]  Finish eating
    
- [ ]  Handle the optional argument [number_of_times_each_philosopher_must_eat]

- [ ]  If the above worked perfectly, add the following actions:
    - [ ]  Thinking
    - [ ]  Sleeping
    
- [ ]  Handle the philosopher’s death.

### [`int fork();`](https://man7.org/linux/man-pages/man2/fork.2.html)

This system call is used to create one or many child processes.

#### return:

       If it’s the main process (the parent) it returns the child pid

       If it’s the child process it returns 0

> You might ask why the return value is like we said above, simply because the child won't need the id to be returned it can get simply get it using `getpid()`, but the parent needs to keep track of the children so it needs the ids.

#### How does it work?

When we call fork the execution line splits into 2 execution lines, the child process created continue the execution from the line forward 

![fork equation](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/fork-equation.png)

→ Example with 3 calls of `fork()`, we got 8 processes.
![fork visual](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/forks.png)

### [`int kill(pid_t pid, int sig);`](https://man7.org/linux/man-pages/man2/kill.2.html)

```c
#include <sys/types.h>
#include <signal.h>
```

This function is used to send signals to a process or a group of signals.

### [`pid_t waitpid(pid_t pid, int *status, int options);`](https://man7.org/linux/man-pages/man3/waitpid.3p.html)

```c
#include <sys/types.h> 
#include <sys/wait.h>
```

The `waitpid()` system call suspends execution of the current process until a child specified by *pid* argument has changed state. By default, `waitpid()` waits only for terminated children, but this behavior is modifiable via the *options*
 the argument, as described below.

Link for more informations :  [Lean more.](https://www.tutorialspoint.com/unix_system_calls/waitpid.htm)

`int *status` 

> This argument helps us  to know the status of the  terminated process \
> We can use it to check if one of the processes (a philosopher) died, if the status ≠ 0, we can terminate all the other processes and terminate the program. \
> 💡 We can wait for  any child instead of a special one: `waitpid(-1, &ret, 0);`

### How to create a fixed number of processes?
```c
int main()
{
  int ret;
  int i;

  i = 0;    
  while (i < 5)// we want to create 5 children. 
  {
    ret = fork();
    if(ret == 0)
    {
    /*
     ... code to be executed by the child process
    */
    exit(0); // the child peocess exits after completing the task demanded.
    }
    i++;
  }
  return (0);
}
```

## Semaphore

Semaphore is simply an unsigned int. This variable is used to solve the critical section problem and to achieve process synchronization in the multiprocessing environment.

Semaphores are of two types:

1. **Counting Semaphore** 
    
    **–** Its value can range over an unrestricted domain. It is used to control access to a resource that has multiple instances.

![sem_1](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/sem_1.png)

2. **Binary Semaphore** 
    
    **–** This is also known as mutex lock. It can have only two values – 0 and 1. Its value is initialized to 1. It is used to implement the solution of critical section problems with multiple processes.

![sem_2](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/sem_2.png)

> ***Note:**  there are named and unnamed semaphores.*

> **Named Semaphores** are like process-shared semaphores, except that named semaphores are referenced with a pathname rather than a shared value. Named semaphores are sharable by several processes. Named semaphores have an owner user-id, group-id, and a protection mode.

> **Unnamed Semaphores** are allocated in process memory and initialized. Unnamed semaphores might be usable by more than one process, depending on how the semaphore is allocated and initialized. Unnamed semaphores are either private, inherited through **fork()**, or are protected by access protections of the regular file in which they are allocated and mapped.

### Creation:

```c
#include <semaphore.h>

sem_t semaphore;
```

### **Initialisation:**

#### [`sem_open()`]():

```c
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */

sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag,
                mode_t mode, unsigned int value);
```

The `sem_open()` function creates a connection between a named semaphore and a process. Once the connection has been created for the semaphore name specified by the *name* argument with a call to `sem_open()`, the process can use the address returned by the call to reference that semaphore.

**name →** The name of the semaphore that you want to create or access.

**oflag →**  Flags that affect how the function creates a new semaphore. This argument is a combination of:

- O_CREAT
    
    This flag is used to create a semaphore if it does not already exist. If O_CREAT
     is set and the semaphore already exists, then O_CREAT has no effect, except as noted under the description of the **O_EXCL** flag.
    
- O_EXCL
    
    If the **O_EXCL** and **O_CREAT** flags are set, the **sem_open** subroutine fails if the semaphore name exists. The check for the existence of the semaphore and the creation of the semaphore if it does not exist are atomic with respect to other processes executing the **sem_open** subroutine with the **O_EXCL** and **O_CREAT** flags set. If **O_EXCL** is set and **O_CREAT** is not set, **O_EXCL** is ignored.
    
```
💡 Don't set *oflag* to O_RDONLY, O_RDWR, or O_WRONLY. A semaphore's behavior is undefined with these flags. 
The QNX libraries silently ignore these options, but they may reduce your code's portability.
```

```
💡 The **O_CREAT** flag requires a third and a fourth parameter: *mode*, 
which is of type **mode_t**, and *value*, which is of type **unsigned**.
```

**mode_t *mode** →* The semaphore's mode (just like file modes). For portability, you should set the read, write, *and* execute bits to the same value. An easy way of doing this is to use the constants from <sys/stat.h>:
• S_IRWXG for group access.
• S_IRWXO for other's access.
• S_IRWXU for your own access.

Example:
```c
sem_open("sem", O_CREAT | O_EXCL, 0644, n);
```
> 0644

> 0: no access to file \
> 6: read/write permisson for the user \
> 4: read only for the group and others

**unsigned int *value →*** The initial value of the semaphore. A positive value (i.e. greater than zero) indicates an unlocked semaphore, and a *value* of 0 (zero) indicates a locked semaphore. This value must not exceed SEM_VALUE_MAX.

**Return Values:** 

Upon successful completion, the function returns the address of the semaphore. Otherwise, it will return a value of **SEM_FAILED** and set `errno` to indicate the error. The symbol S**EM_FAILED** is defined in the header `<semaphore.h>`. No successful return from sem_open() will return the value **SEM_FAILED.**

### sem_init:

```c
int sem_init(sem_t *semaphore, int pshared, unsigned int value);
```

**semaphore →** The sem_t pointer to initialize.

p**shared →** This parameter argument is fundamental in the declaration of semaphore. As it determines the status of the newly initialized semaphore. Whether or not it should be shared between the processes or threads. If the value is non-zero, it means that the semaphore is shared between two or more processes, and if the value is zero, then it means the semaphore is shared between the threads.

v**alue →** It specifies the value that is to be assigned to the newly created semaphore that is assigned initially.

> **Return value:** \
> 0 if success. \
> 1 if error.          

### Blockage:

```c
int sem_wait(sem_t *semaphore);
```

> **Return value:** \
>  0 if success. \
>  -1 if error.               

### Release:

```c
int sem_post(sem_t *semaphore);
```

> **Return value:** \
>  0 if success. \
>  -1 if error. 

### Closure:

```c
int sem_close(sem_t *sem);
```

closes the named semaphore referred to bysem,  allowing any resources that the system has allocated to the calling process for this semaphore to be freed. ***the semaphore still remains in the system.***

> **Return value:** \
>  0 if success. \
>  -1 if error. 

```c
int sem_unlink(const char *name);
```

removes the named semaphore referred to by name from the system. The semaphore name is removed immediately.  The semaphore is destroyed once all other processes that have the semaphore open close it.

> **Return value:** \
>  0 if success. \
>  -1 if error.
