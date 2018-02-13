#include "filler.h"

int main(void)
{
	int i;
	char	*line;
	t_filler *filler;

	int fd;
	fd = open("log1.txt",  O_RDWR);

	int fd2;
	fd2 = open("log2.txt",  O_RDWR);

	int fd3;
	fd3 = open("log.txt",  O_RDWR);
	
	i = 0;
	if(get_next_line(0, &line))
	{
		filler = malloc(sizeof(t_filler));
		// ft_putstr_fd(line, fd);
		ft_pars(line, &filler);
	}
	else
		return (0);
	while(ft_rmap(&filler,fd3))
	{
		while(i < filler->p_h)
		{
			ft_putstr_fd(filler->pi[i], fd);
			ft_putchar_fd('\n', fd);
			i++;
		}
		i = 0;
		while(i < filler->m_h)
		{
			ft_putstr_fd(filler->map[i], fd);
			ft_putchar_fd('\n', fd);
			i++;
		}
		i = 0;
		filler->sum_a = 2147483647;
		ft_game(&filler,fd2);
	}
	return (0);
}