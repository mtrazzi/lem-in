/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:25:33 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 15:29:08 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_op	*ft_new_op(char *op)
{
	t_op *t;

	t = ft_memalloc(sizeof(t_op));
	t->next = NULL;
	t->op = ft_strdup(op);
	return (t);
}

void	ft_add_to_end(char *op, t_op **lst)
{
	t_op *tmp;

	if (!(*lst))
	{
		*lst = ft_new_op(op);
		return ;
	}
	tmp = *lst;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = ft_new_op(op);
	*lst = tmp;
}

char	*ft_pop_op(t_op **lst)
{
	char *s;
	t_op *tmp;

	if (!(*lst))
		ft_error("not well formated");
	s = ft_strdup((*lst)->op);
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp->op);
	free(tmp);
	return (s);
}

int		ft_count_rooms(t_op *lst)
{
	int i;

	i = 0;
	ft_assert(lst, "not able to count rooms");
	while (lst)
	{
		if (lst && ft_is_room(lst->op))
			i++;
		if (lst)
			lst = lst->next;
	}
	return (i);
}

void	ft_print_lst_op(t_op *t)
{
	while (t)
	{
		ft_putstr(t->op);
		ft_putchar('\n');
		t = t->next;
	}
}
