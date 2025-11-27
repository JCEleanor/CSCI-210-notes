## Processese

### state of a process

### Kernel Mode versus User Mode

### Interrupts

### Traps

### System Calls

A mechinism allows user mode process to enter the kernel mode to execute kernel functions.

- sys calls such as open(), read(), write cause a process to switch to kernal mode. (anytime your system interact with _outside world_ (files, network, terminal output) it almost certainly trigger the switch to kernal mode)

### Create new process

#### `fork`

A system call used to create a new process.

`fork()` takes no arguments.

What it does:

1. create a child process
2. duplicate resources: The child process gets a copy of the parent's data, including file descriptors. Both the parent and child have access to the same pipe ends (read/write) immediately after the fork.
3. Returns Different Values: It **returns 0 to the newly created child process** and **returns the child's Process ID (PID) to the parent process**. This allows the code to distinguish which process is running and execute different logic

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/type.h>

int main(){
  pid_t pid;
  // copy the process that is currently running the code
  pid = fork();
  if (pid < 0){
    fprintf("Fork failed\n");
    return 1;
  }
  else if (pid == 0){
    printf("I am the Child process. (PID: %d)\n", getpid());
    // what gets copied from the Parent into the Child
    // 1. the code: the child will have the exact same C code
    // 2. The variables: child gets every variable and its current value
    // 3. The current position: The child doesn't start from main() at the top. It starts life at the exact same line where fork() was called.
  }
  else{
    printf("2. I am the Parent process. (PID: %d, Child PID: %d)\n", getpid(), pid);
  }
}
```

### Basic Process Coordination

#### `exec`

- An `exec()` call will run a new program with a new process if

#### `exit`

#### `wait`

- a `wait()` system call will **NOT** wait indefinitely. If a process calls wait and it has no active child process, the sys call will fail immediately.
- wait will suspend the parent process until one of the child processes terminates.
- we can see which child process terminated by looking at the return value of wait.
- child process's exit code can be obtained via wait call.
- wait function tqkes an integer pointer as an arg, its purpose is to:
  - store the status information (exit code and signal info) of the terminated child.

`HC` and `HP` will be executed concurrently, so it's impossible to know which will print first.

```c
int main() {
    int child_status;
    if (fork() == 0) {
        printf("HC: hello from child\n");
        exit(0);
    } else {
    printf("HP: hello from parent\n");
    wait(&child_status);
    printf("CT: child has terminated\n");
    }
    printf("Bye\n");
    return 0;
}
```

- `waitpid`
  to wait for particular process to terminate

we'll focus more on processs creation.

- `chdir()`
  This system call is used to change the current working directory of the calling process.

#### Zombie process

A zombie process is a process which has executed but still has a record in the process table for the parent process to collect.

#### `posix_spawn`

Alternatve for `fork()` / `exec()`. We'll use this command in project 3.

### Process Control Block

- ctrl c does not always stop a program. (ctrl c the OS sends a specific `SIGINT` to the foreground process)

### Data versus Processes

file descriptors: stdin 0, stdout 1, stderr 2

### Standard I/O descriptors

Open files or other I/O channels are named within the process by an integer file descriptor value

The main takeaway of process slides:
**data is abstracted and everthing is files**

### Signal handler

When a signal (like SIGINT from ctrl c) is delivered to your process, the os has a default action (usually terminate process). A signal handler allows you to override the default action.
