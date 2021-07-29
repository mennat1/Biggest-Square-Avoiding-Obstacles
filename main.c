/*
● The aim of this project is to find the biggest square on a map, avoiding obstacles
● A file containing the map will be provided. It’ll have to be passed as an argument for your program
● The first line of the map contains information on how to read the map:
	○ The number of lines on the map
	○ The “vacant” character
	○ The “occupied” character
	○ The “full” character
● The map is made up of “vacant” characters and “occupied” characters
● The aim of the program is to replace “vacant” characters by “full” characters in order to
  represent the biggest square possible
● In the case that more than one solution exists, we’ll choose to represent the square that’s
  closest to the top of the map, then the one that’s most to the left.

● Definition of a valid map :
	○ All line must have the same length
	○ There's at least one line of at least one box
	○ At each end of line, there’s a line break
	○ The characters on the map can only be those introduced in the first line
	○ In case of an invalid map, your program should display mapp error on the error output
	  followed by a line break. Your program will then move on to the next map

*/



#include "biggest_square.h"

extern int n_of_cols, n_of_lines, map_size_in_bytes;
int	main(int argc, char **argv)
{
	int	i = 1;
	if(argc >= 2)
	{
		while(argv[i] != NULL)
		{
			n_of_lines = 0;
			n_of_cols = 0;
			map_size_in_bytes = 0;

			import_map_from_file(argv[i]);
			i++; //Check next map
			put_str("**********************************\n");
		}
	}
	else{
		put_str("map error\n");
	}
	return (0);
}
