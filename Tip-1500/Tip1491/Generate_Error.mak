# Nmake macros for building Windows 32-Bit apps

all: Genera~1.exe

# Update the resource if necessary

generic.res:generic.rc generic.h
    rc -r -fo generic.res generic.rc

# Update the object file if necessary

Genera~1.obj: Genera~1.cpp generic.cpp generic.h
    $(cc) $(cdebug) $(cflags) $(cvars) Genera~1.cpp

# Update the executable file if necessary, and if so, add the resource back in.

Genera~1.exe: Genera~1.obj generic.res
    $(link) $(linkdebug) $(guiflags) -out:Genera~1.exe Genera~1.obj generic.res $(guilibs) advapi.lib
