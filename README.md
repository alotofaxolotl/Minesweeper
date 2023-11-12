# CLI Minesweeper in C++
This is just a fun project to help me learn C++.

## How To Play

### Commands

The two commands that you use to play are `clear` and `flag`. If you think there is a mine in a given cell you should `flag` it. If you think it is safe, you should `clear` it. You can always unflag a cell with the `flag` command too, if you change your mind.

Whenever you input a command you will be prompted to enter an `x` and `y` coordinate for the cell you want to interact with.

### Rules and Tips

You **win** the game by clearing the whole grid without hitting a mine. You **lose** if you hit a mine.

Cells which you haven't cleared will have a `.` symbol. Cells that you have cleared with show a number indicating the number of mines it is adjacent to (this includes corners). If you flag a cell, it will be indicated by a `!` icon.

If you lose the game, the mines will be indicated by a `*` symbol.

## Building the Project

The project was written and built on Linux using g++-13. If you have g++-13 installed you can build the project by running `make` and the run the executable with `make run`.

The code *should* work on Windows and Mac as it doesn't use anything OS dependant, but it hasn't been written with them in mind.