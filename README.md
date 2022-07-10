# SFML template project
A project example for SFML C++ applications on Linux and Windows. Detailed installation 
instructions. Just implement `Model::render()` and you will see it on your screen.

## Features
* Simple config from `config.json`
* Easily extendable with live keyboad input, own render function
* FPS display
* MVC pattern
* `Makefile` re-usable for other projects, only re-compiles modified sources

## Try out yourself:

### Install SFML

- [Download SFML](https://www.sfml-dev.org/download.php)
- Copy **the content** of include directory (SFML) to `src/` (in this case it's the same for Linux and Windows)  
- From `bin/` copy files (dynamic link libraries) to `src/`  
- Copy `lib/` to `lib/windows/` or `lib/linux/`  
(I copied this from my [raytracing project](https://github.com/markus-brln/ComputerGraphicsCompetition2021),
so the folders are a little different)
![librarySetup](https://user-images.githubusercontent.com/56026631/112718740-39a24680-8ef5-11eb-91f4-1e59d65bbe47.png)


### Linux (Ubuntu):

I only have experience with Ubuntu, here are some ways of how you can compile 
the project yourself that may or may not apply to other distros.

#### 1. Compile the program using g++

   in scr/ execute:  

```
g++ -o main -std=c++2a -I. -L lib/linux  \
*.cc controller/*.cc utils/*.cc model/*.cc viewsf/*.cc \
-lm -lsfml-graphics -lsfml-window -lsfml-system -fopenmp
```
   Compiler flag explanation:    
   - `-std=c++2a` Specify C++ standard to use
   - `-L lib/linux` Search the library named library when linking.
   - `-lsfml-graphics -lsfml-window -lsfml-system` Flags that SFML library requires, see [here](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).
   - `-fopenmp` Multithreading with OpenMP, see `#pragma` directive in `Model::render()`


#### 2. What I did when developing

   1. Install SFML for your own projects  
   ```sudo apt-get install libsfml-dev```  
   1.1 Install gnu make, if necessary:  
   ```sudo apt-get install build-essential```

   2. Descend into `src/`

   3. Build the executable:  
`make [-jX]`  
where X is the amount of jobs, for example equal to your CPU core count.
The Makefile already contains the compile flags mentioned above. It is written such that only 
modified sources are recompiled.  
   4. Run executable:  
      `./main`
   5. Remove SFML (when you want to clean up):  
`sudo apt-get remove libsfml-dev`

### Windows 10

1. Install Mingw 8.1.0 compiler if you don't have a compiler yet.  
   1.1 [Download Mingw installer](https://sourceforge.net/projects/mingw-w64/)  
   1.2 Follow Mingw [install instructions](https://code.visualstudio.com/docs/cpp/config-mingw)  
   1.3 Don't forget to switch to x86_64 architechture  
   1.4 Don't forget to add Mingw's bin folder to PATH, as described in 1.1

2. Compile  
   In `scr/` execute (note the `lib/windows` instead of `lib/linux`):  
```
g++ -o main.exe -std=c++2a -I. -L lib/windows  \
*.cc controller/*.cc utils/*.cc model/*.cc viewsf/*.cc \
-lm -lsfml-graphics -lsfml-window -lsfml-system -fopenmp
```

   Compiler flag explanation:    
   - `-std=c++2a` Specify C++ standard to use
   - `-L lib/windows` Search the library named library when linking.
   - `-lsfml-graphics -lsfml-window -lsfml-system` Flags that SFML library requires, see [here](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).
   - `-fopenmp` Multithreading with OpenMP, see `#pragma` directive in `Model::render()`

