# Illeshian Runtime Preprocessor - IRP

The irp takes in a file called the source.fm file, which is a file manager, file. The file manager handles all of the directives.
use - header files
link - source files
replace - replaces consts

After the irp processes the list of directives, it will open the header and source files, make a copy file, process the files then
output the copy with a new ending extension. The extension will either be .p for source files or .i for header files. These new files
get fed into the illeshian compiler.

