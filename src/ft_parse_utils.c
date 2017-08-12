#include "lem_in.h"

char	*ft_process_room(char *s)
{
	*(ft_strchr(s, ' ')) = '\0';
	return (s);
}

int		**ft_init_mat(int n)
{
	int **result;
	int i;

	i = 0;
	result = ft_memalloc(sizeof(int *) * n);
	while (i < n)
	{
		result[i] = ft_memalloc(sizeof(int) * n);
		i++;
	}
	return (result);
}

int		ft_get_index(char *str, t_env *e)
{
	int i;

	i = 0;
	if (!str)
		return (e->nb_r);
	while (ft_strcmp(str, e->c[i]) && i < e->nb_r)
		i++;
	return (i);
}
