/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chektetric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:23:40 by aanzieu           #+#    #+#             */
/*   Updated: 2016/04/30 12:51:07 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "ref_mino.h"

void		upleft(char ***mino, char **backup, char *str, int moves)
{
	int		x;
	int		y;

	y = -1;
	swap_array(&backup, *mino, 0, 0);
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (ft_strcmp(str, "left") == 0 && backup[y][x - 1] == '.'
					&& x - 1 >= 0 && backup[y][x] == '#')
			{
				moves += 1;
				swap_c(&backup[y][x], &backup[y][x - 1]);
			}
			else if (ft_strcmp(str, "up") == 0 && y - 1 >= 0
					&& backup[y - 1][x] == '.' && backup[y][x] == '#')
			{
				moves += 1;
				swap_c(&backup[y - 1][x], &backup[y][x]);
			}
		}
	}
	moves == 4 ? swap_array(&(*mino), backup, 0, 0) : 0;
}

int			check_void_line(char **str, char axe, int cord)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (axe == 'x')
		while (x < 4)
		{
			if (str[cord][x] != '.')
				return (0);
			x++;
		}
	else if (axe == 'y')
		while (y < 4)
		{
			if (str[y][cord] != '.')
				return (0);
			y++;
		}
	else
		return (0);
	return (1);
}

static int	checkmino_shape(char *str, char ***tetris)
{
	int		i;
	char	*tmp;
	char	**backup;

	backup = NULL;
	i = -1;
	char2matrix(str, &(*tetris));
	while (check_void_line((*tetris), 'x', 0))
		upleft(&(*tetris), backup, "up", 0);
	while (check_void_line((*tetris), 'y', 0))
		upleft(&(*tetris), backup, "left", 0);
	tmp = matrix2char((*tetris));
	i = -1;
	while (++i < 19)
		if (ft_strcmp(g_minos[i], tmp) == 0)
			return (1);
	return (0);
}

static int	checkmino(char *str)
{
	int i;
	int vide;
	int mino;

	i = -1;
	vide = 0;
	mino = 0;
	while (str[++i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			mino++;
		if (str[i] == '.')
			vide++;
	}
	return (i == 20 && vide == 12 && mino == 4);
}

void		check_transform(char *str, int index, char ***data)
{
	int y;

	y = 0;
	if (!(checkmino(str)))
		ft_puterr();
	if (!(checkmino_shape(str, data)))
		ft_puterr();
	while (y < 4)
	{
		find_replace(&(*data)[y], '#', index + 'A');
		y++;
	}
}
