/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sidescr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:04:18 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/03 23:39:52 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int draw_sidescr(t_mlx x, t_mapel el)
{
	t_img   im;
	int		xy[2];

	im = get_xpm_img(x, TITLE);
	if (!im.addr)
		return (1);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX, 20);
	im = get_xpm_img(x, MOVES);
	if (!im.addr)
		return (1);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 20, 100);
	xy[0] = SIDEX + 80;
	xy[1] = 140;
	if (draw_nbr(x, 0, xy, el))
		return (1);
	im = get_xpm_img(x, COLLS);
	if (!im.addr)
		return (1);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 20, 200);
	return (0);
}

int	draw_gameover(t_mlx x)
{
	t_img   im;

	im = get_xpm_img(x, GAMEOVER);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 50, 600);
	mlx_string_put(x.mlx, x.win, SIDEX + 10, 700, 0xFFFFFF, "<ESC> to exit");
	 im.img = mlx_xpm_file_to_image(x.mlx, "sprites/txt-numbers.xpm", &im.w, &im.h);
	 mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 50, 500);
	return (0);
}

int	draw_nbr(t_mlx x, int nbr, int xy[2], t_mapel el)
{
	int		dig;
	int		cxy[2];
	int		sxy[2];
	t_img	di;

	sxy[0] = 20;
	sxy[1] = 10;
	cxy[1] = 0;
	dig = 6;
	while (dig)
	{
		cxy[0] = (nbr % 10) * sxy[0];
		di = cut_img(x, el.nbr, cxy, sxy);
		if (!di.addr)
			return (1);
	 	mlx_put_image_to_window(x.mlx, x.win, di.img, xy[0] + dig * sxy[0], xy[1]);
		nbr /= 10;
		dig--;
	}
	return (0);
}
