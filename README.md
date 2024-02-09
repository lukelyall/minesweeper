# Terminal Minesweeper
A simple console-based Minesweeper clone made with C++ and utilizing the ncurses library.
## ncurses
### Installation
To properly install ncurses for different systems, access the following link:
https://ostechnix.com/how-to-install-ncurses-library-in-linux/
This program was built using WSL (Ubuntu terminal) and due to this can be installed by running the following command:
```Linux
$ sudo apt install libncurses5-dev libncursesw5-dev
```
### Compilation
Once ncurses has been installed, the .cpp file can be compiled with the following command:
```Linux
$ g++ <program file> -lncurses -o <output file name>
```
The output file can then be run using the terminal.