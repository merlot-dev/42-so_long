/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:22:08 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/01 17:48:22 by josegar2         ###   ########.fr       */
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
    w[0] = get_xpm_img(g->x, LWALL);
    w[1] = get_xpm_img(g->x, RWALL);
    w[2] = get_xpm_img(g->x, UWALL);
    w[3] = get_xpm_img(g->x, DWALL);
	if (!w[0].addr || !w[1].addr || !w[2].addr || !w[3].addr)
		return (1);
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

	x = col * g->dim + 2;
	y = row * g->dim + 2;
    c[0] = get_xpm_img(g->x, BLINKY);
    c[1] = get_xpm_img(g->x, INKY);
    c[2] = get_xpm_img(g->x, CLYDE);
    c[3] = get_xpm_img(g->x, PINKY);
	if (!c[0].addr || !c[1].addr || !c[2].addr || !c[3].addr)
		return (1);
	im = c[g->sc++ % 4].img;
   	mlx_put_image_to_window(g->x.mlx, g->x.win, im, x, y);
	return (0);
}

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
	return (0);
}

int	draw_map(t_game *g)
{
	int	i;
	int	j;
	int error;

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
				error = draw_wall(g, i, j);
			if (g->m.maps[i][j] == 'C')
				error = draw_coll(g, i, j);
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
	return (0);
}
