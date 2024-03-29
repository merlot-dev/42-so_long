/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sidescr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:04:18 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/08 12:33:17 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_sidescr(t_game g)
{
	t_img	im;
	int		xy[2];

	im = get_xpm_img(g.x, TITLE);
	if (!im.addr)
		return (1);
	xy[0] = g.x.winx - SIDEX;
	xy[1] = 0;
	x_img_to_win(g, &im, xy, 1);
	im = get_xpm_img(g.x, "sprites/txt-instruction.xpm");
	if (!im.addr)
		return (1);
	xy[0] = g.x.winx - SIDEX + 10;
	xy[1] = g.x.winy - 70;
	return (x_img_to_win(g, &im, xy, 1));
}

int	draw_gameover(t_game *g)
{
	t_img	im;
	int		xy[2];

	xy[0] = g->x.winx - SIDEX + 50;
	xy[1] = g->x.winy / 2;
	im = get_xpm_img(g->x, GAMEOVER);
	x_img_to_win(*g, &im, xy, 1);
	return (0);
}

int	draw_moves(t_game g, int mvs)
{
	int	xy[2];

	xy[0] = g.x.winx - SIDEX + 80;
	xy[1] = 110;
	ft_printf("MOVES: %6d\n", mvs);
	return (0);
}
