#include "lem_in.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_env *e = ft_init_env();

	ft_parse_lst(e);
	ft_printf("Is there path ? %d\n", ft_is_there_path(e, e->nb_r - 1));
	return (0);
}
