# AntiMatter Maze (Lab)
## What is this about ? 
Hello, I'm Alp and this is my Antimatter Maze Game.
This is a semester project which was assigned during the **Structural Programming** Lecture.
> (3rd Semester , Yildiz Technical University/Istanbul)

Project is mainly aims to "**_file handling_**" , "**_recursive functions (automatic gameplay mode)_**" and "**_project structure with multiple files_**" in **_C_** language.

.
.

## Disclaimer
! *Before you run the .exe file it's suggested that you run make file and create a new .exe* ! 
! *In the game menu you should choose a map before starting the game* !
 


## How to run makefile
1- Change current directory to ./antimatter-maze-game/src   via: 
```console
cd ./antimatter-maze-game/src
```
2- Create **_project.exe_** file using makefile via: 
```console
make -f MakeFile
```
! Warning the code may differ because of different **make.exe** names, if above doesn't work try : 
```console
mingw32-make -f MakeFile
```
3- Execute project.exe by : 
```console
.\project.exe
```

## About Folder Structure
- **_"src"_**  folder contains the main source codes of the game itself.
- **_"data"_** contains the usr.bin file which holds the user datas ; username , password , name , lastname.
- **_"maps"_** contains maps or gamefields. When game is started they are loaded initally. Files should be formatted properly.
> True formatting : First Line of file should only contain gamefield size (e.g. **5x6**) + newline char at the end.
> 
> The rest should only contain the gamefield's tiles - C is out/finish , K-Blackhole , P-p Proton and anti-Proton , E-e anti-Electron and Electron.
> 
> 1 for walls , 0 for empty tales. X is the user's start point.
.
.
## Gameplay
Game's purpose is to collect matters and find the way out (C tile).
At the end you'd rewarded with matters in your pocket.

Every anti-Matter pairs would react together and destroy theirselves. (P and p or E and e)

Your aim is to Collect anti-Electron and Proton to create Hydrogen.

You can let the computer play for you / Auto Mode but it won't guarentee the win .

## Auto Gameplay
You can set autogameplay enabled in the menu and start the game. It tries to find his way out avoiding getting captured by blackholes.




## Difficulty
Changes the moves user's have. If game completed in hard-mode user's points multiplied by 1.5 .
