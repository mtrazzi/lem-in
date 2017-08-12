#include "lem_in.h"

void	ft_copy_mat(t_env *e)
{
	int i;
	int j;

	ft_free_mat(e->cpy, e->nb_r);
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

int		**ft_backup_mat(int **m, int size)
{
	int i;
	int j;
	int **result;

	result = ft_init_mat(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			result[i][j] = m[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	ft_free_mat(int **m, int size)
{
	int i;

	if (!m)
		return ;
	i = 0;
	while (i < size)
	{
		if (m[i])
		{
			free(m[i]);
			m[i] = NULL;
		}
		i++;
	}
	if (m)
	{	
		free(m);
		m = NULL;
	}
}

int		ft_get_pre(t_env *e, int s, int *tab)
{
	int i;

	i = 0;
	while (i < e->nb_r)
	{
		if (tab[i] == s)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_del_path(t_env *e, int *path)
{
	int i;

	i = 0;
	while (i < e->nb_r)
	{
		if (path[i])
			ft_del_vertex(e, path[i]);
		i++;
	}
}
