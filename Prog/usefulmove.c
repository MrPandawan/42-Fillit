/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefulmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:27:20 by svilau            #+#    #+#             */
/*   Updated: 2016/04/10 22:45:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		s_compare(char c1, char c2)
{
	return (((65 <= c1 && c1 <= 90) && c2 == '#') ||
			((65 <= c2 && c2 <= 90) && c1 == '#') ||
			(c1 == '.' && c2 == '.') ||
			(c1 == '\n' && c2 == '\n'));
}

int		ft_smartcmp(char *s1, char *s2)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (!(s_compare(s1[i], s2[i])))
		{
			j = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (j);
		}
		i++;
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			j = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (j);
		}
		i++;
	}
	return (0);
}

void	swap_c(char *c1, char *c2)
{
	char aux;

	aux = *c1;
	*c1 = *c2;
	*c2 = aux;
}

void	swap_array(char ***a1, char **a2, int y, int x)
{
	int i;

	i = 0;
	if (*a2 == NULL)
	{
		*a1 = NULL;
		return ;
	}
	*a1 = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		(*a1)[i] = (char *)malloc(sizeof(char) * 5);
		i++;
	}
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			(*a1)[y][x] = a2[y][x];
			x++;
		}
		y++;
	}
}
