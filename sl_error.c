/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:30:14 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/07 15:32:20 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_error(const char *info)
{
	ft_printf("Error\n%s", info);
	return (1);
}

int	free_map(t_map *m)
{
	int	i;

	i = 0;
	if (m->maps)
	{
		while (i < m->rows)
		{
			if (m->maps[i])
				m->maps[i] = ft_free(m->maps[i]);
			i++;
		}
		m->maps = ft_free(m->maps);
	}
	return (0);
}

int	sl_error_free(t_map *m, const char *info)
{
	free_map(m);
	ft_printf("Error\n%s", info);
	return (1);
}
