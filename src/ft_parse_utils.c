/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:40 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:34:23 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_process_room(char *s)
{
	*(ft_strchr(s, ' ')) = '\0';
	return (s);
}

int		**ft_init_mat(int n)
{
	int **result;
	int i;

	i = 0;
	result = ft_memalloc(sizeof(int *) * n);
	while (i < n)
	{
		result[i] = ft_memalloc(sizeof(int) * n);
		i++;
	}
	return (result);
}

int		ft_get_index(char *str, t_env *e)
{
	int i;

	i = 0;
	if (!str)
		return (e->nb_r);
	while (ft_strcmp(str, e->c[i]) && i < e->nb_r)
		i++;
	return (i);
}

void	ft_update_start_end(t_env *e, char *line, char *room)
{
	e->c[(!ft_strcmp(line, "##start") ? 0 : e->nb_r - 1)] = \
		ft_process_room(room);
	if (!ft_strcmp(line, "##start"))
		e->start += 1;
	if (!ft_strcmp(line, "##end"))
		e->end += 1;
	if (e->start > 1 || e->end > 1)
		ft_error("multiple start or end");
	free(line);
}
