# Terminal Minesweeper
![image](https://github.com/lukelyall/minesweeper/assets/109260451/3d525d5a-a7b6-4597-85bd-0a5e9e075088)   
A terminal-based Minesweeper clone made with C++ and utilizing the ncurses library. 
## Controls
The game uses the arrow keys to navigate the board, 'd' to reveal mines, 'f' to flag potential mines, and 'q' to exit. If a mine is revealed then the game ends.
## ncurses
### Installation
This program utilizes the curses/ncurses library. To properly install ncurses for different systems, access the following link:
https://ostechnix.com/how-to-install-ncurses-library-in-linux/
To install on Ubuntu run the following command:
```bash
$ sudo apt install libncurses5-dev libncursesw5-dev
```
### Compilation
Once ncurses has been installed, the .cpp file can be compiled with the following command:
```bash
$ g++ <program files> -lncurses -o <output file name>
```
**note**: for this program, the program files are main.cpp, board.cpp, logic.cpp, and settings.cpp.   
Once the compilation is complete, the output file can be used to play the game.
