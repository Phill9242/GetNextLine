# GetNextLine

The Get Next Line project (or GNL) introduce the concepts of memory leaks, static variables and file descriptor.

The main objective it's create a program that receive a file descriptor number as parameter and return the next line of this file. 
Every time the function it's called, we must return just one line, and nothing more. 
In the end of file the program must return "null" and properly free every memory allocated.


## Bonus part

In the bonus part we must deal with multiple File Descriptors and return the properly line of each one of them according to the received parameter.
