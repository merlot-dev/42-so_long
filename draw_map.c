/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:22:08 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/01 00:34:41 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int draw_sidescr(t_mlx x)
{
    t_img   im;

    im.img = mlx_xpm_file_to_image(x.mlx, TITLE, &im.w, &im.h);
    mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX, 20);
    im.img = mlx_xpm_file_to_image(x.mlx, MOVES, &im.w, &im.h);
    mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 20, 100);
    im.img = mlx_xpm_file_to_image(x.mlx, COLLS, &im.w, &im.h);
    mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 20, 200);
    return (0);
}

int	draw_gameover(t_mlx x)
{
    t_img   im;

    im.img = mlx_xpm_file_to_image(x.mlx, GAMEOVER, &im.w, &im.h);
    mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 50, 600);
	mlx_string_put(x.mlx, x.win, SIDEX + 10, 700, 0xFFFFFF, "<ESC> to exit");
     im.img = mlx_xpm_file_to_image(x.mlx, "sprites/txt-numbers.xpm", &im.w, &im.h);
     mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 50, 500);
	return (0);
}

int draw_wall(t_game *g, int row, int col)
{
	t_img	w[4];
	int		x;
	int		y;

	x = col * g->dim;
	y = row * g->dim;
    w[0].img = mlx_xpm_file_to_image(g->x.mlx, LWALL, &w[0].w, &w[0].h);
    w[1].img = mlx_xpm_file_to_image(g->x.mlx, RWALL, &w[1].w, &w[1].h);
    w[2].img = mlx_xpm_file_to_image(g->x.mlx, UWALL, &w[2].w, &w[2].h);
    w[3].img = mlx_xpm_file_to_image(g->x.mlx, DWALL, &w[3].w, &w[3].h);
	if (!col || g->m.maps[row][col - 1] != '1')
    	mlx_put_image_to_window(g->x.mlx, g->x.win, w[0].img, x, y);
	if (col == (g->m.cols -1) || g->m.maps[row][col + 1] != '1')
     	mlx_put_image_to_window(g->x.mlx, g->x.win, w[1].img, x, y);
	if (!row || g->m.maps[row - 1][col] != '1')
     	mlx_put_image_to_window(g->x.mlx, g->x.win, w[2].img, x, y);
	if (row == (g->m.rows -1) || g->m.maps[row + 1][col] != '1')
     	mlx_put_image_to_window(g->x.mlx, g->x.win, w[3].img, x, y);
	return (0);
}

int draw_coll(t_game *g, int row, int col)
{
	t_img	c[4];
	void	*im;
	int		x;
	int		y;

	x = col * g->dim;
	y = row * g->dim;
    c[0].img = mlx_xpm_file_to_image(g->x.mlx, BLINKY, &c[0].w, &c[0].h);
    c[1].img = mlx_xpm_file_to_image(g->x.mlx, INKY, &c[1].w, &c[1].h);
    c[2].img = mlx_xpm_file_to_image(g->x.mlx, CLYDE, &c[2].w, &c[2].h);
    c[3].img = mlx_xpm_file_to_image(g->x.mlx, PINKY, &c[3].w, &c[3].h);
	im = c[g->sc++ % 4].img;
   	mlx_put_image_to_window(g->x.mlx, g->x.win, im, x, y);
	return (0);
}

int draw_pacman(t_game *g, int row, int col)
{
	t_img	pm;
	int		x;
	int		y;

	x = col * g->dim;
	y = row * g->dim;
    pm.img = mlx_xpm_file_to_image(g->x.mlx, PACMAN, &pm.w, &pm.h);
   	mlx_put_image_to_window(g->x.mlx, g->x.win, pm.img, x, y);
	return (0);
}

int draw_exit(t_game *g, int row, int col)
{
	g->dim += 0;
	row += 0;
	col += 0;
	return (0);
}

int	draw_map(t_game *g)
{
	int	i;
	int	j;

	draw_sidescr(g->x);
	g->dim = CELLDIM;
	g->sc = 0;
	g->mi->w = g->m.cols * g->dim;
	g->mi->h = g->m.rows * g->dim;
	g->mi = mlx_new_image(g->x.mlx, g->mi->w, g->mi->h);
	g->mi->addr = mlx_get_data_addr(g->mi, &g->mi->bpp, &g->mi->ll, &g->mi->end);
	i = 0;
	while (i < g->m.rows)
	{
		j = 0;
		while (j < g->m.cols)
		{
			if (g->m.maps[i][j] == '1')
				draw_wall(g, i, j);
			if (g->m.maps[i][j] == 'C')
				draw_coll(g, i, j);
			if (g->m.maps[i][j] == 'P')
				draw_pacman(g, i, j);
			if (g->m.maps[i][j] == 'E')
				draw_exit(g, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
