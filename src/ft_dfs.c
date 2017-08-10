#include "lem_in.h"

void	ft_dfs_process(t_env *e, int i, int j) //regarde si on peut aller de j a i
{
	if (i == j || e->stop)
		return ;
	else if (e->cpy[i][j])
	{
	//	ft_printf("(%s,%s)\n", e->c[i], e->c[j]);
		if ((i == e->nb_r - 1 || e->a[i]) && e->a[j])
		{
			if (j > 0 && e->mov[e->a[j]])
				return ;
			if (j == 0)
			{
				e->a[i] = e->n - e->a[j] + 1;
				e->a[j] = e->a[j] - 1;
			}
			else
			{
				e->a[i] = e->a[j];
				e->a[j] = 0;	
			}
			ft_printf("L%d-%s ", e->a[i], e->c[i]);
			e->mov[e->a[i]] = 1;
			if (i == e->nb_r - 1)
				e->a[i] = 0;
		}
		e->cpy[i][j] = e->cpy[i][j] - 1;
		e->cpy[j][i] = e->cpy[j][i] - 1;
		//ft_printf("e->stop is %d\n", e->stop);
		i = -1;
		while (++i < e->nb_r && (j != 0))
			ft_dfs_process(e, j, i);
		e->stop = 1;
	}
}

void	ft_dfs(t_env *e, int start) //act on copy
{
	int j;

	ft_copy_mat(e);
	e->mov = ft_memalloc(sizeof(int) * e->n);
	j = 0;
	while (j < e->nb_r)
	{
		e->stop = 0;
		ft_dfs_process(e, start, j);
		j++;
	}
	free(e->cpy);
	free(e->mov);
}

void	ft_process_dfs(t_env *e)
{
	while (!ft_is_finished(e))
	{
		ft_dfs(e, e->nb_r - 1);
		ft_print_ant_tab(e->a, e->n);
	}
}
