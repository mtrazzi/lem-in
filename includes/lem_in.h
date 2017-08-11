#ifndef LEM_IN_H

# define LEM_IN_H
# include "libft.h"

typedef struct		s_env
{
	int		n;		//nb de fourmis
	int		nb_r;	//nb rooms
	int		**m;	//matrice d'adjacence
	char	**c;	//tableau de conversion int/char *
	int		*a;	//tableau contenant nombre de fourmis en chaque case
	int		**cpy;
	int		**paths;
	int		nb_paths;
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
void		ft_error(char *str);
t_op		*ft_parse_stdin(void);
int			ft_is_room(char *line);
int			ft_is_tube(char *line);
int			ft_is_number(char *line);
void		ft_parse_number(t_op **lst, t_env *e);
int			ft_count_rooms(t_op *lst);
void		ft_print_lst_op(t_op *t);
void		ft_parse_lst(t_env *e);
int			ft_parse_room(t_op **lst, t_env *e, int i);
int			**ft_init_mat(int n);
int			ft_get_index(char *str, t_env *e);
char		*ft_process_room(char *s);
void		ft_assert(t_op *lst, char *str);
void		ft_print_tab(char **tab, int size);
void		ft_print_mat(int **m, int size);
void		ft_print_ant_tab(int *tab, int size);
void		ft_copy_mat(t_env *e);
int			ft_is_finished(t_env *e);
int			**ft_backup_mat(int **m, int size);
int			ft_is_there_path(t_env *e, int end);
void		ft_free_mat(int **m, int size);
void		ft_free(void *p);
void		ft_del_vertex(t_env *e, int s);
int			ft_get_pre(t_env *e, int s, int *tab);
int			*ft_find_path(t_env *e);
void		ft_del_path(t_env *e, int *path);
int			ft_count_paths(t_env *e);
void		ft_create_mat_path(t_env *e);
void		ft_process_paths(t_env *e);
void		ft_free_env(t_env *e);
void		ft_error_env(t_env *e, char *str);
void		ft_free_lst_op(t_op *lst);

#endif
