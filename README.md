# Caesar_Cipher
This contains 2 separate applications, caesar.c and cth.c

##caesar.c
Prints all 26 different shifts of a Caesar chipher for one word entered by the user at a time.  It will not work if non-ASCII letters are used.

To compile, use the makefile included and simply type into the terminal:
```
make clean; make caesar
```
To run:
```
./caesar
```
Press Ctrl+C to quit.

##cth.c
Uses multithreads to print all the shifts of a Caesar chipher for one entire sentence entered by the user.  It works with any sentence with spacebars and punctuation in ASCII.

To compile, use the makefile included and simply type into the terminal:
```
 make clean; make cth
 ```
 To run:
```
./cth <N> <1+ words separated by spaces>
```
Where N is the number of shifts in [0, 25] to be applied to the sentence.  Typing 0 will print all possible shifts.
 
