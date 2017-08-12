/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:31 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:31:25 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_there_path(t_env *e, int end)
{
	int i;

	if (end == 0)
		return (1);
	i = 0;
	while (i < e->nb_r)
	{
		if (e->cpy[i][end])
		{
			e->cpy[i][end] = 0;
			e->cpy[end][i] = 0;
			if (ft_is_there_path(e, i))
				return (1);
			e->cpy[i][end] = 1;
			e->cpy[end][i] = 1;
		}
		i++;
	}
	return (0);
}

void	ft_del_vertex(t_env *e, int s)
{
	int i;

	i = 0;
	while (i < e->nb_r)
	{
		e->cpy[i][s] = 0;
		e->cpy[s][i] = 0;
		i++;
	}
}

int		ft_find_path_aux(t_env *e, int *path, int end)
{
	int i;

	if (end == 0)
		return (1);
	i = 0;
	while (i < e->nb_r)
	{
		if (e->cpy[i][end] && !e->visited[i])
		{
			e->visited[i] = 1;
			e->cpy[i][end] = 0;
			e->cpy[end][i] = 0;
			if (ft_find_path_aux(e, path, i))
			{
				path[end] = i;
				return (1);
			}
			e->cpy[i][end] = 1;
			e->cpy[end][i] = 1;
		}
		i++;
	}
	return (0);
}

int		*ft_find_path(t_env *e)
{
	int *result;

	result = ft_memalloc(sizeof(int) * e->nb_r);
	e->visited = ft_memalloc(sizeof(int) * e->nb_r);
	ft_find_path_aux(e, result, e->nb_r - 1);
	if (e->visited)
	{
		free(e->visited);
		e->visited = NULL;
	}
	return (result);
}
