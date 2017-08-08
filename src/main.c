#include "lem_in.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_env *e = ft_init_env();
	t_op *lst;
	lst = ft_parse_stdin();
	ft_parse_number(lst, e);
	ft_putnbr(e->n);
	return (0);
}
