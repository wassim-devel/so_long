/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:43:48 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 15:51:38 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_player *player, t_data *data)
{
	int	c_x;
	int	c_y;

	c_x = player->coord_x;
	c_y = player->coord_y;
	if (rtrnitpos(c_x / 64, (c_y - 64) / 64, data->m.ms) == 'E')
		return (2);
	if (rtrnitpos(c_x / 64, (c_y - 64) / 64, data->m.ms) != '1')
	{
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_g, c_x, c_y);
		c_y -= 64;
		player->coord_y -= 64;
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_p, c_x, c_y);
		return (1);
	}
	return (0);
}

int	move_bottom(t_player *player, t_data *data)
{
	int	c_x;
	int	c_y;

	c_x = player->coord_x;
	c_y = player->coord_y;
	if (rtrnitpos(c_x / 64, (c_y + 64) / 64, data->m.ms) == 'E')
		return (2);
	if (rtrnitpos(c_x / 64, (c_y + 64) / 64, data->m.ms) != '1')
	{
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_g, c_x, c_y);
		c_y += 64;
		player->coord_y += 64;
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_p, c_x, c_y);
		return (1);
	}
	return (0);
}

int	move_right(t_player *player, t_data *data)
{
	int	c_x;
	int	c_y;

	c_x = player->coord_x;
	c_y = player->coord_y;
	if (rtrnitpos((c_x + 64) / 64, c_y / 64, data->m.ms) == 'E')
		return (2);
	if (rtrnitpos((c_x + 64) / 64, c_y / 64, data->m.ms) != '1')
	{
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_g, c_x, c_y);
		c_x += 64;
		player->coord_x += 64;
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_p, c_x, c_y);
		return (1);
	}
	return (0);
}

int	move_left(t_player *player, t_data *data)
{
	int	c_x;
	int	c_y;

	c_x = player->coord_x;
	c_y = player->coord_y;
	if (rtrnitpos((c_x - 64) / 64, c_y / 64, data->m.ms) == 'E')
		return (2);
	if (rtrnitpos((c_x - 64) / 64, c_y / 64, data->m.ms) != '1')
	{
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_g, c_x, c_y);
		c_x -= 64;
		player->coord_x -= 64;
		mlx_put_image_to_window(data->m_p, data->w_p, data->m.i_p, c_x, c_y);
		return (1);
	}
	return (0);
}
