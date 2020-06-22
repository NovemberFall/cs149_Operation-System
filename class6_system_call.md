##

- O_CREAT
  - If the file exists, this flag has no effect except as noted under O_EXCL below. Otherwise, the file is created; 
    the user ID of the file is set to the effective user ID of the process; 
    the group ID of the file is set to  the group ID of the file's parent directory 
    or to the effective group ID of the process; 


- O_APPEND
  - If set, the file offset will be set to the end of the file prior to each write.