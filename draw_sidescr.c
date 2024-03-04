/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sidescr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:04:18 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/04 14:45:07 by josegar2         ###   ########.fr       */
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
	im = get_xpm_img(x, "sprites/txt-keys.xpm");
	if (!im.addr)
		return (1);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 90, 650);
	im = get_xpm_img(x, "sprites/txt-esc2exit.xpm");
	if (!im.addr)
		return (1);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 10, 750);
	return (0);
}

int	draw_gameover(t_mlx x)
{
	t_img   im;

	im = get_xpm_img(x, GAMEOVER);
	mlx_put_image_to_window(x.mlx, x.win, im.img, SIDEX + 50, 500);
	mlx_destroy_image(x.mlx, im.img);
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
		mlx_destroy_image(x.mlx, di.img);
		nbr /= 10;
		dig--;
	}
	return (0);
}
