# Illeshian Compiler - Source Code Tests


## Test One:
```
I am creating the seedling version tests based off https://asmtutor.com/. 

I started with lesson 2 in order to start converting seedling into nasm properly. Lesson 1 was about getting 
a Segmentation fault if you forgot to leave out the system call to end the program right. So I started at lesson 2 
and seedling now outputs lesson 2 nasm assembly and prints Hello, World! So if you are checking the site we will be
one tuterial off the whole time. Our lesson 1 is the sites lesson 2 and so forth.

In order to compile your own source tests in seedling:
make clean
make all 
./seed -o -t -d -n test_01.seed 

In order to assemble the seedling output which is nasm:
nasm -f elf32 -o test_01.o test_01.asm
ld -m elf_i386 -o seed2 test_01.o

We can now run the exectuable:
./seed2
```

## Test Two:
```
In lesson 2 we introduce the ability to jump to global block scope labels in order to take a new approach
to making the string. We compare each byte of the strand manually without declaring the size ourselves like
we did in lesson 1. In this one I had to add in hex literals for the strand. A compare, an increment, a sub,
more jump types. As of right now it all works and prints out a Hello, World. Testing strand! strand. 


/*test two:*/
nasm -f elf32 -o test_02.o test_02.asm
ld -m elf_i386 -o seed2 test_02.o
./seed2
```

