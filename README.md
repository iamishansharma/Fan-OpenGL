# Fan-OpenGL

Assignment 2 by Ishan Sharma - 2016B2A70773P for Computer Graphics ISF311

Programming Language Used: C++;

So as required, I have developed the simulation of the wall fan.
As another object, I have made a simple table to go with it. 
This table has an openable drawer. See below on more details.

## Dependencies

Make sure you have C/C++ installed on your system.

1. This program was built and tested using a Ubuntu (Linux) OS only. 
2. Make sure to run the command `sudo apt-get install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev` to install all dependencies.

## Instructions to Compile and Run

1. Althought you could use the Makefile to compile and clean, 
but I have made a shell script that will clean, compile and run in just 1 command. 

2. Before that, make sure the shell script has permission to 
run for that please run the following command in the terminal - `sudo chmod u+r+x Fan.sh`
(Enter your password if prompted to).

3. Now simply run the command `./Fan.sh` to run the shell script.

IF YOU HAVE TOO MANY PROBLEMS RUNNING OR COMPILING, 
YOU CAN WATCH THE (VIDEO DEMO)[https://drive.google.com/file/d/1lw5KlCGdbaKqBWEhT4a5fmDKe55WIQZh/view?usp=sharing] OF THE PROJECT. 

## How to Interact

1. The `s` key starts the spinning of the fan blades.
2. the `t` key stops the spinning of the fan blades.
3. The `h` toggles the Lateral Movement of the fan. (Press `h` again to stop it)
4. The `u, d, l, r` moves the fan up, down, left and right respectively on the wall the fan is in.
5. The `o` key opens and closes the drawer of the table.
6. The `Esc, q and Q` keys can be used to quit the application.
7. The `x` key is used to move in the negative x perspective direction.
8. The `X` (Capital x) key is used to move in the positive x perspective direction. 
9. The `y` key is used to move in the negative y perspective direction.
10. The `Y` (Capital y) key is used to move in the positive y perspective direction. 
11. The `z` key is used to move in the negative z perspective direction.
12. The `Z` (Capital z) key is used to move in the positive z perspective direction. 