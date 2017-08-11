#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_assert(t_op *lst)
{
	if (!lst)
		ft_error();
}

void	ft_free(void *p)
{
	if (!p)
	{
		free(p);
		p = NULL;
	}
}

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
}
