/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:55:52 by aanzieu           #+#    #+#             */
/*   Updated: 2016/04/11 22:19:00 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		fillit_alloc(char ***fillit, int size)
{
	int i;
	int j;

	i = -1;
	*fillit = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		(*fillit)[i] = (char *)malloc(size + 1);
		j = -1;
		while (++j < size)
			(*fillit)[i][j] = '.';
		(*fillit)[i][size] = '\0';
	}
	(*fillit)[size] = NULL;
}

void		resolvetetris(t_input *tetris, int count)
{
	char	**fillit;
	int		size;
	int		i;

	i = 0;
	size = 2;
	while (size * size < count * 4)
		size++;
	fillit_alloc(&fillit, size);
	while (!(solve(&fillit, tetris, count, 0)))
	{
		free(fillit);
		fillit_alloc(&fillit, ++size);
	}
	print_matrix(fillit);
	free(fillit);
}

static char	*read_av(t_fillit *fillit, char *av)
{
	if ((fillit->fd = open(av, O_RDONLY)) < 0)
		ft_puterr();
	if (!(fillit->buffer = (char*)malloc(BUFFSIZE + 1)))
		return (NULL);
	if (read(fillit->fd, fillit->buffer, BUFFSIZE) < 0)
		ft_puterr();
	if (ft_strlen(fillit->buffer) < 19)
		ft_puterr();
	if (ft_strlen(fillit->buffer) != (ft_count_minos(fillit->buffer) * 21) - 1)
		ft_puterr();
	fillit->buffer[ft_strlen(fillit->buffer) + 1] = '\0';
	close(fillit->fd);
	return (fillit->buffer);
}

static void	fillitgood(t_fillit *fillit, int i, int index)
{
	t_input		*tetris;

	tetris = (t_input *)malloc(sizeof(t_input)
			* (ft_count_minos(fillit->buffer) + 1));
	while (fillit->buffer[++i])
	{
		if (!(i % 21))
		{
			tetris[index].data = (char **)malloc(sizeof(char *) * 4);
			check_transform(ft_strsub(fillit->buffer, i - 21, MAXMINO), index,
					&tetris[index].data);
			index++;
		}
	}
	if (!(fillit->buffer[i]))
	{
		tetris[index].data = (char **)malloc(sizeof(char *) * 4);
		check_transform(ft_strsub(fillit->buffer, i - 20, MAXMINO), index,
				&tetris[index].data);
	}
	tetris[++index].data = NULL;
	resolvetetris(tetris, ft_count_minos(fillit->buffer));
}

int			main(int ac, char **av)
{
	t_fillit	*fillit;

	if (ac == 2)
	{
		fillit = (t_fillit*)malloc(sizeof(t_fillit));
		read_av(fillit, av[1]);
		fillitgood(fillit, 18, 0);
	}
	else
	{
		write(2, "usage: fillit [source_file]\n", 28);
		return (EXIT_FAILURE);
	}
	return (0);
}
