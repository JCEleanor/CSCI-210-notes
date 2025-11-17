## Pipes

- first in first out

- `mkfifo`, `mknod` commands will create named pipes

### Important characteristics of pipes `|`

- A pipe is a **byte stream**
- Pipes are unidirectional (not bidirectional) (Although there are exceptions)
- pipes have limited capacities (they are basically a memory buffer)
- when the pipe is full, the writer process will be blocked (synchornous)
- If the read end of the pipe is closed, i.e. no readers, the process receives the SIGPIPE signal, i.e., broken pipe, and terminates.

✦ The four key events or rules for reading from and writing to a pipe are:

1.  Reading from an empty pipe: If a process attempts to read from an empty pipe, the read call will block (wait) until there is some data to read.

2.  Reading from a pipe with no writers: If all file descriptors referring to the write-end of the pipe have been closed, any process attempting to read from the pipe will see an end-of-file (EOF) and read will return 0.

3.  Writing to a full pipe: If a process attempts to write to a pipe that is full, the write call will block until a reader process consumes some data, freeing up space in the pipe's buffer.

4.  Writing to a pipe with no readers: If a process attempts to write to a pipe that has no open file descriptors for reading, the process will receive a SIGPIPE signal. The default action for this signal is to terminate the process.

## Named Pipes (FIFOs)

```
jingchun_chiu@pct-isengard:/u/pa/nb/tolgacan/210/fall25$ ls -la scratch
prw-rw-r-- 1 tolgacan tolgacan 0 Nov 17 09:16 scratch
```

The p at the beginning of the file permissions string prw-rw-r-- indicates that the file type is a **named pipe (FIFO).**
