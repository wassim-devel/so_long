/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:30:46 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 17:58:14 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_destroy_after_error(t_data *d)
{
	free(d->m.ms);
	exit(0);
}

void	free_table(char **table_map)
{
	int	i;

	i = 0;
	while (table_map[i])
	{
		free(table_map[i]);
		i++;
	}
	free(table_map);
}
