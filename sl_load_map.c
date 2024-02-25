/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:43:46 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/25 17:11:23 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_rows(fd, t_map *m)
{
	char	*line;

	m->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (m->rows == 0)
			m->cols = ft_strlen(line);
		else if (m->cols != ft_strlen(line))
		{
			line = ft_free(line);
			return (sl_error("Bad map\n"));
		}
		m->rows++;
		line = get_next_line(fd);
	}
	m->cols--;
	return (0);
}

int	sl_load_map(char *fn, t_map *m)
{
	int		fd;
	char	*line;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (sl_error("Can't open file\n"));
}
