#include "filler.h"

int		ft_inc(int n, int m, t_filler **filler)
{
	int i;
	int val;

	i = 1;
	if ((*filler)->m_w > (*filler)->m_h)
		val = (*filler)->m_w;
	else
		val = (*filler)->m_h;
	while(i < val)
	{
		if (m - i >= 0)
		{
			if ((*filler)->map[n][m - i] == (*filler)->epos || 
				(*filler)->map[n][m - i] == (*filler)->epos_2)
				return (i);
		}
		if (n - i >= 0 && m - i >= 0)
		{
			if ((*filler)->map[n - i][m - i] == (*filler)->epos || 
				(*filler)->map[n - i][m - i] == (*filler)->epos_2)
				return (i);
		}
		if (n - i >= 0)
		{
			if ((*filler)->map[n - i][m] == (*filler)->epos || 
				(*filler)->map[n - i][m] == (*filler)->epos_2)
				return (i);
		}
		if (n - i >= 0 && m + i < (*filler)->m_w)
		{
			if ((*filler)->map[n - i][m + i] == (*filler)->epos || 
				(*filler)->map[n - i][m + i] == (*filler)->epos_2)
				return (i);
		}
		if (m + i < (*filler)->m_w)
		{
			if ((*filler)->map[n][m + i] == (*filler)->epos || 
				(*filler)->map[n][m + i] == (*filler)->epos_2)
				return (i);
		}
		if (n + i < (*filler)->m_h && m + i < (*filler)->m_w)
		{
			if ((*filler)->map[n + i][m + i] == (*filler)->epos || 
				(*filler)->map[n + i][m + i] == (*filler)->epos_2)
				return (i);
		}
		if (n + i < (*filler)->m_h)
		{
			if ((*filler)->map[n + i][m] == (*filler)->epos || 
				(*filler)->map[n + i][m] == (*filler)->epos_2)
				return (i);
		}
		if (n + i < (*filler)->m_h && m - i >= 0)
		{
			if ((*filler)->map[n + i][m - i] == (*filler)->epos || 
				(*filler)->map[n + i][m - i] == (*filler)->epos_2)
				return (i);
		}
		i++;
	}
	return (i);
}

void	ft_son(int n, int m, t_filler **filler)
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
				(*filler)->sum = (*filler)->sum + ft_inc(i + n, j + m, filler);
			j++;
		}
		j = 0;
		i++;
	}
}
