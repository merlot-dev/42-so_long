/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_tools_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:08:11 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/09 20:09:40 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	x_destroy_img(t_game g, t_img *im)
{
	if (im->addr != NULL)
	{
		mlx_destroy_image(g.x.mlx, im->img);
		im->addr = NULL;
	}
}

int	x_img_to_win(t_game g, t_img *im, int xy[2], int destroy)
{
	mlx_put_image_to_window(g.x.mlx, g.x.win, im->img, xy[0], xy[1]);
	if (destroy)
		x_destroy_img(g, im);
	return (0);
}
