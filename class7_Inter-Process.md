## Inter-Process Communication: Pipes and Memory mapped files (mmap)

![](img/2020-06-28-18-05-45.png)

- techniques for processes to communicate with one another: interprocess 
  communication (IPC).

![](img/2020-06-28-18-08-29.png)
- B
---

## Pipes

![](img/2020-06-28-21-11-42.png)

- To make a `pipe`, put a `vertical bar ()` on the command line between two 
  commands. When a program takes its input from another program, it performs 
  some operation on that input, and writes the result to the `standard output`. 
  It is referred to as a filter.

- [pipe | pipe function](https://novemberfall.github.io/Algorithm-FullStack/operation/pipe.html)


![](img/2020-06-28-21-35-25.png)
- B

---

![](img/2020-06-28-22-51-33.png)
- e
  - `uni-directional 意思是单向的`  
  - use can specify the size of buffer
  - c, d 也都是对的 
---

![](img/2020-06-28-22-59-27.png)
![](img/2020-06-28-23-01-48.png)

---
![](img/2020-06-28-23-11-09.png)
- C

- Recall: if parent doesn't use `wait()`, then child is going to end up like
  `zombie process`.

---

![](img/2020-06-28-23-14-54.png)
- C, if you remember what we saying about system calls, is that they give you 
  a higher level, so you can access things and bigger, so as long as you want
  to define a data structure in `kernel space`, it means that `pipe` has to be
  system call:
![](img/2020-06-28-23-19-43.png)
---
![](img/2020-06-28-23-20-16.png)
- AB

---
![](img/2020-06-29-00-11-07.png)


