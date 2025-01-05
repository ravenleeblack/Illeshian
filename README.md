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
approach to ui elements in app building by using functions and function calls like:

  ![illeshian_ex](https://github.com/user-attachments/assets/082b088d-9ebe-4b8b-8d14-b484fae6daeb)

- Both Illeshian and Seedling are being designed with the idea of a new scope system:
  - Universal Scope - Anything that is not in a function.
  - Global Scope - The body of a first class function called a manager function or the parent or global function.
  - Global Block Scope - The body of data tools that reside in the global scope that are not in the local scope.
  - Local Scope - The body of a second class function. A second class function can be a normal function or a seedling function that allows us to natively write seedling in Illeshian.
  - Local Block Scope - The body of data tools that are in the local scope.

- Since both the Illeshian compiler and the Seedling Assembler are being designed with these new scopes it introduces alot of new features.
  - normal assemblers are section based. In seedling we seperate things by scope followed by a label then a colon to end. Then underneath the label we have that scope labels sections.
 ![seedling_ex](https://github.com/user-attachments/assets/f0e6125e-2fed-46b4-82d1-13beab76d695)

  - Since Illeshian gets compiled down into seedling, it does so, on a one to one basis. global to global and local to local. This means that
  since we have a seedling function in Illeshian that allows us to write seedling assembly code, when illeshian gets converted, since its a local scope
  then it converts to a local scope into seedling.
  - When creating libraries we use a manager function which is global. So when the linker brings in the library which will be a .mod file. Then it just
  adds it into the program like its just another global scope on the end. This makes relocation alot easier for the linker.




I am still working on everything and plan to create a linker named rootling later that supports .exe, .elf, and .elm files.

The Ill driver is the main program that handles the workflow. The ill takes in a file manager file with the extention .fm. The .fm takes in 
a series of headers and sources files that need to compiled and assembled. We use the file manager so we do not have to include headers in every 
source file. The irp takes the .fm file as input and preprocesses it before outputting a .i file for headers and a .p for source files. The comp 
which is the illeshian compiler will take these in as input. When the comp is finished it should produce a .seed file for the seedling assembler.

Right now alot of it works but I am in the process of trying to get the assembler to the point of bootstrap so that we can write the comp code gen
into seedling. 


