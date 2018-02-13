#include "filler.h"

void ft_rp(t_filler **filler)
{
	int i;
	char *line;
	
	i = 0;
	get_next_line(0, &line);
	(*filler)->p_h = ft_atoi(line + 5);
	(*filler)->pi = (char**)malloc(sizeof(char*) * (*filler)->m_h);
	while(i < (*filler)->p_h)
	{
		get_next_line(0, &line);
		(*filler)->pi[i] = ft_strdup(line);
		i++;
	}
	(*filler)->p_w = (int)ft_strlen((*filler)->pi[0]);
}

int ft_rmap(t_filler **filler,int fd)
{
	int 	i;
	char 	*line;

	i = 0;
	get_next_line(0, &line);
	ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
	if(ft_strstr(line, "Plateau"))
	{
		(*filler)->m_h = ft_atoi(line + 7);
		(*filler)->map = (char**)malloc(sizeof(char*) * (*filler)->m_h);
		get_next_line(0, &line);
		while(i < (*filler)->m_h)
		{
			get_next_line(0, &line);
			ft_putstr_fd(line, fd);
			ft_putchar_fd('\n', fd);
			ft_putchar_fd('\n', fd);
			// ft_putchar_fd(line[4], fd);
			// ft_putchar_fd('\n', fd);
			(*filler)->map[i] = ft_strdup(line + 4);
			i++;
				
		}
		ft_rp(filler);
		(*filler)->m_w = (int)ft_strlen((*filler)->map[0]);
		return(1);
	}
	return(0);
}
