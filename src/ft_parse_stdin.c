#include "lem_in.h"

t_env	*ft_init_env(void)
{
	t_env	*e;

	e = ft_memalloc(sizeof(t_env));
	e->n = 0;
	e->m = NULL;
	e->nb_r = 0;
	e->c = NULL;
	e->a = NULL;
	e->cpy = NULL;
	e->paths = NULL;
	e->nb_paths = 0;
	return (e);
}

int		ft_is_room(char *line)
{
	if (!(*line) || *line == ' ')
		return (0);
	while (ft_isprint(*line) && *line != ' ')
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line)
		return (0);
	return (1);
}

int		ft_is_tube(char *line)
{
	if (!(ft_isprint(*line)) || *line == '-')
		return (0);
	while (ft_isprint(*line) && *line != '-' && *line != ' ')
		line++;
	if (*line != '-')
		return (0);
	line++;
	if (!(ft_isprint(*line)) || *line == '-')
		return (0);
	while (ft_isprint(*line) && *line != '-' && *line != ' ')
		line++;
	if (*line)
		return (0);
	return (1);
}

int		ft_is_number(char *line)
{
	if (!ft_isdigit(*line))
		return (0);
	while (ft_isdigit(*line))
		line++;
	return (!(*line));
}

t_op *ft_parse_stdin(void)
{
	t_op	*lst;
	char	*line;
	int		ret;
	int		ok;

	line = NULL;
	lst = NULL;
	ok = 1;
	while ((ret = get_next_line(0, &line)) > 0 && ok)
	{
		ok = (ft_is_tube(line) || ft_is_room(line) || ft_is_number(line)
		|| *line == '#');
		if (ok)
			ft_add_to_end(line, &lst);
		ft_free(line);
	}
	ft_free(line);
	if (ret < 0)
		ft_error();
	return (lst);
}
