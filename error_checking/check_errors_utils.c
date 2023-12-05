/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:46:08 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:17 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	only_one_exit(char *bermap)
{
	int	number_of_exits;
	int	i;

	number_of_exits = 0;
	i = 0;
	while (bermap[i])
	{
		if (bermap[i] == 'E')
			number_of_exits++;
		i++;
	}
	if (number_of_exits != 1)
		return (0);
	return (1);
}

int	at_least_one_item(char *bermap)
{
	int	number_of_items;
	int	i;

	number_of_items = 0;
	i = 0;
	while (bermap[i])
	{
		if (bermap[i] == 'E')
			number_of_items++;
		i++;
	}
	if (number_of_items >= 1)
		return (1);
	return (0);
}

int	only_one_player(char *bermap)
{
	int	number_of_players;
	int	i;

	number_of_players = 0;
	i = 0;
	while (bermap[i])
	{
		if (bermap[i] == 'P')
			number_of_players++;
		i++;
	}
	if (number_of_players != 1)
		return (0);
	return (1);
}

int	is_rectangular(char *bermap)
{
	int	len_first_line;
	int	i;

	len_first_line = ltbs(bermap);
	i = 0;
	while (bermap[i])
	{
		if (bermap[i] == '\n' && bermap[i + 1] != '\0')
		{
			if (ltbs(&bermap[i + 1]) != len_first_line)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_closed(char *bermap)
{
	int	len_first_line;
	int	i;

	len_first_line = ltbs(bermap);
	i = -1;
	while (bermap[++i] != '\n')
	{
		if (bermap[i] != '1')
			return (0);
	}
	while (bermap[i])
	{
		if (bermap[i] == '\n' && bermap[i + 1] != '\0')
			if (bermap[i + 1] != '1' || bermap[i + len_first_line] != '1')
				return (0);
		i++;
	}
	i -= len_first_line;
	while (bermap[i] && bermap[i] != '\n')
	{
		if (bermap[i++] != '1')
			return (0);
	}
	return (1);
}
