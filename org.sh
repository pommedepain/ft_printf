faire en sorte que si on touche au point h, le make tente de recompiler.


Once a suitable makefile exists, each time you change  some  source  files, 
this simple shell command: "make" suffices to perform all necessary 
recompilations.

make updates a target if it depends on prerequisite files that have been modified 
since the target was last modified, or if the target does not exist.


  -W  file,   --what-if=file,   --new-file=file,
       --assume-new=file
            Pretend that the  target  file  has  just
            been  modified.   When  used  with the -n
            flag, this shows you what would happen if
            you  were  to  modify that file.  Without
            -n, it is almost the same  as  running  a
            touch  command  on  the given file before
            running make, except that  the  modifica-
            tion time is changed only in the imagina-
            tion of make.
