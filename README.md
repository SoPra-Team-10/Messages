[![Build Status](https://travis-ci.org/SoPra-Team-10/Messages.svg?branch=master)](https://travis-ci.org/SoPra-Team-10/Messages)
# Messages
The C++ Messages component.

## Installing
In the root directory of the  project run cmake to generate a Makefile by running
```
cmake .
```
next compile the program by running
```
make
```
finally install the program by running
```
sudo make install
```
the library can now be included using

```
#include <SopraMessages/Filename>
```
with `Filename` beeing one of the header files without their relative path.

and linked using

```
-lSopraMessages
```
