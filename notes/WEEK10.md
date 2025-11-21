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

- `fork()` takes no arguments.
- what does `fork()` return if it's successful? **child's process id to the parent and 0 to the child process**

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
