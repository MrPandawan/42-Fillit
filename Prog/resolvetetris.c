/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvetetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:55:52 by aanzieu           #+#    #+#             */
/*   Updated: 2016/04/11 22:22:21 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "ref_mino.h"

static char		get_block(char **mino)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (mino[y][x] != '.' && mino[y][x] != '\n')
				return (mino[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

static void		place(char ***fillit, char **mino, int x, int y)
{
	int		i;
	char	c;

	i = -1;
	c = get_block(mino);
	while (++i < 19)
	{
		if (ft_smartcmp(g_minos[i], matrix2char(mino)) == 0)
		{
			(*fillit)[y + (g_tetri[i][0])][x + (g_tetri[i][1])] = c;
			(*fillit)[y + (g_tetri[i][2])][x + (g_tetri[i][3])] = c;
			(*fillit)[y + (g_tetri[i][4])][x + (g_tetri[i][5])] = c;
			(*fillit)[y + (g_tetri[i][6])][x + (g_tetri[i][7])] = c;
			break ;
		}
	}
}

static int		verify(char **fillit, char **mino, int x, int y)
{
	int i;
	int size;
	int j;

	i = -1;
	size = ft_strlen(fillit[0]) - 1;
	while (++i < 19)
	{
		if (ft_smartcmp(g_minos[i], matrix2char(mino)) == 0)
		{
			j = 0;
			while (j < 8)
			{
				if (y + g_tetri[i][j] >= 0 && x + g_tetri[i][j + 1] >= 0
						&& y + g_tetri[i][j] <= size
						&& x + g_tetri[i][j + 1] <= size)
					j += 2;
				else
					return (0);
			}
			if (ONE == '.' && TWO == '.' && THREE == '.' && FOUR == '.')
				return (1);
		}
	}
	return (0);
}

static int		verify_and_place(char ***fillit, char **mino, int x, int y)
{
	if ((*fillit)[y][x] == '.')
		if (verify((*fillit), mino, x, y))
		{
			place(fillit, mino, x, y);
			return (1);
		}
	return (0);
}

int				solve(char ***fillit, t_input *tetris, int count, int y)
{
	int i;
	int x;

	if (tetris[0].data == NULL)
		return (1);
	i = -1;
	while (tetris[++i].data)
	{
		while ((*fillit)[y])
		{
			x = -1;
			while ((*fillit)[y][x += 1])
			{
				if (verify_and_place(fillit, tetris[i].data, x, y))
				{
					if (solve(fillit, rem_matrix(tetris, i, count), count, 0))
						return (1);
					else
						remove_tetri(fillit, get_block(tetris[i].data));
				}
			}
			y++;
		}
	}
	return (0);
}
