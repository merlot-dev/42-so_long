/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sidescr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:04:18 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/07 01:01:19 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_sidescr(t_game g, t_mapel el)
{
	t_img	im;
	int		xy[2];

	im = get_xpm_img(g.x, TITLE);
	if (!im.addr)
		return (1);
	xy[0] = SIDEX;
	xy[1] = 20;
	x_img_to_win(g, im, xy, 1);
	im = get_xpm_img(g.x, MOVES);
	if (!im.addr)
		return (1);
	xy[0] = SIDEX + 20;
	xy[1] = 100;
	x_img_to_win(g, im, xy, 1);
	xy[0] = SIDEX + 80;
	xy[1] = 140;
	if (draw_nbr(g, 0, xy, el))
		return (1);
	im = get_xpm_img(g.x, "sprites/txt-instruction.xpm");
	if (!im.addr)
		return (1);
	xy[0] = SIDEX + 10;
	xy[1] = 700;
	return (x_img_to_win(g, im, xy, 1));
}

int	draw_gameover(t_mlx x)
{
	t_img	im;

	im = get_xpm_img(x, GAMEOVER);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 50, 500);
	mlx_destroy_image(x.mlx, im.img);
	return (0);
}

int	draw_nbr(t_game g, int nbr, int xy[2], t_mapel el)
{
	int		dig;
	int		cxy[2];
	int		sxy[2];
	t_img	di;

	sxy[0] = 20;
	sxy[1] = 10;
	cxy[1] = 0;
	dig = 6;
	xy[0] += dig * sxy[0];
	while (dig)
	{
		cxy[0] = (nbr % 10) * sxy[0];
		di = cut_img(g.x, el.nbr, cxy, sxy);
		if (!di.addr)
			return (1);
		x_img_to_win(g, di, xy, 1);
		nbr /= 10;
		dig--;
		xy[0] -= sxy[0];
	}
	return (0);
}

int	draw_moves(t_game g, int mvs)
{
	int	xy[2];

	xy[0] = SIDEX + 80;
	xy[1] = 140;
	return (draw_nbr(g, mvs, xy, g.el));
}
