#include "lem_in.h"

void	ft_print_tab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i])
			ft_putstr(tab[i]);
		else
			ft_putstr("0");
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_mat(int **m, int size)
{
	int i;
	int j;

	i = 0;
	j = -1;
	ft_printf("    ");
	while (++j < size)
		ft_printf("%d ", j);
	j = -1;
	ft_putchar('\n');
	ft_printf("    ");
	while (++j < size)
		ft_printf("- ");
	ft_putchar('\n');
	while (i < size)
	{
		ft_printf("%d | ", i);
		j = 0;
		while (j < size)
		{
			ft_printf("%d ", m[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	ft_print_ant_tab(int *tab,  int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%2d ", (i + 1) % 8);
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (i < size)
	{
		ft_printf("%2d ", tab[i]);
		i++;
	}
	ft_putchar('\n');
}
