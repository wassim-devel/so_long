/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:08:08 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 18:02:29 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_if_valid_path(char **table_map)
{
	int	i;
	int	j;
	int	count_items;

	i = 0;
	j = 0;
	count_items = 0;
	while (table_map[i] != NULL)
	{
		while (table_map[i][j])
		{
			if (table_map[i][j] == 'C' || table_map[i][j] == 'E')
				count_items++;
			j++;
		}
		i++;
		j = 0;
	}
	if (count_items > 0)
		return (0);
	return (1);
}

void	fill_for_validpath(char **table_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (table_map[i] != NULL)
	{
		while (table_map[i][j])
		{
			if (table_map[i][j] == 'P' && table_map[i - 1][j] != '1')
				table_map[i - 1][j] = 'P';
			if (table_map[i][j] == 'P' && table_map[i + 1][j] != '1')
				table_map[i + 1][j] = 'P';
			if (table_map[i][j] == 'P' && table_map[i][j + 1] != '1')
				table_map[i][j + 1] = 'P';
			if (table_map[i][j] == 'P' && table_map[i][j - 1] != '1')
				table_map[i][j - 1] = 'P';
			j++;
		}
		i++;
		j = 0;
	}
}

int	is_there_valid_path(char *bermap)
{
	char	**table_map;
	int		number_of_times;

	table_map = ft_split(bermap, '\n');
	number_of_times = 100;
	while (number_of_times != 0)
	{
		fill_for_validpath(table_map);
		number_of_times--;
	}
	if (check_if_valid_path(table_map) == 1)
	{
		free_table(table_map);
		return (1);
	}
	free_table(table_map);
	return (0);
}

int	two_checks(char *bermap)
{
	if (!is_rectangular(bermap))
	{
		write(1, "Error\nThe map isn't rectangular", 31);
		return (0);
	}
	if (!is_map_closed(bermap))
	{
		write(1, "Error\nThe map isn't closed", 26);
		return (0);
	}
	return (1);
}

//return 1 if error, 0 if no error
int	check_error(char *bermap, t_data data)
{
	if (!only_one_exit(bermap))
	{
		write(1, "Error\nThere's not only one exit", 31);
		on_destroy_after_error(&data);
	}
	if (!at_least_one_item(bermap))
	{
		write(1, "Error\nThere's not at least one item", 35);
		on_destroy_after_error(&data);
	}
	if (!only_one_player(bermap))
	{
		write(1, "Error\nThere's not only one player", 33);
		on_destroy_after_error(&data);
	}
	if (!two_checks(bermap))
		on_destroy_after_error(&data);
	if (!is_there_valid_path(bermap))
	{
		write(1, "Error\nThere is no valid path", 28);
		on_destroy_after_error(&data);
	}
	return (0);
}
