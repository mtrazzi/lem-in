#include "lem_in.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_env *e = ft_init_env();

	ft_parse_lst(e);
	ft_print_mat(e->m, e->nb_r);
	return (0);
}
