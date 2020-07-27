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

![](img/2020-07-26-22-01-18.png)

- the problem here is that when you're calling the function. This is going
  to allocate a new stack frame for the parameters that get passed in which 
  in this case is and enter the point `a`. And when this function completes. 
  That stack frame is not going to exist anymore. So essentially, `a` is 
  local variable for that function called.

## calloc()

![](img/2020-07-26-22-05-52.png)

![](img/2020-07-26-22-06-34.png)

![](img/2020-07-26-22-07-16.png)

---

![](img/2020-07-26-22-07-30.png)

![](img/2020-07-26-22-08-55.png)

---

![](img/2020-07-26-22-10-06.png)

- p1 has problem is that returning is a memory address to a local variable,
  when the function complete, the stack gets deleted, you're returning the
  address of x, but that variable x is a local variable that doesn't exist 
  anymore. so you return the address of x, x is gone.  
- p2, that problem is we have talked about previously. you have to call
  `malloc()` for `int *px`,  
- p3, this function is returning the address of pointer

---

![](img/2020-07-26-22-25-33.png)

![](img/2020-07-26-22-26-00.png)

![](img/2020-07-26-22-27-41.png)
































