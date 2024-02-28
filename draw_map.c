/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:22:08 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/28 22:59:15 by josegar2         ###   ########.fr       */
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
	return (0);
}

int	draw_map(t_mlx x)
{
	draw_sidescr(x);
	draw_gameover(x);
	return (0);
}
