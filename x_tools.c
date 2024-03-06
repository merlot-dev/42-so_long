/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:29:17 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/07 00:24:31 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	x_destroy_img(t_game g, t_img im)
{
	mlx_destroy_image(g.x.mlx, im.img);
	im.addr = NULL;
}

void	x_img_to_win(t_game g, t_img im, int xy[2], int destroy)
{
	mlx_put_image_to_window(g.x.mlx, g.x.win, im.img, xy[0], xy[1]);
	if (destroy)
		x_destroy_img(g, im);
}
