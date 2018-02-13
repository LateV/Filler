/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:42:35 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:42:37 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_genchar(char c, int n)
{
	char	*str;

	if (n <= 0)
	{
		str = (char *)malloc(sizeof(char) + 2);
		str[0] = '\0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (n + 1));
	str[n--] = '\0';
	while (n >= 0)
		str[n--] = c;
	return (str);
}
