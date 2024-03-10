/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fire_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:16:17 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/10 19:27:40 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw_fire(t_game *g, int n)
{
	t_img				cpm;
	int					xy[2];

	cpm = get_sprite_n(g, g->el.fire, n);
	xy[1] = g->dim + g->dim / 22;
	while (xy[1] < (g->m.rows - 1) * g->dim)
	{
		xy[0] = g->dim + g->dim / 22;
		while (xy[0] < (g->m.cols - 1) * g->dim)
		{
			if (g->m.maps[xy[1] / g->dim][xy[0] / g->dim] == 'F')
				x_img_to_win(*g, &cpm, xy, 0);
			xy[0] += g->dim;
		}
		xy[1] += g->dim;
	}
	x_destroy_img(*g, &cpm);
	return (0);
}
