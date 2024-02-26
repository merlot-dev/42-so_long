/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:48:53 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/26 17:35:30 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_mvs(t_map *m, char **mvs)
{
	int	i;

	i = 0;
	while (mvs && i < m->rows)
	{
		if (mvs[i])
			mvs[i] = ft_free(mvs[i]);
		i++;
	}
	if (mvs)
		mvs = ft_free(mvs);
	return (1);
}

int	path_from(int x, int y, t_map *m, char **mvs)
{
	if (x == m->endx && y == m->endy)
		return (0);
	if (mvs[y][x] == 1 || m->maps[y][x] == '1')
		return (1);
	mvs[y][x] = 1;
	if (!path_from(x - 1, y, m, mvs))
		return (0);
	if (!path_from(x, y - 1, m, mvs))
		return (0);
	if (!path_from(x + 1, y, m, mvs))
		return (0);
	if (!path_from(x, y + 1, m, mvs))
		return (0);
	return (1);
}

int	check_path(t_map *m)
{
	char	**mvs;
	int		i;

	mvs = (char **)ft_calloc(m->rows, sizeof(char *));
	if (!mvs)
		return(1);
	i = 0;
	while (i < m->rows)
	{
		mvs[i] = (char *)ft_calloc(m->cols, sizeof(char));
		if (!mvs[i])
			return (free_mvs(m, mvs));
		i++;
	}
	i = path_from(m->stx, m->sty, m, mvs);
	free_mvs(m, mvs);
	return (i);
}

