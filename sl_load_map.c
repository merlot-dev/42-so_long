/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:43:46 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/11 19:12:37 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_rows(int fd, t_map *m)
{
	char	*line;

	m->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (m->rows == 0)
			m->cols = ft_strlen(line);
		else if (m->cols != (int)ft_strlen(line))
		{
			line = ft_free(line);
			return (sl_error("Bad map width\n"));
		}
		m->rows++;
		line = ft_free(line);
		line = get_next_line(fd);
	}
	m->cols--;
	if ((m->cols < 3) || (m->rows < 3))
		return (sl_error("Size to small\n"));
	m->stx = 0;
	m->sty = 0;
	m->endx = 0;
	m->endy = 0;
	return (0);
}

int	check_elements(t_map *m, int y, int x)
{
	if (!ft_strchr("10CEP", m->maps[y][x]))
		return (sl_error_free(m, "Invalid char in map\n"));
	if (m->maps[y][x] == 'P' && m->stx)
		return (sl_error_free(m, "More than one start\n"));
	m->sty += y * (m->maps[y][x] == 'P');
	m->stx += x * (m->maps[y][x] == 'P');
	if (m->maps[y][x] == 'E' && m->endx)
		return (sl_error_free(m, "More than one exit\n"));
	m->endy += y * (m->maps[y][x] == 'E');
	m->endx += x * (m->maps[y][x] == 'E');
	m->coll += m->maps[y][x] == 'C';
	return (0);
}

int	check_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	m->coll = 0;
	while (i < m->rows)
	{
		if (m->maps[i][0] != '1' || m->maps[i][m->cols -1] != '1')
			return (sl_error_free(m, "Bad wall\n"));
		j = 1;
		while (j < m->cols -1)
		{
			if ((i == 0 || i == m->rows - 1) && m->maps[i][j] != '1')
				return (sl_error_free(m, "Bad wall\n"));
			if (i > 0 && i < m->rows - 1)
				if (check_elements(m, i, j))
					return (1);
			j++;
		}
		i++;
	}
	if (!m->coll || !m->stx || !m->endx)
		return (sl_error_free(m, "Not enough elements in map\n"));
	return (0);
}

int	get_map_info(int fd, t_map *m)
{
	int		i;
	char	*line;

	m->maps = (char **)ft_calloc(m->rows, sizeof(char *));
	if (! m->maps)
		return (sl_error("Map malloc has failed\n"));
	i = 0;
	while (i < m->rows)
	{
		line = get_next_line(fd);
		m->maps[i] = ft_substr(line, 0, m->cols);
		line = ft_free(line);
		if (!m->maps[i])
			return (sl_error_free(m, "Map line malloc failed\n"));
		i++;
	}
	if (check_map(m))
		return (1);
	if (check_path(m))
		return (sl_error_free(m, "No path in the map\n"));
	return (0);
}

int	sl_load_map(char *fn, t_map *m)
{
	int		fd;
	int		error;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (sl_error("Can't open file\n"));
	error = get_rows(fd, m);
	close(fd);
	if (error)
		return (1);
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (sl_error("Can't open file 2\n"));
	error = get_map_info(fd, m);
	close(fd);
	if (error)
		return (1);
	return (0);
}
