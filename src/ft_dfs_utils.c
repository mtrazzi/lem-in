#include "lem_in.h"

void	ft_copy_mat(t_env *e)
{
	int i;
	int j;

	e->cpy = ft_init_mat(e->nb_r);
	i = 0;
	while (i < e->nb_r)
	{
		j = 0;
		while (j < e->nb_r)
		{
			e->cpy[i][j] = e->m[i][j];
			j++;
		}
		i++;
	}
}

int		ft_is_finished(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_r - 1)
	{
		if (e->a[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
