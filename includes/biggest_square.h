#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>


#ifndef BSQ_H
#define BSQ_H

void import_map_from_file(char *file_name);
void find_biggest_square(char *map_ptr);
void draw_bsq(char *map_ptr, int bri, int bsq_side_length);
int min_of_three(int x, int y, int z);
int min_of_two(int a, int b);
void put_char(char c);
void put_str(char *str);
off_t find_file_size(int fd, char *file_name);

#endif