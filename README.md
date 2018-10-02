# `ccipher`
###### An utility to decrypt and encrypt plain ASCII text in several classical ciphers.

## Installation 
- Get prebuilt binaries from [Releases](https://github.com/42tm/ccipher/releases) page
- ...or build yourself an executable in the platform of your choice.

## Build
### Requirements
`ccipher` requires `cmake` and a C++11-compatible compiler to be available inside your `PATH` environment variable.
  
  To test whether you have it : 
  - Fire up a terminal.
  - Enter `cmake --version` to test CMake. On GNU/Linux it should yields a result like this :
    ```
    cmake version 3.12.1

    CMake suite maintained and supported by Kitware (kitware.com/cmake).
    ```
  - Enter `g++ -v` to test GCC suite. On GNU/Linux, you should see something like this :
    ```
    Using built-in specs.
    COLLECT_GCC=g++
    COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/8/lto-wrapper
    OFFLOAD_TARGET_NAMES=nvptx-none
    OFFLOAD_TARGET_DEFAULT=1
    Target: x86_64-linux-gnu
    Configured with:
    ...
    Thread model: posix
    gcc version 8.2.0 (Debian 8.2.0-5)
    ```
    
  - (Only if `g++` isn't there)
    
    Type `clang++ -v` or `clang++ --version` to check if Clang is available.
    It should yields things like
    ```
    clang version 6.0.1-6
    Target: x86_64-pc-linux-gnu
    ...
    ```
  - If you fail to successfully run any command of the above, see section "Fulfilling requirements" below.

### Compiling instruction  
- Fire up a terminal.
- Change the current directory to be the root of this repository.
  - `git clone https://github.com/42tm/ccipher` beforehand, if necessary.
- Make a directory there. Here I assume you used a directory called `build/`.
- Change current directory to it.
- Enter `cmake ..`.
  - If `cmake` succeeds, type `make` if you have GNU `make` installed.
  - Type `cmake --build` if you don't.

Now you should see an executable named `ccipher` inside your current directory
(or `ccipher.exe` in case you use Windows).

### Fulfilling requirements
- CMake : download from [here](https://cmake.org/download/).
- C++-11 compatible compiler : 
  - On Windows, try [Clang](http://releases.llvm.org/download.html) or [MinGW-w64](mingw-w64.org/doku.php/download).
  - On GNU/Linux, try any compiler you want.

## License
This program, including its source code, is licensed under the GNU General Public License, version 3.0.

This program uses a modified version of [`42tm/vigenere`](https://github.com/42tm/vigenere),
which is also licensed under GPL 3.0.
