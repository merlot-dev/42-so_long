/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:52:26 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/08 12:43:24 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_wall_el(t_game *g, t_mapel *mel)
{
	mel->wl[0] = get_xpm_img(g->x, LWALL);
	mel->wl[1] = get_xpm_img(g->x, RWALL);
	mel->wl[2] = get_xpm_img(g->x, UWALL);
	mel->wl[3] = get_xpm_img(g->x, DWALL);
	if (!mel->wl[0].addr || !mel->wl[1].addr || !mel->wl[2].addr
		|| !mel->wl[3].addr)
		return (1);
	mel->cr[0] = get_xpm_img(g->x, CRNTL);
	mel->cr[1] = get_xpm_img(g->x, CRNTR);
	mel->cr[2] = get_xpm_img(g->x, CRNBR);
	mel->cr[3] = get_xpm_img(g->x, CRNBL);
	if (!mel->cr[0].addr || !mel->cr[1].addr || !mel->cr[2].addr
		|| !mel->cr[3].addr)
		return (1);
	return (0);
}

int	load_elements(t_game *g, t_mapel *mel)
{
	if (load_wall_el(g, mel))
		return (1);
	mel->blinky = get_xpm_img(g->x, BLINKY);
	mel->inky = get_xpm_img(g->x, INKY);
	mel->clyde = get_xpm_img(g->x, CLYDE);
	mel->pinky = get_xpm_img(g->x, PINKY);
	mel->fruits = get_xpm_img(g->x, FRUITS);
	mel->pill = get_xpm_img(g->x, PILL);
	if (!mel->blinky.addr || !mel->inky.addr || !mel->clyde.addr
		|| !mel->pinky.addr || !mel->fruits.addr || !mel->pill.addr)
		return (1);
	mel->pacman = get_xpm_img(g->x, PACMAN);
	if (!mel->pacman.addr)
		return (1);
	mel->black = get_xpm_img(g->x, BLACK);
	if (!mel->black.addr)
		return (1);
	return (0);
}

int	destroy_map_el(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		x_destroy_img(*g, &g->el.wl[i]);
		x_destroy_img(*g, &g->el.cr[i++]);
	}
	x_destroy_img(*g, &g->el.blinky);
	x_destroy_img(*g, &g->el.inky);
	x_destroy_img(*g, &g->el.clyde);
	x_destroy_img(*g, &g->el.pinky);
	x_destroy_img(*g, &g->el.fruits);
	x_destroy_img(*g, &g->el.pill);
	return (1);
}

int	destroy_move_el(t_game *g)
{
	x_destroy_img(*g, &g->el.pacman);
	x_destroy_img(*g, &g->el.black);
	return (1);
}

int	destroy_elements(t_game *g)
{
	destroy_map_el(g);
	destroy_move_el(g);
	return (1);
}
