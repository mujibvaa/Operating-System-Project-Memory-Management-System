# Operating-System-Project-Memory-Management-System
OBJECTIVE
*Write a C program to simulate the following contiguous memory allocation techniques
a) Worst-fit b) Best-fit c) First-fit

DESCRIPTION
One of the simplest methods for memory allocation is to divide memory into several fixed-sized partitions. Each
partition may contain exactly one process. In this multiple-partition method, when a partition is free, a process is
selected from the input queue and is loaded into the free partition. When the process terminates, the partition
becomes available for another process. The operating system keeps a table indicating which parts of memory
are available and which are occupied. Finally, when a process arrives and needs memory, a memory section
large enough for this process is provided. When it is time to load or swap a process into main memory, and if
there is more than one free block of memory of sufficient size, then the operating system must decide which
free block to allocate. Best-fit strategy chooses the block that is closest in size to the request. First-fit chooses
the first available block that is large enough. Worst-fit chooses the largest available block.
