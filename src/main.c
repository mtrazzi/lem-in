/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:48 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:42:35 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_env *e;

	e = ft_init_env();
	ft_parse_lst(e);
	ft_copy_mat(e);
	if (!ft_is_there_path(e, e->nb_r - 1))
		ft_error("no path");
	ft_create_mat_path(e);
	while (!ft_is_finished(e))
		ft_process_paths(e);
	ft_free_env(e);
	return (0);
}
