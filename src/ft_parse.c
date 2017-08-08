#include "lem_in.h"

void	ft_parse_number(t_op *lst, t_env *e)
{
	char *line;

	if (!lst)
		ft_error();			
	line = ft_pop_op(&lst);
	if (!ft_is_number(line))
		ft_error();
	e->n = ft_atoi(line);
}

int		ft_parse_room(t_op *lst, t_env *e, int i)
{
	char *line;

	if (!lst)
		ft_error();
	line = ft_pop_op(&lst);
}

void	ft_parse(t_op *lst, t_env *e)
{
	char	**c;
	int		i;

	ft_parse_number(lst, e);	
	e->c = ft_memalloc(sizeof(char *) * e->n);
}
