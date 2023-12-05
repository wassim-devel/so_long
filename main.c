/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:10:05 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 17:54:48 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *d)
{
	mlx_destroy_image(d->m_p, d->m.i_g);
	mlx_destroy_image(d->m_p, d->m.i_p);
	mlx_destroy_image(d->m_p, d->m.i_e);
	mlx_destroy_image(d->m_p, d->m.i_i);
	mlx_destroy_image(d->m_p, d->m.i_w);
	mlx_destroy_window(d->m_p, d->w_p);
	mlx_destroy_display(d->m_p);
	free(d->m_p);
	free(d->m.ms);
	free(d->p);
	exit(0);
}

void	increment_on_move(void)
{
	static int	i = 0;

	i++;
	ft_putnbr(i);
	write(1, "\n", 1);
}

int	on_keypress(int k, t_data *d)
{
	static int	current_collected_items = 0;
	int			return_value;

	if (rtrnitpos(d->p->coord_x / 64, d->p->coord_y / 64, d->m.ms) == 'C')
	{
		ritp(d->p->coord_x / 64, d->p->coord_y / 64, d->m.ms);
		current_collected_items++;
	}
	if (k == 0x0077 || k == 0x0061 || k == 0x0073 || k == 0x0064)
	{
		return_value = move_if_it_can(k, d);
		if (return_value == 1)
			increment_on_move();
		if (return_value == 2 && current_collected_items == d->m.items_in_map)
			on_destroy(d);
	}
	if (k == 0xff1b)
		on_destroy(d);
	return (0);
}

void	assign_images(t_data *d)
{
	d->m.i_g = mlx_xpm_file_to_image(d->m_p,
			"./assets/g.xpm", &d->m.i_wi, &d->m.i_he);
	d->m.i_w = mlx_xpm_file_to_image(d->m_p,
			"./assets/w.xpm", &d->m.i_wi, &d->m.i_he);
	d->m.i_p = mlx_xpm_file_to_image(d->m_p,
			"./assets/p.xpm", &d->m.i_wi, &d->m.i_he);
	d->m.i_e = mlx_xpm_file_to_image(d->m_p,
			"./assets/e.xpm", &d->m.i_wi, &d->m.i_he);
	d->m.i_i = mlx_xpm_file_to_image(d->m_p,
			"./assets/i.xpm", &d->m.i_wi, &d->m.i_he);
	d->m.items_in_map = count_number_of_items_in_map(d->m.ms);
	ft_putmap(*d, d->m.ms);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc == 2)
	{
		d.m.ms = fill_bermap(argv[1]);
		check_error(d.m.ms, d);
		if (!d.m.ms)
			return (1);
		d.m_p = mlx_init();
		if (!d.m_p)
			return (1);
		d.w_p = mlx_new_window(d.m_p, ltbs(d.m.ms) * 64, cbs(d.m.ms) * 64, "");
		if (!d.w_p)
			return (free(d.m_p), free(d.m.ms), 1);
		assign_images(&d);
		d.p = find_initial_coords(d.m.ms);
		mlx_hook(d.w_p, KeyPress, KeyPressMask, &on_keypress, &d);
		mlx_hook(d.w_p, DestroyNotify, StructureNotifyMask, &on_destroy, &d);
		mlx_loop(d.m_p);
		free(d.m.ms);
		free(d.p);
		return (0);
	}
	write(1, "Pas le bon nombre d'arguments", 29);
}
