/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:36 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/07 16:33:41 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	usage(char **argv)
{
	ft_printf("Usage: %s <fichero.ber>\n", argv[0]);
	return (1);
}

int	check_file_name(char *fn)
{
	char	*ext;

	ext = ft_substr(fn, ft_strlen(fn) - 4, 4);
	if (ft_strcmp(ext, ".ber"))
		return ((int)ft_free(ext) + 1);
	return ((int)ft_free(ext));
}

int	exit_game(int keycode, t_game *g)
{
	keycode += 0;
	g->mv = 0;
	exit(0);
}

// left: 123, right:124, up:126, down:125
// a:0, s:1, w:13, z:6
int	hook_handler(int keycode, t_game *g)
{
	if (keycode == 53)
	{
		destroy_elements(g);
		mlx_destroy_window(g->x.mlx, g->x.win);
		exit_game(keycode, g);
	}
	if (key_moves(keycode, g))
	{
		mlx_destroy_window(g->x.mlx, g->x.win);
		exit_game(keycode, g);
	}
	return (0);
}

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

int	main(int argc, char **argv)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	if (argc != 2 || check_file_name(argv[1]))
		return (usage(argv));
	if (sl_load_map(argv[1], &g.m))
		return (1);
	if (init_map(&g))
		return (1);
	g.x.mlx = mlx_init();
	g.x.win = mlx_new_window(g.x.mlx, g.x.winx, g.x.winy, "PACMAN revenge");
	if (draw_map(&g))
	{
		destroy_elements(&g);
		return (sl_error_free(&g.m, "Check xpm image files\n"));
	}
	mlx_hook(g.x.win, 2, 0, hook_handler, &g);
	mlx_hook(g.x.win, 17, 0, exit_game, &g);
	mlx_loop(g.x.mlx);
}
