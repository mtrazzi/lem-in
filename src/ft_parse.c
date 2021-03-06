/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:36 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:36:10 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_number(t_op **lst, t_env *e)
{
	char *line;

	if (!lst)
		ft_error("nothing instead of number for first line");
	line = ft_pop_op(lst);
	if (!ft_is_number(line))
		ft_error("not a number for first line");
	e->n = ft_atoi(line);
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int		ft_parse_room(t_op **lst, t_env *e, int i)
{
	char *line;
	char *room;

	line = ft_pop_op(lst);
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
	{
		room = ft_pop_op(lst);
		if (!ft_is_room(room))
		{
			free(line);
			free(room);
			ft_error_env(e, "incorrect room after start or end");
		}
		ft_update_start_end(e, line, room);
		return (0);
	}
	else if ((*line) == '#')
	{
		free(line);
		return (0);
	}
	e->c[i] = ft_process_room(line);
	return (1);
}

void	ft_parse_tube(t_op **lst, t_env *e)
{
	char	*line;
	int		x;
	int		y;

	line = ft_pop_op(lst);
	if (*(line) == '#')
	{
		free(line);
		return ;
	}
	*(ft_strchr(line, '-')) = '\0';
	x = ft_get_index(line, e);
	y = ft_get_index(ft_strchr(line, '\0') + 1, e);
	if (x == e->nb_r || y == e->nb_r)
		ft_error_env(e, "tube out of bound");
	e->m[x][y] = 1;
	e->m[y][x] = 1;
	free(line);
}

void	ft_parse_lst(t_env *e)
{
	int		i;
	t_op	*lst;

	i = 1;
	lst = ft_parse_stdin();
	if (!lst)
		return ;
	ft_print_lst_op(lst);
	ft_putchar('\n');
	ft_parse_number(&lst, e);
	ft_assert(lst, "nothing after first number");
	e->nb_r = ft_count_rooms(lst);
	e->c = ft_memalloc(sizeof(char *) * e->nb_r);
	e->m = ft_init_mat(e->nb_r);
	while (lst && (ft_is_room(lst->op) || *(lst->op) == '#'))
		i += ft_parse_room(&lst, e, i);
	if (!lst || (!e->start || !e->end))
		ft_error("error parsing rooms");
	while (lst && (ft_is_tube(lst->op) || *(lst->op) == '#'))
		ft_parse_tube(&lst, e);
	if (lst)
		ft_error("general scope not well formated. Usage : nb/rooms/tubes");
	e->a = ft_memalloc(sizeof(int) * e->nb_r);
	e->a[0] = e->n;
}
