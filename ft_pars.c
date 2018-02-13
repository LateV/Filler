#include "filler.h"

void	ft_pars(char *line, t_filler **filler)
{
	if (line[10] == '1')
	{
		(*filler)->mpos = 'o';
		(*filler)->mpos_2 = 'O';
		(*filler)->epos = 'x';
		(*filler)->epos_2 = 'X';
	}
	else if (line[10] == '2')
	{
		(*filler)->mpos = 'x';
		(*filler)->mpos_2 = 'X';
		(*filler)->epos = 'o';
		(*filler)->epos_2 = 'O';
	}
	(*filler)->best_i = 0;
	(*filler)->best_j = 0;
	(*filler)->sum_a = 2147483647;
	(*filler)->sum = 0;
}
