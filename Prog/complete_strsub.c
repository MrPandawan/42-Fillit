/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_strsub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:55:52 by aanzieu           #+#    #+#             */
/*   Updated: 2016/04/10 22:54:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_strlen(const char *str)
{
	size_t	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	j;

	j = 0;
	if (ft_strlen(s) < start || !s)
		return (NULL);
	if (!(new = (char*)malloc(len + 1)))
		return (NULL);
	while (j < len && s[start])
		new[j++] = s[start++];
	new[j] = '\0';
	return (new);
}
