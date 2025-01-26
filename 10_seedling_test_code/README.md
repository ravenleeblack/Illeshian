# Illeshian Compiler - Source Code Tests

If you are going through the tests. Right now you have to delete the temp files and the .asm before you can use ./seed
to run another file. If you dont then there be previous stuff in the temp getting carried over that will make your nasm
assembling fail with error due to duplication. I will get around to making it properly delete the previous data in the 
temp eventually. IF you dont want to manaually clean then re-running make clean make all will do it for you but that
kind of sucks too having to re-make before every assemble.


## Test One: Proper program exit
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

## Test Two: Calculate strand length
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

## Test Three: Subroutines / local labels with local block labels
```
In lesson 3 we introduce the ability to call a sub routine or a local function. While in the local function we 
pass some arguments, then jump to a next_char local block label in order to do a loop that will get all the chars
in the test strand we want to write to the console. If its a global or local label we call it. If its global or local
block we jump to it. So in order for this too work if its a global or local label then in the footer we use 
pass_arg: eax;   or whatever register is being popped. If its a global or local block then we in the footer we use
pass_arg: num_value[0];  it just means return zero or nothing. This might come in handy when we actually get to the point
of writing our own machine language opcodes so we want to already have some things introduced beforehand.


/*test three:*/
nasm -f elf32 -o test_03.o test_03.asm
ld -m elf_i386 -o seed2 test_03.o
./seed2
```

