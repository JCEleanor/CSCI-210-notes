## Pipes

### Important characteristics of pipes

- A pipe is a **unidirectional** (aka half-duplex, although there are exceptions) byte stream which has a write end and a read end
- communication bridge between related processes, typically a child and a parent process
- pipes are implemented as fixed size **memory buffer** in kernal memory (so they have limited capacity)
- first in first out data structure
- can be created with `pipe()` system call
- automatically destroy when all associated processes close the pipe
- standard pipes are anonymous; they have no names in file system
- when the pipe is full, the writer process will be blocked (synchornous)
- If the read end of the pipe is closed, i.e. no readers, the process receives the SIGPIPE signal, i.e., broken pipe, and terminates.

### create pipes in C

```c
#include <unistd.h>
int main(){
    int fd[2]; // file descriptors for pipes

    // create buffer in kernal memory
    if (pipe(fd) == -1){
        perror("Failed to create pipes");
        return 1;
    }

    // if succeed, return two file descriptor
    // fd[1] => parent: write end (for writing)
    // fd[0] => child: read end (for reading)
}

```

## Named Pipes

### Important characteristics of pipes

- accessible via a pathname in the filesystem
- allow communication between unrelated processes
- persist until explicitly deleted from the filesystem

- `mkfifo`, `mknod` commands will create named pipes
- First In First Out: If we write byte B to a pipe after byte A is written, byte A will be read by the reader process first.
- `p` means named pipes:

```
jingchun_chiu@pct-isengard:/u/pa/nb/tolgacan/210/fall25$ ls -la scratch
prw-rw-r-- 1 tolgacan tolgacan 0 Nov 17 09:16 scratch
```

### Create Named Pipes

#### Writer process

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd;
    char msg[] = "Hello via FIFO";

    // open named pipe for writing
    fd = open("/tmp/fifo", O_WRONLY);
    write(fd, msg, str_len(msg));
    close(fd);
    return 0;
}
```

#### Reader process

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h> // for integer operation

int main() {
    int fd;
    char buf[100];

    // Create the named pipe
    mkfifo("/tmp/myfifo", 0666);

    // Open for reading
    fd = open("/tmp/myfifo", O_RDONLY);
    read(fd, buf, 100);
    printf("Received: %s\n", buf);
    close(fd);

    return 0;
}
```

## Pipes VS. Named Pipes

| Feature        | Anonymous Pipes                        | Named Pipes (FIFOs)                         |
| :------------- | :------------------------------------- | :------------------------------------------ |
| **Scope**      | Related processes only (parent-child). | Any process on the same system.             |
| **Filesystem** | No existence in filesystem.            | Exists as a special file with a path.       |
| **Lifespan**   | Destroyed when processes close it.     | Persists until deleted (like a file).       |
| **Creation**   | `pipe()` system call.                  | `mkfifo()` system call or command.          |
| **Access**     | Inherited via `fork()`.                | Accessed via permissions (open/read/write). |
| **Direction**  | Unidirectional (one-way).              | Unidirectional (one-way).                   |

#### The four key events or rules for reading from and writing to a pipe are:

1.  Reading from an empty pipe: If a process attempts to read from an empty pipe, the read call will block (wait) until there is some data to read.

2.  Reading from a pipe with no writers: If all file descriptors referring to the write-end of the pipe have been closed, any process attempting to read from the pipe will see an end-of-file (EOF) and read will return 0.

3.  Writing to a full pipe: If a process attempts to write to a pipe that is full, the write call will block until a reader process consumes some data, freeing up space in the pipe's buffer.

4.  Writing to a pipe with no readers: If a process attempts to write to a pipe that has no open file descriptors for reading, the process will receive a SIGPIPE signal. The default action for this signal is to terminate the process.

### Quiz

1. When you open a pipe with the pipe(fd) function call, where fd is an array of two integers, and you follow that call with a fork() call. If you want to use the pipe as a communication channel from the child process to the parent process, which of the following actions should be completed to finish setting up the pipe?

- To set up a pipe correctly, you must close the "unused" ends of the pipe in each process.

2. If a process tries to read from a pipe, it will be blocked even though there are no writer processes at the write end of the pipe. (F)

- The read() system call will return 0 (indicating end-of-file/EOF)
- This signals to the reading process that no more data will be written to the pipe
- The reading process can then proceed accordingly (typically by closing the pipe and continuing execution)

The blocking behavior only occurs when:

- There are writer processes with the write end open, but
- No data is currently available in the pipe

3. A pipe can have multiple reader processes reading from it.

4. The write end of a pipe can be open by only one writer process. When other processes try to open it for writing, they will be blocked until the first write process closes the write end of the pipe.

5. If a process wants to open a named pipe to write to it, the open() system call will be blocked until there is at least one reader process at the read end of the pipe.

6. A writer process that tries to write to a pipe will get a SIGPIPE (broken pipe) signal if the pipe is full.

- A writer process gets a SIGPIPE signal when there are no reader processes at the read end of the pipe, not when the pipe is full.

When the pipe is full:

- The write() system call will block (wait) until space becomes available
- The writer process is suspended until the reader consumes some data
  No SIGPIPE signal is generated

When there are no readers:

- The writer receives a SIGPIPE signal
- This indicates a "broken pipe" because there's no one to read the data being written
- If SIGPIPE is not handled, the default action is to terminate the process.
