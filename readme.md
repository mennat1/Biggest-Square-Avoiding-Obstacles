# Finding the biggest square in map, avoiding obstacles.

- The aim of this project is to find the biggest square on a map, avoiding obstacles.
- A file containing the map will be provided. It’ll have to be passed as an argument for the program.
- The first line of the map contains information on how to read the map:
		1. The number of lines on the map.
		2. The “vacant” character.
		3. The “occupied” character.
		4. The “full” character.

- The map is made up of “vacant” characters and “occupied” characters.
- The aim of the program is to replace “vacant” characters by “full” characters in order to
  represent the biggest square possible.
- In the case that more than one solution exists, we’ll choose to represent the square that’s
  closest to the top of the map, then the one that’s most to the left.

- Definition of a valid map:
	1. All line must have the same length.
	2. There's at least one line of at least one box.
	3. At each end of line, there’s a line break.
	4.  The characters on the map can only be those introduced in the first line.
	5.  In case of an invalid map, your program should display mapp error on the error output
	 		followed by a line break. Your program will then move on to the next map.
