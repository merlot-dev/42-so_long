/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:59:44 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/14 00:32:58 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	flood_map(int x, int y, t_map *m, char **mvs)
{
	mvs[y][x] |= 1;
	if (m->maps[y][x] == 'C')
		m->coll--;
	if (m->maps[y - 1][x] != '1')
		mvs[y - 1][x] |= 2;
	if (m->maps[y + 1][x] != '1')
		mvs[y + 1][x] |= 2;
	if (m->maps[y][x - 1] != '1')
		mvs[y][x - 1] |= 2;
	if (m->maps[y][x + 1] != '1')
		mvs[y][x + 1] |= 2;
	if (!(mvs[y - 1][x] & 1) && m->maps[y - 1][x] != '1')
		flood_map(x, y - 1, m, mvs);
	if (!(mvs[y + 1][x] & 1) && m->maps[y + 1][x] != '1')
		flood_map(x, y + 1, m, mvs);
	if (!(mvs[y][x - 1] & 1) && m->maps[y][x - 1] != '1')
		flood_map(x - 1, y, m, mvs);
	if (!(mvs[y][x + 1] & 1) && m->maps[y][x + 1] != '1')
		flood_map(x + 1, y, m, mvs);
	if (mvs[m->endy][m->endy] && !m->coll)
		return (0);
	return (1);
}

int	check_path(t_map *m)
{
	char	**mvs;
	int		i;
	int		c;

	mvs = (char **)ft_calloc(m->rows, sizeof(char *));
	if (!mvs)
		return (1);
	i = 0;
	while (i < m->rows)
	{
		mvs[i] = (char *)ft_calloc(m->cols, sizeof(char));
		if (!mvs[i])
			return (free_mvs(m, mvs));
		i++;
	}
	c = m->coll;
	i = flood_map(m->stx, m->sty, m, mvs);
	m->coll = c;
	free_mvs(m, mvs);
	return (i);
}
