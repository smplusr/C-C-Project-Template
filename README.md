# c-cpp-project-template
Template for C and C++ projects.

---------------------------------------------------------------------

FILE ARCHITECTURE:

>    origin/
>       |
>       |               _               _
>       |---------------|---------------|
>       |               |               |
>       V               V               V
>      src/           build/           bin/
>       |               |               |
>       |               |               V
>       |               |             a.out
>       |               |               
>       |               |               
>       |               |               _
>       |               |---------------|
>       |               |               |
>       |               V               V
>       |   compile-source.bin    compile-headers.bin
>       |
>       |
>       |               _
>       |---------------|
>       |               |
>       V               V
>     main.c          mods/
>                       |               _
>                       |---------------|
>                       |               |
>                       V               V
>                     misc/           libs/
>                       |               |
>                       |               |
>                       |               V
>                       |             pch.h
>                       |
>                       |               _
>                       |---------------|
>                       |               |
>                       V               V
>                     elc.h           rcp.h

---------------------------------------------------------------------

INFO:

> All header files are precompiled in the linux-build fork of the project.
> Both elc.h and rcp.h are imported modules from the c-cpp-utilities project.

> The src/ folder contains all the sources and headers used in a project.
> The mods/ folder contains all the modules.
> The misc/ folder contains miscalenous modules, such as elc.h and rcp.h.
> The libs/ folder contains pch.h, the declaration of inclusion and headers.

> The build/ folder contains instructions for the rcp.h module.

> The bin/ folder contains the compiled binary of the program.
