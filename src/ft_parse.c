#include "lem_in.h"

void	ft_parse_number(t_op **lst, t_env *e)
{
	char *line;

	if (!lst)
		ft_error();	
	line = ft_pop_op(lst);
	if (!ft_is_number(line))
		ft_error();
	e->n = ft_atoi(line);
}

int		ft_parse_room(t_op **lst, t_env *e, int i)
{
	char *line;
	char *room;

	line = ft_pop_op(lst);
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
	{
		room = ft_pop_op(lst);
		if (!ft_is_room(room))
			ft_error();
		e->c[(!ft_strcmp(line, "##start") ? 0 : e->nb_r - 1)] = ft_process_room(room); 
		return (0);
	}
	else if ((*line) == '#')
		return (0);
	e->c[i] = ft_process_room(line);
	return (1);
}

void	ft_parse_tube(t_op **lst, t_env *e)
{
	char	*line;
	int		x;
	int		y;

	line = ft_pop_op(lst);
	if (*(line) == '#')
		return ;
	*(ft_strchr(line, '-')) = '\0';	
	x = ft_get_index(line, e);
	y = ft_get_index(ft_strchr(line, '\0') + 1, e);
	e->m[x][y] = 1;
	e->m[y][x] = 1;
}

void	ft_parse_lst(t_env *e)
{
	int		i;
	t_op	*lst;

	i = 1;
	lst = ft_parse_stdin();
	ft_parse_number(&lst, e);
	e->nb_r = ft_count_rooms(lst);
	e->c = ft_memalloc(sizeof(char *) * e->nb_r);
	e->m = ft_init_mat(e->nb_r);
	while (lst && (ft_is_room(lst->op) || *(lst->op) == '#'))
		i += ft_parse_room(&lst, e, i);
	ft_assert(lst);
	while (lst && (ft_is_tube(lst->op) || *(lst->op) == '#'))
		ft_parse_tube(&lst, e);
	e->a = ft_memalloc(sizeof(int) * e->nb_r);
	e->a[0] = e->n;
	ft_copy_mat(e);
	if (!ft_is_there_path(e, e->nb_r - 1))
		ft_error();
	ft_print_lst_op(lst);
}
