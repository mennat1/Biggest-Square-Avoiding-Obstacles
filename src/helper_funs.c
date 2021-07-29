#include "biggest_square.h"

int min_of_three(int x, int y, int z)
{
	int min = min_of_two(x, min_of_two(y,z));
	return min;
}


int min_of_two(int a, int b) 
{ 
	return ((a <= b) ? a : b); 
} 


void put_char(char c)
{
	write(1, &c, 1);
}


void put_str(char *str)
{
	while (*str != '\0')
	{
		put_char(*str);
		str++;
	}
}


off_t find_file_size(int fd, char *file_name)
{
	struct stat buffer;
	fd = open(file_name, O_RDONLY);
	fstat(fd, &buffer);
	return (buffer.st_size);

}