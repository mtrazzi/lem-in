#include "lem_in.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_env *e = ft_init_env();

	ft_parse_lst(e);
	ft_copy_mat(e);
	ft_print_ant_tab(ft_find_path(e), e->nb_r);
	ft_printf("%d\n", ft_is_there_path(e, e->nb_r - 1));
	ft_del_path(e, ft_find_path(e));
	ft_print_ant_tab(ft_find_path(e), e->nb_r);
	ft_printf("%d\n", ft_is_there_path(e, e->nb_r - 1));
	ft_del_path(e, ft_find_path(e));
	ft_printf("%d\n", ft_is_there_path(e, e->nb_r - 1));
	return (0);
}
