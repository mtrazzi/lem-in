#include "libft.h"

char	*get_buffer(const int fd)
{
	char	buff[BUF_SIZE];
	int		ret;
	int		n;

	ft_memset(buff, 0, BUF_SIZE);
	n = 0;
	ret = read(fd, buff, BUF_SIZE);
	if (ret < 0)
		perror("Error :");
	return (ft_strdup(buff));
}

int		get_next_line(const int fd, char **line)
{
	static char	**tab = NULL;
	static int	n = 0;
	char		*buffer;
	int			i;

	if (!tab)
	{
		buffer = get_buffer(fd);
		tab = ft_strsplit(buffer, '\n');
		free(buffer);
	}
	*line = ft_strdup(tab[n]);
	if (!tab || n == (ft_tab_length(tab) - 1))
	{
		i = -1;
		while (++i < ft_tab_length(tab))
			free(tab[i]);
		free(tab);
		return (0);
	}
	n++;
	return (1);
}
