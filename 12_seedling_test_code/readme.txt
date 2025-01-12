
/* I am doing the tests based off https://asmtutor.com/ the good oh nasm learning site. I 
started with lesson 2 in order to start converting seedling into nasm. Lesson 1 was about getting 
a Segmentation fault if you dont end the program with the right system call. So I started at lesson 2 
and seedling now outputs lesson 2 nasm assembly and prints Hello, World! the only issue with this one
is there is no hex literal to end the literal string. But yea we have a text one that assembles.*/


/*test one*/
nasm -f elf32 -o test_01.o test_01.asm
ld -m elf_i386 -o seed2 test_01.o
./seed2


