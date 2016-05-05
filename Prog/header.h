/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 22:31:51 by aanzieu           #+#    #+#             */
/*   Updated: 2016/04/11 22:19:19 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFSIZE 546
# define MAXMINO 20
# define ONE fillit[y + (g_tetri[i][0])][x + (g_tetri[i][1])]
# define TWO fillit[y + (g_tetri[i][2])][x + (g_tetri[i][3])]
# define THREE fillit[y + (g_tetri[i][4])][x + (g_tetri[i][5])]
# define FOUR fillit[y + (g_tetri[i][6])][x + (g_tetri[i][7])]

typedef struct	s_input
{
	char	**data;
	char	**fillit;
}				t_input;

typedef struct	s_fillit
{
	char	*minos;
	char	*buffer;
	int		fd;
}				t_fillit;

void			check_transform(char *str, int index, char ***tetris);
int				solve(char ***fillit, t_input *tetris, int count, int y);

void			char2matrix(char *str, char ***tetris);
char			*matrix2char(char **str);
void			find_replace(char **str, char find, char replace);
void			remove_tetri(char ***fillit, char c);
t_input			*rem_matrix(t_input *tetris, int pos, int count);

int				s_compare(char c1, char c2);
int				ft_smartcmp(char *s1, char *s2);
int				ft_strcmp(char *s1, char *s2);
void			swap_c(char *c1, char *c2);
void			swap_array(char ***a1, char **a2, int y, int x);

char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
size_t			ft_count_minos(char *str);
void			ft_puterr(void);
void			print_matrix(char **str);

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
