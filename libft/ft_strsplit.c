/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:09:29 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 11:41:38 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && (s[i] == c))
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static	size_t	strlen_char(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	**tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(char *) * count_words(s, c) + 1)) == NULL)
		return (NULL);
	while (j < count_words(s, c))
	{
		tmp = (char **)malloc(sizeof(char *));
		while (s[i] == c)
			i++;
		if ((*tmp = ft_strnew(strlen_char(s + i, c))) == NULL)
			return (NULL);
		ft_strncpy(*tmp, s + i, strlen_char(s + i, c));
		i += strlen_char(s + i, c);
		tab[j] = ft_strdup(*tmp);
		free(*tmp);
		free(tmp);
		j++;
	}
	tab[j] = 0;
	for (size_t a = 0; a < count_words(s, c); a++)
		ft_printf("line %d is %s\n", a, tab[a]);
	return (tab);
}
