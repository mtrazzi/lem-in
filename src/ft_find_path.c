#include "lem_in.h"

int		ft_is_there_path(t_env *e, int end)
{
	int i;
	int **m;

	if (end == 0)
		return (1);
	i = 0;
	while (i < e->nb_r)
	{
		if (e->cpy[i][end])
		{	
			m = ft_backup_mat(e->cpy, e->nb_r);
			e->cpy[i][end] = 0;
			e->cpy[end][i] = 0;
			if (ft_is_there_path(e, i))
			{
				ft_free_mat(e->cpy, e->nb_r);
				e->cpy = ft_backup_mat(m, e->nb_r); 
				ft_free_mat(m, e->nb_r);
				return (1);
			}
			ft_free_mat(e->cpy, e->nb_r);
			e->cpy = ft_backup_mat(m, e->nb_r); 
			ft_free_mat(m, e->nb_r);
		}
		i++;
	}
	return (0);
}

void	ft_del_vertex(t_env *e, int s)
{
	int i;

	i = 0;
	while (i < e->nb_r)
	{
		e->cpy[i][s] = 0;
		e->cpy[s][i] = 0;
		i++;
	}
}

int		ft_find_path_aux(t_env *e, int *path, int end)
{
	int i;
	int **m;

	if (end == 0)
		return (1);
	i = 0;
	while (i < e->nb_r)
	{
		if (e->cpy[i][end])
		{	
			ft_printf("(%s, %s)\n", e->c[i], e->c[end]);
			m = ft_backup_mat(e->cpy, e->nb_r);
			e->cpy[i][end] = 0;
			e->cpy[end][i] = 0;
			if (ft_find_path_aux(e, path, i))
			{
				path[end] = i;
				ft_free_mat(e->cpy, e->nb_r);
				e->cpy = ft_backup_mat(m, e->nb_r); 
				ft_free_mat(m, e->nb_r);
				return (1);
			}
			ft_free_mat(e->cpy, e->nb_r);
			e->cpy = ft_backup_mat(m, e->nb_r); 
			ft_free_mat(m, e->nb_r);
		}
		i++;
	}
	return (0);
}

int		*ft_find_path(t_env *e) // supposing there is path
{
	 int *result;

	 result = ft_memalloc(sizeof(int) * e->nb_r);
	 ft_find_path_aux(e, result, e->nb_r - 1);
	 return (result);
}
