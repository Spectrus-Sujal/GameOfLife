# GameOfLife

## Description 
This project is a recreation of Conway's Game of Life where Cells in a grid simulate through various stages of life based on the number of neighboring cells

### Rules
1. Any living cell dies when it has less than 2 neighbors due to under population
2. Any living cell with 2 or 3 neighbors survies to the next generation
2. Any living cell dies when it has 4 or more neighbors due to over population
3. Any dead cell comes to life if it has exactly 3 neighbors due to reproduction


## Dependencies
This recreation of Game of Life is made using C++ and <a href="https://openframeworks.cc/">Open Frameworks</a> in Visual Studio 2022

### Importing this project
Steps to import this project to Visual Studio or VS Code
<ol>
 <li> Install Windows 2017-2022 version of <a href="https://openframeworks.cc/download/">Open Frameworks</a>
 <li> Extract the Zip file anywhere on your machine
 <li> Go into of_v0.11.2_vs2017_release\of_v0.11.2_vs2017_release\apps\myApps and create a new folder named gameOfLife
 <li> Download the project files from this repo into of_v0.11.2_vs2017_release\of_v0.11.2_vs2017_release\apps\myApps\gameOfLife
 <li> Open the .sln file
</ol>

## License
This project is unlicensed and is free to use for any who wish to do so
