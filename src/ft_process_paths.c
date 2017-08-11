#include "lem_in.h"

int		ft_count_paths(t_env *e)
{
	int i;
	int *tab;
	i = 0;
	
	ft_copy_mat(e);
	while (ft_is_there_path(e, e->nb_r - 1))
	{
		tab = ft_find_path(e);
		ft_del_path(e, tab);
		free(tab);
		i++;
	}
	return (i);
}

void	ft_create_mat_path(t_env *e)
{
	int i;
	int	*path;

	e->nb_paths = ft_count_paths(e);
	e->paths = ft_memalloc(e->nb_paths);
	i =  0;
	ft_copy_mat(e);
	while (i < e->nb_paths)
	{
		path = ft_find_path(e);
		e->paths[i] = path;
		ft_del_path(e, path);
		i++;
	}	
}

void	ft_process_paths_aux(t_env *e, int i, int j)
{
	int prev;

	prev = e->paths[i][j];
	if (e->a[j] || !e->a[prev])
		return ;
	if (prev == 0)
	{
		e->a[j] = e->n - e->a[prev] + 1;
		e->a[0] = e->a[prev] - 1;
	}
	else
	{
		e->a[j] = e->a[prev];
		e->a[prev] = 0;
	}
	ft_printf("L%d-%s ", e->a[j], e->c[j]);
	if (j == e->nb_r - 1)
		e->a[j] = 0;
}

void	ft_process_paths(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->nb_paths)
	{
		j = e->nb_r - 1;
		while (j > 0)
		{
			ft_process_paths_aux(e, i, j);
			j = e->paths[i][j];	
		}
		i++;
	}
	ft_putchar('\n');
}
