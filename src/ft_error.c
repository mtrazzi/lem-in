/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:29 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:25:30 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_env(t_env *e, char *str)
{
	if (e)
	{
		ft_free_env(e);
		e = NULL;
	}
	ft_error(str);
}

void	ft_assert(t_op *lst, char *str)
{
	if (!lst)
		ft_error(str);
}
