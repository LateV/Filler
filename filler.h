#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include "libft/libft.h"

//
#include <stdio.h>
//

typedef struct	s_filler
{
	char	mpos;
	char	mpos_2;
	char	epos;
	char	epos_2;
	char	**map;
	char	**pi;
	int		p_w;
	int 	p_h;
	int 	m_w;
	int		m_h;
	int		**sonar;
	int		sum;
	int		sum_a;
	int		best_i;
	int 	best_j;
}				t_filler;

int 			ft_rmap(t_filler **filler,int fd);

void			ft_putcoord(int i, int j);
void			ft_game(t_filler **filler,int fd);
void			ft_pars(char *line, t_filler **filler);
void			ft_son(int n, int m, t_filler **filler);

#endif
