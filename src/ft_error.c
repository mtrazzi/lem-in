#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_assert(t_op *lst)
{
	if (!lst)
		ft_error();
}
