## To know:

1. **No** global variables :)
2. Arguments:
    - **number of philosophers** = number of forks
    - **time to die :** the philosopher must eat before time_to_die ms after starting or his last meal
    - **time to eat:** in ms, the time takes for a philo to eat.
    - **time to sleep:**  in ms it s resting time.
    - **number of times each philo must eat:**   optional, if all philosophers eat at least number_of_...  times the program stops if it’s not specified the program ends when a philo dies RIP.

---

## Tasks:

Now after we got the arguments we need to start by few things:

1. Each philosopher must have an index between [1 - number_of_philo] 

```
💡 Philo’s index starts from 1 not 0
```

1. Any change must be written this way:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
    
    
    **X:** the philosopher’s index.
    
```
    💡 The status printed should not be intertwined with another philo’s status. 
    in other words things must be synchronized. (It’s all about synchronization)
```
    
2. We can’t have more than **10 ms** between a philo’s death and when it will print its death.
3. We should avoid a philo’s death.

---

## **How ?!**

1. Each philosopher must be a thread *(you’ll know how to create a thread later).*
2. One fork between each philosopher, if there are multiple philosophers then one fork on the right and another one on the left.
3. To avoid philosophers duplicating forks we need to protect each fork with a mutex.
    
    **How again?!**
    
    → We’ll define at the beginning [number_of_philo mutexes], each philosopher has its own.
    
    → Once a philosopher picks up a fork, it’s locked using `mutex_lock()`, no one else can use it until it is unlocked by the same philosopher using `mutex_unlock()` and so on.
    
    → When the program is about to end ( a philosopher dies or they all ate at least [number of times to eat] times we have to destroy all the mutexes using `mutex_destroy()`, it’s basically like freeing that object so it can be reinitialized.
    

---

## Threads:

**what is a thread?**

A thread in computer science is short for a thread of execution. Threads are a way for a program to divide (termed "split") itself into two or more simultaneously (or pseudo-simultaneously) running tasks.

Thread example: lets say that the browser is a process and other applications also is processes! Threads can be the tabs within the browser!

Threads and processes help us in multitasking but there is a difference between them:

→ using multiple processes gives us two benefits. 

**Concurrency**

**Isolation:** the memory is separated and if one crushes, the others just keep running.

→ threads offer us only concurrency plus every thread has its own call stack.

---

## Creation:

```c
#include <phtreads.h>
```

```c
int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);
```

- **thread:** pointer to an unsigned integer value that returns the thread id of the thread created.
- **attr**: pointer to a structure that is used to define thread attributes like detached state, scheduling policy, stack address, etc. Set to NULL for default thread attributes.

***THREAD ATTRIBUTE STRUCTURE:***

```c
typedef struct {
    int                 __flags;
    size_t              __stacksize;
    void                *__stackaddr;
    void                (*__exitfunc)(void *status);
    int                 __policy;
    struct sched_param  __param;
    unsigned            __guardsize;
                } pthread_attr_t;
```

- **start_routine:** pointer to a subroutine that is executed by the thread. The return type and parameter type of the subroutine must be of type void *. The function has a single attribute but if multiple values need to be passed to the function, a struct must be used.
- **arg:** pointer to void that contains the arguments to the function defined in the earlier argument

```
💡 The last argument can help us to pass arguments to the function but we can also get results from the function using the second parameter of `pthread_join`
```

---

## Waiting:

```c
int pthread_join(pthread_t th, void **thread_return);
```

    Used to wait for the termination of a thread.

**th:** The target thread whose termination you're waiting for.

**thread_return*:*** NULL, or a pointer to a location where the function can store the value passed to *[pthread_exit()](https://www.qnx.com/developers/docs/6.4.0/neutrino/lib_ref/p/pthread_exit.html)* by the target thread.

`pthread_join` does two things:

1. Wait for the thread to finish.
2. Clean up any resources associated with the thread

If you exit the process without joining, then (2) will be done for you by the OS (although it won't do thread cancellation cleanup, just nuke the thread from orbit), and (1) will not. So whether you need to call `pthread_join` depends on whether you need (1) to happen.

If you don't need the thread to run, then as everyone else is saying you may as well detach it. A detached thread cannot be joined (so you can't wait on its completion), but its resources are freed automatically if it does complete.

---

### Detaching:

```c
**int pthread_detach(pthread_t thread);**
```

  

Used to detach a thread. A detached thread does not require a thread to join on terminating (it s no longer joinable). The resources of the thread are automatically released after terminating if the thread is detached.
In other words, if a thread is detached, it does not need to join back into its parent to release its resources *(and neither can you join it)*. This is useful when you want to have a thread that just does its thing without joining back with its creator.

```
💡 The thread by default is created joinable but we can make it detached since creation using the thread attributes.
```

As we said the detached thread can no longer be joinable so the program might exit before its termination to solve this use: **`pthread_exit();`**

## Mutexes *(mutual exclusion)*

The mutex (In fact, the term mutex is short for mutual exclusion) also known as spinlock is the simplest synchronization tool that is used to protect critical regions and thus prevent race conditions. That is a thread must acquire a lock before entering into a critical section (In critical section multi threads share a common variable, updating a table, writing a file and so on), it releases the lock when it leaves critical section.

The mutex lock allows the thread to lock a code section *(it says: Hey! I have the floor)* and exclude all the other threads.

---

### Initialization:

```c
# include <pthread.h>

pthread_mutex_t	*mutex;
```

```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```

You have to have allocated memory for it ahead of time *( pthread_mutex_init() does not call malloc().)*

---

### Lock:

```c
int pthread_mutex_lock (pthread_mutex_t * mutex);
```

> I want to point out here, that `pthread_mutex_lock()` does not actively **"lock"** other threads. Instead, *it locks a data structure*, which can be shared among the threads. The locking and unlocking of the data structure make synchronization guarantees, which are very important to avoiding *race conditions(see explanation below)*. However, I don't want you to get into the habit of thinking that `pthread_mutex_lock()` actively blocks other threads, or "locks them out." It doesn't -- it locks a data structure, and when other threads try to lock the same data structure, they block. Please re-read this paragraph.
> 

**What is a Race Condition?**
A race condition occurs when two or more threads can access shared data and try to change it at the same time. Because the thread scheduling algorithm can swap between threads at any time, you don't know the order in which the threads will attempt to access the shared data. Therefore, the result of the change in data is dependent on the thread scheduling algorithm, i.e. both threads are "racing" to access/change the data.

**What is a Deadlock?**
A deadlock happens when two threads/processes cannot make progress because each one waits for the other to release a lock, as illustrated in the following diagram.

![deaklock.png](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/imgs/deaklock.png)

***Note:*** if the mutex is locked by a thread, only that thread can unlock it, other threads wait until then.

---

### Unlock:

```c
int pthread_mutex_unlock (pthread_mutex_t * mutex);
```

---

### Destruction:

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

This function sets the mutex to an invalid value so it can be reinitialized but the destroyed mutex can no longer be used.

It is safe to destroy an initialized mutex that is unlocked. Attempting to destroy locked mutex results in undefined behavior.

```
💡 Every mutex must eventually be destroyed with pthread_mutex_destroy(). 
The machine eventually detects the error if a mutex is not destroyed, but the storage is deallocated or corrupted.
```
