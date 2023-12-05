/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:11:52 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 17:59:26 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include "unistd.h"
# include "fcntl.h"
# include <X11/X.h>

typedef struct s_map {
	void	*i_g;
	void	*i_w;
	void	*i_p;
	void	*i_e;
	void	*i_i;
	int		i_wi;
	int		i_he;
	char	*ms;
	int		items_in_map;
}				t_map;

typedef struct s_player
{
	int	coord_x;
	int	coord_y;
}				t_player;

typedef struct s_data {
	void		*m_p;
	void		*w_p;
	t_map		m;
	t_player	*p;
}				t_data;

//error_checking
//check_errors.c
int			check_error(char *bermap, t_data data);
//ft_split.c
char		**ft_split(char const *s, char c);
//check_errors_utils.c
int			only_one_exit(char *bermap);
int			at_least_one_item(char *bermap);
int			only_one_player(char *bermap);
int			is_rectangular(char *bermap);
int			is_map_closed(char *bermap);

//check_errors_utils2.c
void		free_table(char **table_map);
int			on_destroy_after_error(t_data *d);

//map_funcs.c
void		ft_putmap(t_data data, char *bermap);
char		*fill_bermap(char *file_path);
char		rtrnitpos(int x, int y, const char *bermap);
void		ritp(int x, int y, char *bermap);

//map_funcs2.c
int			count_number_of_items_in_map(const char *bermap);

//utils.c
int			ltbs(const char *str);
int			cbs(const char *str);
void		ft_putnbr(int n);

//player_utils.c
t_player	*find_initial_coords(const char *bermap);
int			move_if_it_can(int keysym, t_data *data);

//player_utils2.c
int			move_left(t_player *player, t_data *data);
int			move_right(t_player *player, t_data *data);
int			move_bottom(t_player *player, t_data *data);
int			move_up(t_player *player, t_data *data);

#endif
