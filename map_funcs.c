/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:38:18 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 15:39:21 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putmapimages(t_data data, int *a, int i, int y)
{
	if (data.m.ms[*a] == '\n')
		(*a)++;
	if (data.m.ms[*a] == '1')
		mlx_put_image_to_window(data.m_p, data.w_p, data.m.i_w, i, y);
	else if (data.m.ms[*a] == '0')
		mlx_put_image_to_window(data.m_p, data.w_p, data.m.i_g, i, y);
	else if (data.m.ms[*a] == 'P')
		mlx_put_image_to_window(data.m_p, data.w_p, data.m.i_p, i, y);
	else if (data.m.ms[*a] == 'E')
		mlx_put_image_to_window(data.m_p, data.w_p, data.m.i_e, i, y);
	else if (data.m.ms[*a] == 'C')
		mlx_put_image_to_window(data.m_p, data.w_p, data.m.i_i, i, y);
}

void	ft_putmap(t_data data, char *bermap)
{
	int	i;
	int	y;
	int	a;
	int	*a_ptr;

	a_ptr = &a;
	i = 0;
	y = 0;
	*a_ptr = 0;
	while (y < cbs(bermap) * 64)
	{
		while (i < ltbs(bermap) * 64)
		{
			ft_putmapimages(data, &a, i, y);
			i += 64;
			(*a_ptr)++;
		}
		i = 0;
		y += 64;
	}
}

char	*fill_bermap(char *file_path)
{
	int		fd;
	char	buffer[100000];
	char	*to_return;
	ssize_t	num_read;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	num_read = read(fd, buffer, 100000);
	buffer[num_read] = '\0';
	to_return = malloc(sizeof(char) * (num_read + 1));
	i = 0;
	while (buffer[i] != '\0')
	{
		to_return[i] = buffer[i];
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}

char	rtrnitpos(int x, int y, const char *bermap)
{
	int	i;
	int	trasversed_backslashns;

	i = 0;
	trasversed_backslashns = 0;
	while (bermap[i])
	{
		if (bermap[i] == '\n')
			trasversed_backslashns++;
		else if (trasversed_backslashns == y)
		{
			return (bermap[i + x]);
		}
		i++;
	}
	return (0);
}

void	ritp(int x, int y, char *bermap)
{
	int	i;
	int	trasversed_backslashns;

	i = 0;
	trasversed_backslashns = 0;
	while (bermap[i])
	{
		if (bermap[i] == '\n')
			trasversed_backslashns++;
		else if (trasversed_backslashns == y)
		{
			bermap[i + x] = '0';
			return ;
		}
		i++;
	}
}
