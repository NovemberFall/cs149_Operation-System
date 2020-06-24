## Mechanism: Limited Direct Execution

- In order to virtualize the CPU, the operating system needs to somehow share 
  the physical CPU among many jobs running seemingly at the same time. The basic idea is
  simple: run one process for a little while, then run another one, and so forth. 
  By **time sharing** the CPU in this manner, virtualization is achieved.


![](img/2020-06-23-20-38-26.png)

![](img/2020-06-23-20-40-15.png)

---
![](img/2020-06-23-20-42-35.png)
- B
  
---
![](img/2020-06-23-20-43-20.png)
- A

---
![](img/2020-06-23-20-44-37.png)
- C, is false, because you can attempt the most trivialized instructions from the 
  user mode, that is fine, but the computer is going to switch from user mode to 
  the kernel mode. For example, if you make a system called like `open a file` or
  `write to a file` that's going to involve switching from the user to the kernel
  mode.


---
## Problem 2: How to switch between processes
- How can the OS regain(恢复) control of the CPU so that it can switch between 
  processes?
  -  A cooperative Approach: Wait for system calls
  -  A Non-Cooperative Approach: The OS takes control

#### A cooperative(合作的) Approach
![](img/2020-06-23-20-56-50.png)

![](img/2020-06-23-20-57-18.png)

![](img/2020-06-23-20-59-36.png)

![](img/2020-06-23-21-01-42.png)

![](img/2020-06-23-21-13-42.png)

![](img/2020-06-23-21-45-58.png)
---

![](img/2020-06-23-21-46-53.png)

- B

---
## A Non-Cooperative Approach: The OS taks control

![](img/2020-06-23-21-50-30.png)

![](img/2020-06-23-21-52-03.png)

![](img/2020-06-23-21-54-04.png)

## Context switch

![](img/2020-06-23-21-55-24.png)

![](img/2020-06-23-21-56-09.png)
- B

![](img/2020-06-23-21-57-06.png)
- 4
---

##  Concurrency 并发
![](img/2020-06-23-22-00-43.png)

![](img/2020-06-23-22-00-56.png)
- D

---
![](img/2020-06-23-22-02-29.png)
- B
