## File system organization: file + inode + directory structure

A well formed file system is composed of three main components:

### 1. the file

Is a collection of data blocks, on a storage device, containing the data of interest

### 2. **inode**: a structure assigned to eah file to store its metadata

Inodes do not contain the filename. Instead, inodes contain metadata about a file (like permissions, timestamps, size, and pointers to data blocks), but the filename itself is stored in the directory entry that points to that inode.

- **Each file has an inode to store its metadata and locate the files's content**
- inodes are stored in a table, which is allocated when the filesystem is first created, which means there are fixed numbers of inodes in a file system.
  - in linux ext4, a default ratio of 1 inode per 16 KBs of total capacity is used.
- use `ls -i` to get the inode number information of files/directories
- use `df -i` to get usage information on inodes in a file system

### 3. directory structure: a table to store file names and inode numbers

- filenames and inode number are not stored in the inode. They are stored in directory structure
- use `ls -d` to inspect a directory (instead of listing its content)

| Filename | inode #  |
| -------- | -------- |
| a.txt    | 33534535 |
| b.txt    | 34545221 |
| dir1     | 45455455 |

## File system organization: symbolic and hard links

### Symbolic links

- When listed inside a directory, the `l` flag at the very first column of a long
  format listing identifies them as links.
- deleting the target file does not remove the symbolic links pointing to that file
- create symbolic link using `ln -s [target file] [link name]`
- also called <i>soft</i> links

### Hard links

- They are independent entries in the same or different directory strucures that point to the **same inode**. In other words, they are aliases to the same single file
- The system keeps track of number of hard links to a file, so that the data blcks are deleted from the disk only after the last remaining link to that inode is deleted
- creare hard links `ln [target file] [hard link name]`

## The superuser

- administers the OS
- is not affected by file permission (can move, delete any file that belongs to anyone
- used to be called root user
- Today, instead of logging as the root user each time, regular users can be given superuser privileges by listing them in a special file named: **sudoers**
- using the **`sudo`** command to execute a command as the superuser is recommended.

### `sudo`

`sudo [OPTION] [CMD]`
super user do

- on Ubuntu, Debiam and Kali Linux, `apt` is the main package manager
  - `sudo apt-get update`
  - `sudo apt-get install [package_name]`

### User management

- `who`: prints info about all users who are currently logged in
- `w`: similar to `who` but prints more info
- `id [USERNAME`: print the user and group info for the specified [USERNAME]
- Users can be added using the `useradd` command and can be removed using the `userdel` command

## Querying and manipulating processes

- **A process is a running copy of a program along with its allocated resources such, memory, file handles, network sockets, etc.**
- there can be multiple different processes of a program - example: vim is a program installed on isengard. When different users edit their own files simultaneously, there will be multiple and separate vim processes with their own process ids, memory footprints, etc.
- processes are dynamic, i.e., there are various events in their lifetimes: created, paused, run, killed and completed

- `ps` to list all processes
- `ps -ef` will list all the processes in full-format

### Foreground and Background Processes

when you run a program in your bash shell, by default, it is run as a foreground process, meaning that your interaction with the shell is suspended until that program finishes it execution.

For some programs that may run for hours, you may want to keep it running in the background: **`<program> &`** to run a program as a background process

### Pause/Kill signals to a Foreground Process

- a running foreground process can be terminated by sending it a SIGINT (Signal Interrupt) with Ctrl-c
- a running foreground proces can be paused by sending it a SIGTSTP (Signal Terminal Stop) signal with Ctrl-z

- `kill {pid}`
- `pkill {pName}`

### Parent process

Every process is created by a parent process

1. the parent process uses the `fork` system call to create a clone of itself
   - when `fork()` is successful, it returns:
     1. child PID is returned to the parent
     2. 0 is returned to the child
   - when `fork()` fails, no child process is created and -1 is returned to the parent
2. the clone is identical to the current process except its process id and parent process id
3. the new process then loads and executes the desired program
