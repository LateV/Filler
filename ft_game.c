#include "filler.h"

int		ft_ch_en(int n, int m, t_filler **filler)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (*filler)->p_h)
	{
		while(j < (*filler)->p_w)
		{
			if ((*filler)->pi[i][j] == '*')
			{
				if ((i + n >= (*filler)->m_h || j + m >= (*filler)->m_w) ||
					(i + n < 0 || j + m < 0))
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return(1);
}

int 	ft_ch(int n, int m, t_filler **filler)
{
	int p;
	int i;
	int j;

	i = 0;
	j = 0;
	p = 0;
	while (i < (*filler)->p_h)
	{
		while(j < (*filler)->p_w)
		{
			if ((*filler)->pi[i][j] == '*')
			{
				if ((*filler)->map[i + n][j + m] == (*filler)->epos ||
					(*filler)->map[i + n][j + m] == (*filler)->epos_2)
					return (0);
			}
			if ((*filler)->pi[i][j] == '*')
			{
				if ((*filler)->map[i + n][j + m] == (*filler)->mpos ||
					(*filler)->map[i + n][j + m] == (*filler)->mpos_2)
					p++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return(p);
}

void		ft_try_p(int i, int j, t_filler **filler,int fd)
{
	if(!ft_ch_en(i, j, filler))
		return;
	if(ft_ch(i, j, filler) == 1)
	{
		ft_son(i , j, filler);
		if ((*filler)->sum_a > (*filler)->sum)
		{
			(*filler)->sum_a = (*filler)->sum;
			(*filler)->best_i = i;
			(*filler)->best_j = j;
			ft_putstr_fd("TTTTTTTTTTTTTTTTTT\n",fd);
			ft_putnbr_fd((*filler)->sum, fd);
			ft_putchar_fd('\n', fd);
			ft_putnbr_fd(i, fd);
			ft_putchar_fd('\n', fd);
			ft_putnbr_fd(j, fd);
			ft_putchar_fd('\n', fd);
			ft_putstr_fd("TTTTTTTTTTTTTTTTTT\n",fd);
		}
		(*filler)->sum = 0;
	}
}

void		ft_game(t_filler **filler,int fd)
{
	int i;
	int j;

	i = -(*filler)->p_h;
	j = -(*filler)->p_w;
	while(i < (*filler)->m_h)
	{
		while(j < (*filler)->m_w)
		{
			ft_try_p(i, j, filler, fd);
			j++;
		}
		i++;
		j = -(*filler)->p_w;
	}
	ft_putcoord((*filler)->best_i, (*filler)->best_j);
	(*filler)->best_j = 0;
	(*filler)->best_i = 0;
	// ft_putstr_fd("TTTTTTTTTTTTTTTTTT\n",fd);
	// ft_putnbr_fd(i + n, fd);
	// ft_putchar_fd('\n', fd);
	// ft_putnbr_fd(j + m, fd);
	// ft_putchar_fd('\n', fd);
	// ft_putstr_fd("TTTTTTTTTTTTTTTTTT\n",fd);
	// ft_putchar_fd('\n', fd);
}