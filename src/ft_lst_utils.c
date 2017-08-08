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

	s = (*lst)->op;
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
	free(tmp->op);
	return (s);
}

char	*ft_pop_end(t_op **lst)
{
	char	*s;
	t_op	*tmp;
	t_op	*prev;

	if (!((*lst)->next))	
	{
		s = (*lst)->op;
		free((*lst)->op);
		free(*lst);
		*lst = NULL;
		return (s);
	}
	tmp = *lst;
	while ((*lst)->next)
	{
		s = (*lst)->next->op;
		prev = *lst;
		*lst = (*lst)->next;
	}
	*lst = tmp;
	free(prev->next->op);
	free(prev->next);
	prev->next = NULL;	
	return (s);
}

char	*ft_last_op(t_op *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst->op);
}
