/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefultetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:27:20 by svilau            #+#    #+#             */
/*   Updated: 2016/04/11 22:19:28 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		char2matrix(char *str, char ***tetris)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			(*tetris)[y] = ft_strsub(str, i - 4, 5);
			y++;
		}
		i++;
	}
}

char		*matrix2char(char **str)
{
	int		y;
	char	*mino;

	y = 0;
	mino = (char *)malloc(sizeof(char ) * 21);
	mino[0] = '\0';
	while (y < 4)
	{
		ft_strcat(mino, str[y]);
		y++;
	}
	return (mino);
}

void		remove_tetri(char ***fillit, char c)
{
	int x;
	int y;

	y = 0;
	while ((*fillit)[y])
	{
		x = 0;
		while ((*fillit)[y][x])
		{
			if ((*fillit)[y][x] == c)
				(*fillit)[y][x] = '.';
			x++;
		}
		y++;
	}
}

void		find_replace(char **str, char find, char replace)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((*str)[i] == find)
			(*str)[i] = replace;
		i++;
	}
}

t_input		*rem_matrix(t_input *tetris, int pos, int count)
{
	int		i;
	t_input *cpy;

	i = 0;
	cpy = (t_input *)malloc(sizeof(t_input) * count + 1);
	while (tetris[i].data)
	{
		cpy[i].data = tetris[i].data;
		i++;
	}
	cpy[i].data = NULL;
	i = 0;
	while (cpy[i].data && i != pos)
		i++;
	if (i == pos)
	{
		while (cpy[i + 1].data)
		{
			swap_array(&cpy[i].data, cpy[i + 1].data, 0, 0);
			i++;
		}
		cpy[i].data = NULL;
	}
	return (cpy);
}
