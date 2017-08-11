#include "lem_in.h"

void	ft_free_env(t_env *e)
{
	if (e->m)
		ft_free_mat(e->m, e->nb_r);
	e->m = NULL;
	if (e->c)
		ft_free_char_tab(e->c, e->nb_r);
	e->c = NULL;
	ft_free(e->a);
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

void	ft_free_lst_op(t_op *lst)
{
	t_op *tmp;

	if (!lst)
		return ;
	while (lst->next)
	{
		tmp = lst->next;
		lst->next = NULL;
		free(lst->op);
		lst->op = NULL;
		free(lst);
		lst = tmp;
	}
	free(lst->op);
	free(lst);
}
