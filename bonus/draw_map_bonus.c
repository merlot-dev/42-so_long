/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:01:38 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/08 17:14:51 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw_pacman(t_game *g, int row, int col)
{
	int		px;
	int		py;

	px = col * g->dim + (g->dim / 22);
	py = row * g->dim + (g->dim / 22);
	mlx_put_image_to_window(g->x.mlx, g->x.win, g->el.pacman.img, px, py);
	g->px = col;
	g->py = row;
	return (0);
}

int	draw_pill(t_game *g, int row, int col)
{
	int		px;
	int		py;

	px = col * g->dim + (g->dim / 22);
	py = row * g->dim + (g->dim / 22);
	mlx_put_image_to_window(g->x.mlx, g->x.win, g->el.pill.img, px, py);
	return (0);
}

int	draw_exit(t_game *g, int row, int col)
{
	t_img	cpm;
	int		xy[2];
	int		sxy[2];

	xy[0] = 0;
	xy[1] = 0;
	sxy[0] = 36;
	sxy[1] = 23;
	cpm = cut_img(g->x, g->el.fruits, xy, sxy);
	if (!cpm.addr)
		return (1);
	xy[0] = col * g->dim + 4;
	xy[1] = row * g->dim + 10;
	x_img_to_win(*g, &cpm, xy, 1);
	return (0);
}

int	draw_el(t_game *g, int row, int col)
{
	int	error;

	error = 0;
	if (g->m.maps[row][col] == '1')
		error = draw_wall(g, row, col, g->el);
	if (g->m.maps[row][col] == 'C')
		error = draw_coll(g, row, col, g->el);
	if (g->m.maps[row][col] == 'P')
		error = draw_pacman(g, row, col);
	if (g->m.maps[row][col] == 'E')
		error = draw_exit(g, row, col);
	if (g->m.maps[row][col] == '0')
		error = draw_pill(g, row, col);
	if (error)
		return (error);
	return (0);
}

int	draw_map(t_game *g)
{
	int	i;
	int	j;

	if (load_elements(g, &g->el))
		return (destroy_elements(g));
	if (draw_sidescr(*g, g->el))
		return (destroy_elements(g));
	i = 0;
	while (i < g->m.rows)
	{
		j = 0;
		while (j < g->m.cols)
		{
			if (draw_el(g, i, j++))
				return (destroy_elements(g));
		}
		i++;
	}
	g->mv = 0;
	return (0);
}
