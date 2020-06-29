## System Calls and File I/O

- O_CREAT
  - If the file exists, this flag has no effect except as noted under O_EXCL below. Otherwise, the file is created; 
    the user ID of the file is set to the effective user ID of the process; 
    the group ID of the file is set to  the group ID of the file's parent directory 
    or to the effective group ID of the process; 


- O_APPEND
  - If set, the file offset will be set to the end of the file prior to each write.


##  What are system calls?

![](img/2020-06-23-22-13-21.png)

![](img/2020-06-23-22-13-33.png)


## Why study the I/O system calls?

- I/O system calls:
  - form the basis of file I/O
  - are the foundation of virtually all communication on Linux.
- Recall: In all variations of Linux, because in Unix based operation systems
  Everything is a file. So everything that you're doing a Unix based operating
  systems, a file and represented by files. Thus, I/O are very important

---
![](img/2020-06-23-22-19-34.png)
- A

---
![](img/2020-06-23-22-20-09.png)
- A , this question is tricky, when you first execute a C program the CPU is 
  initially in user mode. And it only enters kernel mode when makes a system call
  so kernel mode is not the default mode of execution. 

---
![](img/2020-06-23-22-25-35.png)
- B  ; behalf(代表)

---
![](img/2020-06-23-22-26-42.png)
- A

---

![](img/2020-06-23-22-30-05.png)
![](img/2020-06-23-22-30-15.png)
---

![](img/2020-06-23-22-30-32.png)
- b
---

![](img/2020-06-23-22-31-38.png)
- C
---

![](img/2020-06-23-22-44-02.png)
![](img/2020-06-23-22-44-26.png)

- Note: 0644, everyone belongs in a group in Unix based operating system and what is
  0644, means is that owner will have permissions have read and write.

![](img/2020-06-23-22-53-34.png)
- a,  In memory, we have the table of `file descriptor`, is pointing to a 
  `file table entry` which contains file offset. And it also points to `V-node`
  i-node is on the disk, not in memory. 

![](img/2020-06-23-23-27-06.png)

---

![](img/2020-06-23-23-28-32.png)
- a
---

## File Sharing


![](img/2020-06-23-23-29-34.png)
#### fork() and open()
- after `fork()` call being made, child is sleeping for a while, then both parent
  and child open the same file, so the same file can be opened by both and then
  they both write some sequence of characters into the file.
  - then its process goes to `sleep()`, which is a system call can be useful for
    assignment 3, this just mean that `close()` is going to wait for a while 
    before it continues.
  - they were writing the same things into the same file. If two processes write
    same characters at the same time, it could be overwritten. 
- 这里最重要的一点是，child 并没有得到current offset的copy, 就算每一次写东西进文件，
  parent and child 没有分享offset, 最终导致写的东西被互相覆盖

```c++
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    char c;
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    const char *pathname = "fork-then-open.out";
    if (fork() == 0)
        sleep(1);
    fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);

    for (c = 'A'; c < 'A' + 5; c++) {
        write(fd, &c, 1);
        sleep(2);
    }

    close(fd);
    return 0;
}

/* 
ABCDE
 */
```

### another example of file sharing:

![](img/2020-06-23-23-35-18.png)

#### open(), then fork()

- Now, in this case open the file, opening a file then forking so first you open 
  a file and then you fork, all of `file descriptors` got copied into the child.
  so both a parent and the child have identical `file descriptors`. Because the
  offsets into the file set by parent and child. When parent increments the 
  offset that offset will be mirrored in the child process.

- so the offset when it's changed in parent. It's also changed for the child 
  because both parent and child pointing to the same data structures and they
  share the same offset.
- 这里最重要的一点是，child 得到current offset的copy from parent, parent and child
  both point to same data strucutures and the share same offset.
  - And every time either parent or child was writing something. it was also 
    increment in the current position in the file. so you get all characters
    repeated twice. One from parent and one from child.

```c++
int main()
{
    char c;
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    const char *pathname = "open-then-fork.out";
    fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (fork() == 0)
        sleep(1);

    for (c = 'A'; c < 'A' + 5; c++) {
        write(fd, &c, 1);
        sleep(2);
    }

    close(fd);
    return 0;
}

/* 
AABBCCDDEE
 */
```

---
![](img/2020-06-24-00-06-34.png)
- C 

---

![](img/2020-06-24-00-13-36.png)
- b
  - `read, write, execute` mode

---

![](img/2020-06-24-00-17-40.png)
- c

---
![](img/2020-06-24-00-18-35.png)
- d, handing system calls, it will return 0, means success and -1 means failure.

---

## lseek

![](img/2020-06-24-00-22-43.png)

- [system call lseek(), read(), write()](https://novemberfall.github.io/Algorithm-FullStack/operation/redirection.html)


![](img/2020-06-28-16-05-48.png)
- d


![](img/2020-06-28-16-06-41.png)
- B, let's say you don't know how big your file is from the beginning, but you 
  just know that you want to set it somewhere relative to the end of the file and
  which flag would you use

---

![](img/2020-06-28-16-11-32.png)
- a


![](img/2020-06-28-16-16-02.png)
- b

![](img/2020-06-28-16-19-36.png)
- A, 'd' is printing out, since `lseek(fd, 0, 0)`, set position to be 0, 
  文件的开始位置，所以 `s` 被 `d` 覆盖



![](img/2020-06-28-16-27-00.png)
- c

![](img/2020-06-28-17-17-10.png)

![](img/2020-06-28-17-17-24.png)
- b

---
![](img/2020-06-28-17-18-13.png)
- d

---
![](img/2020-06-28-17-42-25.png)

- [dup()/ dup2() explantaion:](https://novemberfall.github.io/Algorithm-FullStack/operation/dup.html)
