## Processese

### state of a process

### Kernel Mode versus User Mode

### Interrupts

### Traps

### System Calls

A mechinism allows user mode process to enter the kernel mode to execute kernel functions.

### Create new process

#### `fork`

### Basic Process Coordination

#### `exec`

#### `exit`

#### `wait`

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

#### `posix_spawn`

Alternatve for `fork()` / `exec()`. We'll use this command in project 3.

### Process Control Block

### Data versus Processes

file descriptors: stdin 0, stdout 1, stderr 2
