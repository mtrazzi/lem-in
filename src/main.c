#include "lem_in.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_env *e = ft_init_env();

	ft_parse_lst(e);
	ft_create_mat_path(e);
	while (!ft_is_finished(e))
		ft_process_paths(e);
	ft_free_env(e);
	return (0);
}

