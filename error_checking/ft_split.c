/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:39:57 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:25:58 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (i == 0)
		{
			if (s[i] == c)
				counter++;
		}
		else if (s[i - 1] != c && s[i] == c && s[i - 1])
			counter++;
		i++;
	}
	if (i != 0 && s[i - 1] != c && (s[i] == c || s[i] == '\0') && s[i - 1])
		counter++;
	return (counter);
}

int	ft_strlen_to_c(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	free_all(char	**tab, int amount)
{
	while (amount >= 0)
	{
		free(tab[amount]);
		amount--;
	}
	free(tab);
}

int	write_word(char *to_write, char const *to_copy, char c)
{
	int	i;

	i = 0;
	while (to_copy[i] != c && to_copy[i])
	{
		to_write[i] = to_copy[i];
		i++;
	}
	to_write[i] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**to_return;

	i = 0;
	to_return = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!to_return)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		to_return[i] = malloc(sizeof(char) * (ft_strlen_to_c(s, c) + 1));
		if (!(to_return[i]))
		{
			free_all(to_return, i);
			return (NULL);
		}
		s += write_word(to_return[i], s, c);
		i++;
	}
	to_return[i] = 0;
	return (to_return);
}
