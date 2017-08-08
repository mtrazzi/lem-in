#ifndef LEM_IN_H

# define LEM_IN_H
# include "libft.h"

typedef struct		s_env
{
	int		n;
	int		**m;
	char	**c;
}					t_env;
typedef struct		s_op
{
	struct s_op		*next;
	char			*op;
}					t_op;
t_env		*ft_init_env(void);
int			ft_is_room(char *line);
int			ft_is_tube(char *line);
t_op		*ft_new_op(char *op);
void		ft_add_to_end(char *op, t_op **lst);
char		*ft_pop_op(t_op **lst);
void		ft_error(void);
t_op		*ft_parse_stdin(void);
int			ft_is_room(char *line);
int			ft_is_tube(char *line);
int			ft_is_number(char *line);
void		ft_parse_number(t_op *lst, t_env *e);

#endif
