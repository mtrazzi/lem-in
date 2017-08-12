/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:22 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:25:24 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_env(t_env *e)
{
	if (e->m)
		ft_free_mat(e->m, e->nb_r);
	e->m = NULL;
	if (e->c)
		ft_free_char_tab(e->c, e->nb_r);
	e->c = NULL;
	if (e->a)
	{
		free(e->a);
		e->a = NULL;
	}
	if (e->cpy)
		ft_free_mat(e->cpy, e->nb_r);
	e->cpy = NULL;
	if (e->paths)
		ft_free_mat(e->paths, e->nb_paths);
	e->paths = NULL;
	e->n = 0;
	e->nb_r = 0;
	e->nb_paths = 0;
	free(e);
}
