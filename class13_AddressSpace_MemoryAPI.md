## Address Space

![](img/2020-07-26-20-53-58.png)

![](img/2020-07-26-20-54-17.png)

---

![](img/2020-07-26-20-58-39.png)

---
![](img/2020-07-26-20-59-58.png)

![](img/2020-07-26-21-00-36.png)

![](img/2020-07-26-21-02-53.png)

---

![](img/2020-07-26-21-03-28.png)

![](img/2020-07-26-21-03-42.png)

---

![](img/2020-07-26-21-06-54.png)
- A

---

![](img/2020-07-26-21-09-57.png)

![](img/2020-07-26-21-17-44.png)

---

![](img/2020-07-26-21-18-26.png)

---


## Memory API

![](img/2020-07-26-21-38-17.png)
![](img/2020-07-26-21-38-28.png)


#### Heap access

![](img/2020-07-26-21-39-31.png)

![](img/2020-07-26-21-40-17.png)

- the problem is that after `int *ptr` declaration. This pointer has a random
  value. This pointer point to a random location in memory.
  it's assigning 10 and 22 random location in memory, which could be
  anywhere. Which means that you're accessing it's a segmentation fault, 
  which means your're accesing something outside of your memory space. 

---

![](img/2020-07-26-21-49-00.png)
![](img/2020-07-26-21-49-27.png)
![](img/2020-07-26-21-52-28.png)

![](img/2020-07-26-21-50-23.png)
![](img/2020-07-26-21-50-35.png)

![](img/2020-07-26-21-50-48.png)
![](img/2020-07-26-21-50-57.png)

![](img/2020-07-26-21-52-53.png)

---

## Issue

![](img/2020-07-26-21-53-41.png)
![](img/2020-07-26-21-54-18.png)
![](img/2020-07-26-21-54-37.png)
![](img/2020-07-26-21-56-27.png)

#### Memory Leak

![](img/2020-07-26-21-56-57.png)

![](img/2020-07-26-21-57-36.png)

#### Dangling Pointer

![](img/2020-07-26-21-58-41.png)













































