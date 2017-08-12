/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:38 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:44:22 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_env	*ft_init_env(void)
{
	t_env	*e;

	e = ft_memalloc(sizeof(t_env));
	e->n = 0;
	e->m = NULL;
	e->nb_r = 0;
	e->c = NULL;
	e->a = NULL;
	e->cpy = NULL;
	e->paths = NULL;
	e->nb_paths = 0;
	e->visited = NULL;
	e->start = 0;
	e->end = 0;
	return (e);
}

int		ft_is_room(char *line)
{
	if (!(*line) || *line == ' ')
		return (0);
	while (ft_isprint(*line) && *line != ' ')
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line)
		return (0);
	return (1);
}

int		ft_is_tube(char *line)
{
	if (!(ft_isprint(*line)) || *line == '-')
		return (0);
	while (ft_isprint(*line) && *line != '-' && *line != ' ')
		line++;
	if (*line != '-')
		return (0);
	line++;
	if (!(ft_isprint(*line)) || *line == '-')
		return (0);
	while (ft_isprint(*line) && *line != '-' && *line != ' ')
		line++;
	if (*line)
		return (0);
	return (1);
}

int		ft_is_number(char *line)
{
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	return (!(*line));
}

t_op	*ft_parse_stdin(void)
{
	t_op	*lst;
	char	*line;
	int		ret;
	int		ok;

	line = NULL;
	lst = NULL;
	ok = 1;
	while ((ret = get_next_line(0, &line)) > 0 && ok)
	{
		ok = (ft_is_tube(line) || ft_is_room(line) || ft_is_number(line)
		|| *line == '#');
		if (ok)
			ft_add_to_end(line, &lst);
		free(line);
	}
	if (!line || (!ft_is_tube(line) && (*line != '#')))
		ft_error("empty file or last line incorrect");
	ft_add_to_end(line, &lst);
	free(line);
	if (ret < 0)
		ft_error("error in get_next_line");
	return (lst);
}
