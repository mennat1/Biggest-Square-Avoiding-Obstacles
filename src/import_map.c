#include "biggest_square.h"

char symbols_arr[3];/*symbols_arr[0] => vacant, symbols_arr[1] => obstacle, symbols[2] => full*/
int	n_of_lines;
int n_of_cols;
int map_size_in_bytes;

/*FUNCTION #1*/
void import_map_from_file(char *file_name)
{
	char *map_ptr = NULL;
	int	fd, map_index = 0, symbols_counter = 0;
	char buff;
	off_t file_size_in_bytes, first_line_size_in_bytes = 0;
	fd = open(file_name, O_RDONLY);
	if(fd == -1)
	{	
		put_str("Cant open file\n");
		return;
	}
	file_size_in_bytes =  find_file_size(fd, file_name);
	while(read(fd, &buff, 1))/*Read the whole file byte by byte*/
	{
		if(symbols_counter == 3)
		{	/*If we finished reading the map symbols*/
			if(buff != '\n')/*There must be a '\n' at the end of the line*/
			{
				put_str("INVALID MAP ERROR #1\n");
				return;
			}
			first_line_size_in_bytes++;
			map_size_in_bytes = file_size_in_bytes - first_line_size_in_bytes;
			if(map_size_in_bytes % n_of_lines){/*Lines must be of equal length*/
				put_str("INVALID MAP ERROR #2\n");
				return;
			}else{
				n_of_cols = map_size_in_bytes / n_of_lines;
			}
			map_ptr = (char *)malloc(sizeof(char)*(map_size_in_bytes+1));
			*(map_ptr + map_size_in_bytes) = '\0';
			symbols_counter++;
			continue;/*i.e do not save the '\n' of the first line*/
		}
		if(buff >= '0' && buff <= '9')
		{	/*Read number of lines*/
			first_line_size_in_bytes++;
			n_of_lines *=10;
			n_of_lines += (buff - 48);
		}	
		else if(symbols_counter < 3)
		{	/*Read vacant, obstacle and full characters*/
			symbols_arr[symbols_counter] = buff;
			symbols_counter++;
			first_line_size_in_bytes++;
		}else
		{	/*Read the map*/
			*(map_ptr + map_index) = buff;
			map_index++;
		}
	}
	close(fd);
	find_biggest_square(map_ptr);
}


/*FUNCTION #2*/
void find_biggest_square(char *map_ptr)
{
	int bsq_side_length = 0, bottom_right_index_of_the_bsq = 0, index = 0;
	char vacant_char = symbols_arr[0], obstacle_char = symbols_arr[1];
	int top_index, left_index, top_left_index, top_int, top_left_int, left_int, result_int;
	char top_char, top_left_char, left_char, result_char;
	char *adjacent_map_ptr = (char *)malloc(sizeof(char)*(map_size_in_bytes + 1));
	*(adjacent_map_ptr + map_size_in_bytes) = '\0';
	while(*(map_ptr+index) != '\0')
	{
		if(*(map_ptr+index) == '\n'){
			*(adjacent_map_ptr+index) = '\n';
		}else if((index < n_of_cols) || ((index % n_of_cols) == 0)){//first row or first column
			if(*(map_ptr + index) == vacant_char)
			{
				*(adjacent_map_ptr + index) = '1';
				if(bsq_side_length == 0){
					bsq_side_length = 1;
					bottom_right_index_of_the_bsq = index;
				}
			}else if(*(map_ptr+index) == obstacle_char){
				*(adjacent_map_ptr+index) = '0';
			}else{
				put_str("INVALID MAP ERROR #3\n");
				return;
			}
		}else{
			top_index = index - n_of_cols;
			top_left_index = top_index - 1;
			left_index = index - 1;
			if(*(map_ptr + index) == obstacle_char){
				*(adjacent_map_ptr+index) = '0';
			}else if(*(map_ptr + index) == vacant_char){
				top_char = *(adjacent_map_ptr+top_index);
				left_char = *(adjacent_map_ptr+left_index);
				top_left_char = *(adjacent_map_ptr+top_left_index);
				top_int = top_char - '0';
				top_left_int = top_left_char - '0';
				left_int = left_char - '0';
				result_int = min_of_three(top_int, top_left_int, left_int) + 1;
				if(result_int > bsq_side_length)
				{
					bsq_side_length = result_int;
					bottom_right_index_of_the_bsq = index;
				}
				result_char = result_int + '0';
				*(adjacent_map_ptr + index) = result_char;
			}else{
				put_str("INVALID MAP ERROR #4\n");
				return;
			}
		}
		index++;
	}
	free(adjacent_map_ptr);
	draw_bsq(map_ptr, bottom_right_index_of_the_bsq, bsq_side_length);

}

/*FUNCTION #2*/
void draw_bsq(char *map_ptr, int bri, int bsq_side_length)
{
	char *final_map_ptr = (char *)malloc(sizeof(char)*(map_size_in_bytes+1));
	char *traversing_ptr = final_map_ptr;
	*(final_map_ptr + map_size_in_bytes) = '\0';
	int index = 0;
	int tri = bri - (bsq_side_length - 1) * n_of_cols;
	int tli = tri - bsq_side_length + 1;
	int r1 = tli / n_of_cols;//ex: 13/12=1
	int r2 = bri / n_of_cols;//ex: 91/12=7
	int c1 = tli % n_of_cols;//ex: 13%12=1
	int c2 = bri % n_of_cols;//ex: 91%12=7
	int index_row, index_col;
	while(*(map_ptr + index) != '\0'){
		index_row = index / n_of_cols;
		index_col = index % n_of_cols;
		if((index_row>=r1)&&(index_row<=r2)&&(index_col>=c1)&&(index_col<=c2)){
			*(final_map_ptr + index) = symbols_arr[2];//full character
		}else{
			*(final_map_ptr + index) = *(map_ptr + index);
		}
		index++;
	}
	while(*traversing_ptr != '\0'){
		put_char(*traversing_ptr);
		traversing_ptr++;
	}

	free(map_ptr);
	free(final_map_ptr);
}

