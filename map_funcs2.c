/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:23 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 15:39:23 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_number_of_items_in_map(const char *bermap)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (bermap[i])
	{
		if (bermap[i] == 'C')
			count++;
		i++;
	}
	return (count);
}
