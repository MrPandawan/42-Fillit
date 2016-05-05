/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:55:52 by aanzieu           #+#    #+#             */
/*   Updated: 2016/04/10 23:01:25 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_puterr(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

size_t	ft_count_minos(char *str)
{
	int x;
	int count;

	count = 0;
	x = 0;
	while (str[x] != '\0')
	{
		if (x % 21 == 0)
			count++;
		x++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	j;

	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	ft_strcpy(&dest[ft_strlen(dest)], src);
	return (dest);
}

void	print_matrix(char **str)
{
	int y;

	y = -1;
	while (str[++y])
	{
		write(1, str[y], ft_strlen(str[y]));
		write(1, "\n", 1);
	}
}
