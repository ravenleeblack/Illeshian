# Illeshian is a suite of programs.
```
The Illeshian Driver - ill
The Illeshian Runtime Preprocessor - irp
The Illeshian Compiler - comp
The Seedling assembler - seed
The Rootling linker - hasnt been started yet - root
```

## Concepts about Illeshian worth considering to help build and finish the project:
- The Illeshian Language is buildt around the idea of a 2 tier function system. Its a procedural language that uses children functions that are not closures. This should allow us to replicate what classes can do and create a better 
approach to ui elements in procedural app building by using functions and function calls like:

  ![illeshian_ex](https://github.com/user-attachments/assets/082b088d-9ebe-4b8b-8d14-b484fae6daeb)

- Both Illeshian and Seedling are being designed around the idea of a new scope system:
  - Universal Scope, Global Scope, Global Block Scope, Local Scope, Local Block Scope

    So something like this:
  
      ![scope_ex](https://github.com/user-attachments/assets/01cd2dfa-37ce-4da6-b7ed-61e581d6be21)

    Will get converted down into something like this in seedling:
  
      ![scope_ex_one](https://github.com/user-attachments/assets/d86b0023-5b9f-4a54-8665-078199484696)

- Since both the Illeshian compiler and the Seedling Assembler are being designed with these new scopes it introduces alot of new features.
  - normal assemblers are section based. In seedling we are scope based. We seperate things by scope followed by a label. This would be called the header. Then underneath
  the label header, we have the body, the body is where we declare and assign the sections needed to write assembly code. These sections are tied to its scope and label.

    ![seedling_ex](https://github.com/user-attachments/assets/f0e6125e-2fed-46b4-82d1-13beab76d695)

  - Since Illeshian gets compiled down into seedling, it does so, on a one to one basis. global to global and local to local.
  So this in Illeshian:

    ![illeshian_ex](https://github.com/user-attachments/assets/082b088d-9ebe-4b8b-8d14-b484fae6daeb)

    Would get translated down into seedling as something along the lines of:
  
       ![convert_ex](https://github.com/user-attachments/assets/3a550446-7b62-4bf2-b889-280f859a3c97)
  
  - There also will be a seedling function in Illeshian at some point. Since the seedling function is local scope. When Illeshian gets converted, the seedling function, just becomes a local label.
  This allows seedling to be natively written in Illeshian.

  - When creating libraries we would use a manager function which is global. When the linker is trying to link libraries with our program all it has to do is bring in the library as if it was just another global scope label in the program. putting it on the end. This should make relocation alot easier for the linker.




I am still working on everything and plan to create a linker named rootling later that supports .exe, .elf, and .elm files.

The Ill driver is the main program that handles the workflow. The ill takes in a file manager file with the extention .fm. The .fm takes in 
a series of headers and sources files that need to compiled and assembled. We use the file manager so we do not have to include headers in every 
source file. The irp takes the .fm file as input and preprocesses it before outputting a .i file for headers and a .p for source files. The comp 
which is the illeshian compiler will take these in as input. When the comp is finished it should produce a .seed file for the seedling assembler.

# Main Goal Right Now:
- Getting the seedling assembler finished as a boot strap then self hosting program so that we can write the illeshian code gen in seedling. Since we are writing the program in c, the program takes in seedling as input and produces nasm as output. This means once we actually compile the c program into binary, we have an executable program, that executable program takes in seedling and produces nasm. We then have to rewrite the assembler in seedling instead of c now that we have a program that can assemble seedling to nasm. Since the first program produces nasm output, once we use that to assemble the new seedling assembler code, then we would have a self hosting seedling assembler.
- The current problem that I have right now is that other assemblers are section based and seedling is scope based with sections underneath. I had to create some nasm temp files, so that I collect all the
  seedling sections then write them into the right nasm section temp file, so that later we can bring all that information back in and have it write to the proper nasm files properly.

