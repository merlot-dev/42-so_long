/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:48:33 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/08 14:48:44 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_map(t_game *g)
{
	if (g->m.cols > 22 || g->m.rows > 18)
		return (sl_error_free(&g->m, "Map is OK but big to be playable\n"));
	g->dim = CELLDIM;
	g->x.winx = g->dim * g->m.cols + 280;
	g->x.winy = g->dim * g->m.rows;
	if (g->x.winy < 300)
		g->x.winy = 300;
	return (0);
}
