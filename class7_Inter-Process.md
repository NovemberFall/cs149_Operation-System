## Inter-Process Communication: Pipes and Memory mapped files (mmap)

![](img/2020-06-28-18-05-45.png)

- techniques for processes to communicate with one another: interprocess 
  communication (IPC).

![](img/2020-06-28-18-08-29.png)
- B
---

## Pipes

- `Pipes` can be used only between processes that have a common `ancestor`. 
  Normally, a `pipe` is created by a `process`, that process calls `fork`, 
  and the `pipe` is used between the `parent` and the `child`.

![](img/2020-06-28-21-11-42.png)

- To make a `pipe`, put a `vertical bar ()` on the command line between two 
  commands. When a program takes its input from another program, it performs some operation on that input, and writes the result to the `standard output`. It is referred to as a filter.

