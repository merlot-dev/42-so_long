/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:22:08 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/04 14:48:08 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int draw_pacman(t_game *g, int row, int col)
{
	t_img	pm;
	int		px;
	int		py;

	px = col * g->dim + 2;
	py = row * g->dim + 2;
	pm = get_xpm_img(g->x, PACMAN);
	if (!pm.addr)
		return (1);
   	mlx_put_image_to_window(g->x.mlx, g->x.win, pm.img, px, py);
   	mlx_destroy_image(g->x.mlx, pm.img);
	g->px = col;
	g->py = row;
	return (0);
}

int draw_pill(t_game *g, int row, int col)
{
	t_img	pm;
	int		px;
	int		py;

	px = col * g->dim + 2;
	py = row * g->dim + 2;
	pm = get_xpm_img(g->x, PILL);
	if (!pm.addr)
		return (1);
   	mlx_put_image_to_window(g->x.mlx, g->x.win, pm.img, px, py);
   	mlx_destroy_image(g->x.mlx, pm.img);
	return (0);
}

int draw_exit(t_game *g, int row, int col)
{
	t_img	pm;
	t_img	cpm;
	int		xy[2];
	int		sxy[2];

	xy[0] = 0;
	xy[1] = 0;
	sxy[0] = 36;
	sxy[1] = 23;
	pm = get_xpm_img(g->x, "sprites/pm-fruits.xpm");
	if (!pm.addr)
		return (1);
	cpm = cut_img(g->x, pm, xy, sxy);
	xy[0] = col * g->dim + 4;
	xy[1] = row * g->dim + 10;
   	mlx_put_image_to_window(g->x.mlx, g->x.win, cpm.img, xy[0], xy[1]);
   	mlx_destroy_image(g->x.mlx, pm.img);
   	mlx_destroy_image(g->x.mlx, cpm.img);
	return (0);
}

int	draw_map(t_game *g)
{
	int		i;
	int		j;
	int 	error;

	if (load_elements(g, &g->el))
		return (1);
	if (draw_sidescr(g->x, g->el))
		return (1);
	g->dim = CELLDIM;
	g->mv = 0;
	g->gover = 0;
	g->mi.w = g->m.cols * g->dim;
	g->mi.h = g->m.rows * g->dim;
	g->mi.img = mlx_new_image(g->x.mlx, g->mi.w, g->mi.h);
	g->mi.addr = mlx_get_data_addr(g->mi.img, &g->mi.bpp, &g->mi.ll, &g->mi.end);
	i = 0;
	while (i < g->m.rows)
	{
		j = 0;
		while (j < g->m.cols)
		{
			if (g->m.maps[i][j] == '1')
				error = draw_wall(g, i, j, g->el);
			if (g->m.maps[i][j] == 'C')
				error = draw_coll(g, i, j, g->el);
			if (g->m.maps[i][j] == 'P')
				error = draw_pacman(g, i, j);
			if (g->m.maps[i][j] == 'E')
				error = draw_exit(g, i, j);
			if (g->m.maps[i][j] == '0')
				error = draw_pill(g, i, j);
			if (error)
				return (1);
			j++;
		}
		i++;
	}
	g->mv = 0;
	return (0);
}
