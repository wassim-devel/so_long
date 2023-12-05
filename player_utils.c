/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:39:45 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 15:48:27 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*find_initial_coords(const char *bermap)
{
	int			i;
	int			x;
	int			y;
	t_player	*coords;

	coords = malloc(sizeof(t_player));
	i = -1;
	x = 0;
	y = 0;
	while (bermap[++i])
	{
		if (bermap[i] == 'P')
		{
			coords->coord_x = (x - 1) * 64;
			coords->coord_y = (y) * 64;
			return (coords);
		}
		if (bermap[i] == '\n')
		{
			x = 0;
			y++;
		}
		x++;
	}
	return (coords);
}

int	move_if_it_can(int keysym, t_data *data)
{
	if (keysym == 0x0077)
		return (move_up(data->p, data));
	else if (keysym == 0x0061)
		return (move_left(data->p, data));
	else if (keysym == 0x0073)
		return (move_bottom(data->p, data));
	else if (keysym == 0x0064)
		return (move_right(data->p, data));
	return (0);
}
