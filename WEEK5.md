## File system organization: inode

A well formed file system is composed of three main components: 

### 1. the file
Is a collection of data blocks, on a storage device, containing the data of interest

### 2. **inode**: a structure assigned to eah file to store its metadata
- **Each file has an inode to store its metadata and locate the files's content**
- inodes are stored in a table, which is allocated when the filesystem is first created, which means there are fixed numbers of inodes in a file system.
    - in linux ext4, a default ratio of 1 inode per 16 KBs of total capacity is used.
- use `ls -i` to get the inode number information of files/directories
- use `df -i` to get usage information on inodes in a file system
  
### 3. directory structure: a table to store file names and inode numbers
- filenames and inode number are not stored in the inode. They are stored in directory structure
- use `ls -d` to inspect a directory (instead of listing its content)

| Filename | inode # |
|----------|----------|
| a.txt    | 33534535 |
| b.txt    | 34545221 |
| dir1     | 45455455 |
   
## File system organization: symbolic and hard links

When listed inside a directory, the l flag at the very first column of a long
format listing identifies them as links.


## Querying and manipulating processes

